# "Catch the Falling Objects" - Arcade Game Build

## Game Concept

The arcade game, based on Jack and the Beanstalk, was designed to be a classic “catch the falling objects” concept. Golden eggs fall from the clouds down the beanstalks and the user has to control a basket to catch the eggs as they fall. Every egg that passes through the basket adds a point to the player’s tally, and the goal is to catch as many eggs as possible within the 30 second time constraint. We have three manufactured vertical timing belts that rotate throughout the 30 seconds; they have eggs attached to them with magnets on the front. The basket is on a horizontal belt at the bottom of the game, with a hall effect sensor on the side that faces the vertical belts. The basket can move to three set positions in front of each of the bands, sensing the magnet when an egg passes by. At the end of the 30 seconds the basket returns to the middle position and everything stops spinning until the start button is pressed again.

---

## Demo Video
https://github.com/user-attachments/assets/57ea5e9a-5529-44c0-9c8f-fc6eea5776d1


## CAD Drawings - Vertical Band

The CAD drawings below show the mechanical design and custom manufactured components used in the arcade game build.

<p align="center">
  <img src="images/Drawing1CAD.png" width="75%">
  <br>
  <a href="cad/Game_Belt_Orthographic.pdf">PDF Link</a>
</p>

<p align="center">
  <img src="images/Drawing2CAD.png" width="47%">
  <img src="images/Drawing3CAD.png" width="47%">
  <br>
  <a href="cad/Game_Belt_Exploded.pdf">PDF Link</a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="cad/Slotted_Drive_Belt_Orthographic.pdf">PDF Link</a>
</p>

<p align="center">
  <img src="images/Drawing4CAD.png" width="47%">
  <img src="images/Drawing5CAD.png" width="47%">
  <br>
  <a href="cad/Idler_Roller_Orthographic.pdf">PDF Link</a>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <a href="cad/Drive_Sprocket_Orthographic%20(1).pdf">PDF Link</a>
</p>

## Programming/Electronics

The game was programmed in C++.

The code controls the logic of the arcade game, including player input, movement timing, system response, and reset behavior. It is split into two different circuits to deal with varying voltage levels and interference from the motors onto the sensor.

<p align="center">
  <img src="images/wiring1.jpeg" width="47%">
  <img src="images/wiring2.jpeg" width="47%">
</p>

### C++ Code Files

- [Main Arcade Game Code](code/main.cpp)
- [Motor/Sensor Control Code](code/motor-sensor-control.cpp)

## Design Process

### Initial Concept

Write about the original goal of the project here. Explain what kind of arcade game you wanted to build, what the player experience was supposed to be, and what major functions the game needed to perform.

![Initial Sketch](images/initial-sketch.jpg)

---

### Mechanical Design

Write about how you designed the moving physical components. Explain what parts had to move, how they were connected, and why you chose your specific design.

Discuss any important CAD decisions, spacing, alignment, tolerances, or structural concerns.

![Mechanical Design](images/mechanical-design.jpg)

---

### Prototyping and Testing

Write about how the design changed over time. This is where you should show iteration.

Good things to mention:
- what failed at first
- what you had to redesign
- what you tested repeatedly
- how you improved reliability
- how the final version differed from the first idea

![Prototype](images/prototype.jpg)

---

### Final Build

Write about the completed version of the game. Explain what worked well, what you were proud of, and how the final product met the original goal.

![Final Build](images/final-build.jpg)

---

## Bill of Materials

| Item | Quantity | Purpose | Notes |
|---|---:|---|---|
| Microcontroller | 1 | Runs game logic | Arduino / other board |
| Motor | 1 | Controls movement | Replace with exact type |
| Motor driver | 1 | Powers motor | Replace with exact model |
| Buttons / joystick | 1 | Player input | Replace with exact input |
| Wires | Various | Electrical connections |  |
| Frame material | Various | Physical structure | Wood / acrylic / 3D print |
| Fasteners | Various | Assembly | Screws, nuts, bolts |
| Custom CAD parts | Various | Game mechanism | 3D printed / laser cut |
| Power supply | 1 | Powers system | Replace with voltage |
| Miscellaneous materials | Various | Finishing and assembly |  |

---


