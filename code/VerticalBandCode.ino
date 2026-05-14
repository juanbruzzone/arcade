// -------- Button --------
const int buttonPin = 12;

// -------- Motor on PWMA pin 5 --------
const int M1_PWMA = 5;
const int M1_AIN1 = 2;
const int M1_AIN2 = 3;

// -------- Motor on PWMA pin 9 --------
const int M2_PWMA = 9;
const int M2_AIN1 = 10;
const int M2_AIN2 = 11;

// -------- Motor on PWMA pin 6 --------
const int M3_PWMA = 6;
const int M3_AIN1 = 7;
const int M3_AIN2 = 8;

// -------- Settings --------
const int SPEED = 180;
const unsigned long RUN_TIME = 30000; // 30 seconds

bool motorsRunning = false;
bool buttonLatch = false;
unsigned long startTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(M1_PWMA, OUTPUT);
  pinMode(M1_AIN1, OUTPUT);
  pinMode(M1_AIN2, OUTPUT);

  pinMode(M2_PWMA, OUTPUT);
  pinMode(M2_AIN1, OUTPUT);
  pinMode(M2_AIN2, OUTPUT);

  pinMode(M3_PWMA, OUTPUT);
  pinMode(M3_AIN1, OUTPUT);
  pinMode(M3_AIN2, OUTPUT);

  stopMotors();
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    buttonLatch = false;
  }

  if (buttonState == LOW && !motorsRunning && !buttonLatch) {
    motorsRunning = true;
    buttonLatch = true;
    startTime = millis();
    startMotors();
  }

  if (motorsRunning && millis() - startTime >= RUN_TIME) {
    stopMotors();
    motorsRunning = false;
  }
}

void startMotors() {
  // Motor on pin 5
  digitalWrite(M1_AIN1, LOW);
  digitalWrite(M1_AIN2, HIGH);
  analogWrite(M1_PWMA, SPEED);

  // Motor on pin 9
  digitalWrite(M2_AIN1, LOW);
  digitalWrite(M2_AIN2, HIGH);
  analogWrite(M2_PWMA, SPEED);

  // Motor on pin 6 -- flipped
  digitalWrite(M3_AIN1, HIGH);
  digitalWrite(M3_AIN2, LOW);
  analogWrite(M3_PWMA, SPEED);
}

void stopMotors() {
  analogWrite(M1_PWMA, 0);
  analogWrite(M2_PWMA, 0);
  analogWrite(M3_PWMA, 0);
}