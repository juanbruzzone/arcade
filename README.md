# "Catch the Falling Objects" - Arcade Game Build

## Game Concept

The arcade game, based on Jack and the Beanstalk, was designed to be a classic “catch the falling objects” concept. Golden eggs fall from the clouds down the beanstalks and the user has to control a basket to catch the eggs as they fall. Every egg that passes through the basket adds a point to the player’s tally, and the goal is to catch as many eggs as possible within the 30 second time constraint. We have three manufactured vertical timing belts that rotate throughout the 30 seconds; they have eggs attached to them with magnets on the front. The basket is on a horizontal belt at the bottom of the game, with a hall effect sensor on the side that faces the vertical belts. The basket can move to three set positions in front of each of the bands, sensing the magnet when an egg passes by. At the end of the 30 seconds the basket returns to the middle position and everything stops spinning until the start button is pressed again.

---

## Demo Video

[Watch the arcade game running](PASTE-VIDEO-LINK-HERE)

## CAD Drawing Files

The CAD drawings below show the mechanical design of the arcade game and the custom components used in the final build.

- [CAD Drawing 1](cad/drawing-1.pdf)
- [CAD Drawing 2](cad/drawing-2.pdf)
- [CAD Drawing 3](cad/drawing-3.pdf)
- [CAD Assembly Drawing](cad/assembly-drawing.pdf)

<!-- Optional CAD preview image -->
![CAD Preview](images/cad-preview.png)

---

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

### Electronics and Controls

Write about the electronic components and control system. Explain what inputs the player uses, what outputs the system controls, and how the code interacts with the physical game.

Examples to discuss:
- buttons, joystick, or sensors
- motors or actuators
- wiring
- microcontroller
- timing and reset logic

![Electronics](images/electronics.jpg)

---

### Programming

The game was programmed in C++.

The code controls the logic of the arcade game, including player input, movement timing, system response, and reset behavior. The software had to be reliable because it directly controlled physical components.

Key programming responsibilities included:

- Reading player inputs
- Controlling moving components
- Managing game state
- Timing actions correctly
- Resetting the game after each round
- Debugging hardware/software interaction

[View C++ Code](code/main.cpp)

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

## Skills Demonstrated

- C++ programming
- CAD modeling
- Mechanical design
- Physical prototyping
- Electronics integration
- System troubleshooting
- Iterative design
- Technical documentation# arcade
