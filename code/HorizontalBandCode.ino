#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Pins ---
const int stepPin = 2; 
const int dirPin = 3; 
const int wakePin = 5;    
const int hallPin = 4;    
const int X_pin = A1;     
const int btnPin = 6;     
const int speakerPin = 8; 

// --- LED Strip ---
const int ledPin = 7;
const int numPixels = 8;
Adafruit_NeoPixel strip(numPixels, ledPin, NEO_GRB + NEO_KHZ800);

// --- Game Variables ---
bool gameActive = false;
unsigned long gameStartTime = 0;
const long gameDuration = 30000;  // ✅ 30 seconds

int score = 0;

// --- Hall sensor control ---
bool magnetLatched = false;
int lastHallState = HIGH;
unsigned long lastScoreTime = 0;
const unsigned long scoreDebounceMs = 250;

// --- Timing variables ---
unsigned long lastStepTime = 0; 
const int noiseIgnoreWindow = 20;

// --- LED flash ---
unsigned long flashEnd = 0;
bool flashing = false;

// --------------------------------------------------
// MOTOR INDEXING SETTINGS
// --------------------------------------------------

const long STEPS_PER_REV = 200;
const float AXLE_DIAMETER_MM = 14.5;
const float POSITION_SPACING_MM = 168.91;
const float AXLE_CIRCUMFERENCE_MM = 3.14159 * AXLE_DIAMETER_MM;

const long STEPS_PER_POSITION = (long)((POSITION_SPACING_MM / AXLE_CIRCUMFERENCE_MM) * STEPS_PER_REV + 0.5);

int currentPosition = 0;
bool joystickReleased = true;

const int stepDelayUs = 900;
// --------------------------------------------------

void setup() {
  pinMode(stepPin, OUTPUT); 
  pinMode(dirPin, OUTPUT);
  pinMode(wakePin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(hallPin, INPUT_PULLUP); 

  digitalWrite(wakePin, LOW); 
  lcd.init();
  lcd.backlight();

  strip.begin();
  strip.clear();
  strip.show();

  showStartScreen();
}

void loop() {
  if (!gameActive && digitalRead(btnPin) == LOW) {
    startGame();
  }

  if (gameActive) {
    handleJoystick(); 
    checkScore();      
    handleLED();
    
    if (millis() % 200 < 20) { 
      updateLCD();
    }
    
    if (millis() - gameStartTime >= gameDuration) {
      endGame();
    }
  }
}

// ---------------- LED ----------------

void handleLED() {
  if (flashing && millis() > flashEnd) {
    flashing = false;
    strip.clear();
    strip.show();
  }
}

void flashGreen() {
  for (int i = 0; i < numPixels; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
  }
  strip.show();
  flashing = true;
  flashEnd = millis() + 200;
}

void setRed() {
  for (int i = 0; i < numPixels; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show();
}

// ---------------- GAME ----------------

void checkScore() {
  unsigned long now = millis();
  int hallState = digitalRead(hallPin);

  // Ignore sensor noise immediately after motor movement
  if (now - lastStepTime < noiseIgnoreWindow) {
    lastHallState = hallState;
    return;
  }

  // Score only on the falling edge: HIGH -> LOW
  if (!magnetLatched &&
      lastHallState == HIGH &&
      hallState == LOW &&
      now - lastScoreTime > scoreDebounceMs) {
    score++;
    magnetLatched = true;
    lastScoreTime = now;
    tone(speakerPin, 1200, 50);
    flashGreen();
  }

  // Rearm only after sensor is fully released
  if (magnetLatched && hallState == HIGH) {
    magnetLatched = false;
  }

  lastHallState = hallState;
}

void startGame() {
  score = 0;
  gameActive = true;
  gameStartTime = millis();
  digitalWrite(wakePin, HIGH); 
  
  currentPosition = 0;
  joystickReleased = true;

  magnetLatched = false;
  lastHallState = digitalRead(hallPin);
  lastScoreTime = 0;

  strip.clear();
  strip.show();
  
  tone(speakerPin, 800, 100);
  delay(100);
  tone(speakerPin, 1200, 200);
  
  lcd.clear();
}

void updateLCD() {
  int timeLeft = (gameDuration - (millis() - gameStartTime)) / 1000;
  if (timeLeft < 0) timeLeft = 0;

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(timeLeft);
  lcd.print("s   ");

  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
  lcd.print("   ");
}

void showStartScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Push Joystick &"); // Modified line
  lcd.setCursor(0, 1);
  lcd.print("Button to Begin"); // Modified line

  strip.clear();
  strip.show();
}

void endGame() {
  moveToCenter();

  gameActive = false;
  digitalWrite(wakePin, LOW); 
  
  tone(speakerPin, 400, 500); 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAME OVER!");
  lcd.setCursor(0, 1);
  lcd.print("Final Score: ");
  lcd.print(score);

  setRed();

  delay(5000); 
  showStartScreen();
}

// ---------------- MOTOR ----------------

void handleJoystick() {
  int joyX = analogRead(X_pin);

  if (joyX >= 450 && joyX <= 550) {
    joystickReleased = true;
    return;
  }

  if (!joystickReleased) return;

  if (joyX < 400) {
    if (currentPosition > -1) {
      moveOnePosition(-1);
      currentPosition--;
    }
    joystickReleased = false;
  } 
  else if (joyX > 600) {
    if (currentPosition < 1) {
      moveOnePosition(1);
      currentPosition++;
    }
    joystickReleased = false;
  }
}

void moveToCenter() {
  while (currentPosition < 0) {
    moveOnePosition(1);
    currentPosition++;
  }
  while (currentPosition > 0) {
    moveOnePosition(-1);
    currentPosition--;
  }
}

void moveOnePosition(int direction) {
  if (direction < 0) {
    digitalWrite(dirPin, HIGH);
  } else {
    digitalWrite(dirPin, LOW);
  }

  for (long i = 0; i < STEPS_PER_POSITION; i++) {
    doStep();
  }

  lastStepTime = millis();
}

void doStep() {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(stepDelayUs); 
  digitalWrite(stepPin, LOW);
  delayMicroseconds(stepDelayUs);
}