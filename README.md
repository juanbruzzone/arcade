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
  <img src="images/wiring1.jpeg" width="35%">
  <img src="images/wiring2.jpeg" width="35%">
</p>

### Arduino Code Files

- [Main Game Code](code/HorizontalBandCode.ino)
- [Sensor/Motor Circuit Code](code/VerticalBandCode.ino)

## Design Process

### Initial Concept

- Designed a custom “catch the falling objects” arcade game inspired by *Jack and the Beanstalk*, combining physical gameplay with embedded programming and mechanical motion.
- Developed a 30-second player experience in which golden eggs moved down vertical bands while the player controlled a basket across three fixed positions.
- Integrated multiple subsystems from the start: C++ game logic, motors, timing belts, magnets, hall effect sensing, player input, and physical scoring logic.
- Built the concept around precision: the basket had to align with magnetic eggs in real time for the sensor to register successful catches.

---

### Mechanical Design

- Engineered four belt-driven systems to operate together: three vertical bands for the falling eggs and one horizontal belt for basket movement.
- Designed and manufactured key custom components, including vertical bands, sprockets, supports, and alignment structures.
- Used CAD modeling to plan spacing, part geometry, assembly fit, and movement paths before fabrication.
- Improved serviceability by leaving the top structure removable, allowing quick access to internal mechanisms during testing and repair.
- Solved wire-interference issues by adding slack to the hall effect sensor wiring and routing it around the moving systems with dowel supports.

https://github.com/user-attachments/assets/63af64f7-019d-4e8d-bfbd-29849f61da64

---

### Prototyping and Testing

- Iterated heavily as the design moved from concept to physical build, using testing to identify issues that were not visible on paper.
- Refined the custom vertical bands after early versions introduced minor wobble during rotation, improving alignment and sensor reliability.
- Adjusted spacing, support structures, and magnet placement to make the hall effect sensor more consistent during gameplay.
- Solved electrical interference from the motors by separating the system into two circuits while keeping both synchronized under the same timing structure.
- Simplified the original design from five vertical belts to three, improving reliability, spacing, and overall manufacturability.
- Shifted from 3D eggs and basket components to flatter 2D designs to reduce physical interference and create smoother gameplay.

<p align="center">
  <img src="images/Prototype1.jpeg" width="47%">
  <img src="images/Prototype2.JPG" width="47%">
</p>

---

### Final Build

<table>
  <tr>
    <td width="38%" valign="top">
      <img src="images/FinalBuild2.jpeg" width="100%">
    </td>
    <td width="62%" valign="top">
      <ul>
        <li>Built a complete arcade game that combined mechanical motion, electronics, programming, and physical fabrication into one functioning interactive system.</li>
        <li>Programmed a timed 30-second gameplay cycle in which players moved the basket between three positions to catch magnetic eggs traveling down the vertical bands.</li>
        <li>Integrated multiple motors, sensors, custom-manufactured components, and C++ control logic into a coordinated system.</li>
        <li>Created a precise horizontal basket movement system that allowed the sensor to reach accurate catching positions during gameplay.</li>
        <li>Overcame mechanical alignment, wiring, voltage, and interference challenges through repeated testing, redesign, and troubleshooting.</li>
        <li>Completed a hands-on engineering build that strengthened skills in CAD modeling, fabrication, electronics, Arduino/C++ programming, prototyping, and system-level problem solving.</li>
      </ul>
    </td>
  </tr>
</table>

## Bill of Materials

| Item | Source | Unit Cost | Quantity | Total Cost |
|---|---|---:|---:|---:|
| Particle wood board | Home Depot | $8.52 | Around ⅔ | $6 |
| 1x1 inch by 14ft wooden plank | Home Depot | $2 per foot | 6 ft | $12 |
| Acxico mini micro gear motor | Amazon | $3 | 3 | $10 |
| DIANN dual DC stepper motor | Amazon | $2.70 | 3 | $8 |
| 12v Power Supply | Amazon | $9 | 1 | $9 |
| 5050 RGB LED | Amazon | $6 | 1 | $6 |
| GT2 Timing Belt | Amazon | $0.61 per foot | 6 ft | $3.66 |
| MAKERELE nema stepper motor | Amazon | $10 | 1 | $10 |
| Hall effect sensor | Amazon | $0.40 | 1 | $0.40 |
| Button | Amazon | $4 | 1 | $4 |
| Canvas drop cloth | Amazon | $15 | Around ⅓ | $5 |
| Magnets | Arduino Kit | - | 20 | - |
| Arduino | Arduino Kit | - | 2 | - |
| Breadboard | Arduino Kit | - | 2 | - |
| LCD Display | Arduino Kit | - | 1 | - |
| Basic speaker | Arduino Kit | - | 1 | - |
| Joystick | Arduino Kit | - | 1 | - |
| Paper (Golden Eggs) | Lab | - | - | - |
| Sprocket axles | 3D print (lab) | - | 6 | - |
| Sprocket Pegs | 3D Print (lab) | - | 9 | - |
| ¼ inch dowels | Lab | - | 7 | - |
| 9V power adapter | Lab | - | 3 | - |
| Paint | Lab | - | - | - |
| Hot glue | Lab | - | - | - |
| Wire | Lab | - | - | - |
| 1.5” nails | Lab | - | - | - |

### Total Cost: $74.06
