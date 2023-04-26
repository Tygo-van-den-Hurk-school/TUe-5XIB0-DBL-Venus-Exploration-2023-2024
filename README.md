# TU/e DBL Venus Exploration

This is the [DBL Venus Exploration website](https://www.es.ele.tue.nl/education/oo2/) into markdown form. This reader contains all the information that the website does. Enjoy. 

## Note's

We are group 17, and have locker 45. Here is a list of links:
-   [Google Drive](https://drive.google.com/drive/folders/1ZX2TFxr7pBkVThMW8cO832ZpsedXFqyV?usp=sharing)
-   [GitHub](https://github.com/St-H123/TUe-DBL-Venus-Exploration/)

## Table of contents

-   [Assignment](#assignment)
-   [Grading](#grading)
-   [Equipment](#equipement)
-   [Software](#software)
    -   [Getting started](#getting-started)
    -   [Programming](#programming-the-robot)
    -   [Hardware components](#hardware-components)
    -   [I/O pins](#io-pin-connections)
-   [Learning Objectives](#learning-objectives)
-   [Support](#support)

## Assignment

During this Design-Based Learning (DBL) exercise you will be working in a team to design and build a system that is used to explore the planet Venus. You will develop robots equipped with sensors and actuators which drive over the surface of the planet. These robots need to cooperate with each other to complete several challenging tasks. In a final competition, the robots of all teams will compete against each other. The team which build the robots that are able to complete all tasks in the least amount of time will be the winner of this competition.

After a long journey through space, your robots will land on the planet Venus. The first location where the robots touchdown will be known as the base camp. From this location, the robots need to start their exploration of the planet. They need to navigate through a maze of steep hills and craters. It should be avoided at all cost that a robot falls into a craters as this will lead to the permanent loss of this robot for the expedition. While exploring the planet, the robots need to find several different rock samples that are hidden somewhere on the planet. Each of these samples needs to be found and brought back to the base camp. At the base camp, the samples need to be assembled and placed into the rock analysis laboratory that is available in the base camp.

![Map](https://www.es.ele.tue.nl/education/oo2/img/map.png)

### Planet

The hills on the planet will be made of a hard material (e.g., cardboard boxes) that reflects ultrasound, but which absorbs most infra-red light. The hills will have a minimal height of 30 cm and it will be impossible to climb these hills with the robots. The cliffs will be marked on the floor surface with black tape. The outer edges of the planet will also be marked with black tape (i.e., the field explored by the robots is surrounded by cliffs at all ends). The rock samples will be squared boxes of approximatly 2x2x2 cm that reflect infra-red light (i.e., they will be covered with white tape). The rock analysis laboratory is a squared container with a width and length of 20 cm and a height of 2.5 cm. The rock samples need to be placed in the container from the top. A ramp (angle less then 30 degrees) will be available on one side to climb to the top of the laboratory.

#### Boundary

![BoundaryImage](https://www.es.ele.tue.nl/education/oo2/img/boundary.png)

#### Cliff

![CliffImage](https://www.es.ele.tue.nl/education/oo2/img/cliff.png)

#### Hill

![HillImage](https://www.es.ele.tue.nl/education/oo2/img/mountain.png)

#### Rock samples

![RockSamplesImage](https://www.es.ele.tue.nl/education/oo2/img/rock_new.png)

#### Lab

![LabImage](https://www.es.ele.tue.nl/education/oo2/img/lab.png)

Note that these pictures are just illustrations. The actual objects might be different. They do however comply to the specification listed above.

## Grading

The project will be graded based on an interim design report, a final presentation, and a final report.

-   Design report (week 3) - 15% of the final result
-   Presentation (week 8) - 15% of the final result
-   Final report (week 8) - 70% of the final result

### Design report

The design report must be submitted through [Canvas](https://canvas.tue.nl/courses/22820) before 11:59 pm on May 12th, 2023. The report (max 10 pages A4 single column including title page and table of content) should contain the following elements:

-   Problem statement that highlights the key challenges that need to be addressed in this design project.
-   Discussion on the system-level design of the system including a discussion on the trade-offs that have been made for each component in the system? I.e., the system level description of the system should consider multiple different scenarios including possible fault situations.
-   Concise description on the working of each component in the system including a clear definition of the interfaces of each component. I.e., after reading the discussion on the components the reader should be able to assess whether all components can successfully be interconnected.
-   A test plan that defines tests (and expected outcomes) for testing the components as well as a series of tests that define how the component integration is tested. Note that the test plan does not have to define the time at which the tests are executed (planning).
-   A detailed project planning. I.e., a reasonable amount of time should be assigned for the development and testing of each individual component, sufficient time should also be available for the integration. Furthermore, realistic milestones should be defined along the project timeline to monitor progress and to define actions in case deadlines are missed. The plan should also include the task assignment between members of the team, and discussion about sub-teams if there are any.

### Presentation

At the end of the project, a video presentation (8-10 minutes) must be submitted through [Canvas](https://canvas.tue.nl/courses/22820) before 11:59 pm on June 25th, 2023. The video should demonstrate your design in action and explain the design concept and motivate your teams main design decisions.

### Final report

At the end of the project, the final report must be submitted through [Canvas](https://canvas.tue.nl/courses/22820) before 11:59 pm on June 25th, 2023. The final report consists of two parts. Part 1 (max 15 pages A4 single column including title page and table of content) should contain the following elements:

Problem statement that highlights the key challenges that need to be addressed in this design project.
Discussion on the system-level design of the system including a discussion on the trade-offs that have been made for each component in the system. I.e., the system level description of the system should consider multiple different scenarios including possible fault situations.
Concise description on the working of each component in the system including a clear definition of the interfaces of each component. I.e., after reading the discussion on the components the reader should be able to build the components him/herself and understand the main points of the design of the components.

Discussion on the tests performed to verify the correct operation of the individual components. I.e., the set of performed tests should cover all possible conditions including possible fault situations. For each test the discussion should include the following: (1) description of the test setup, (2) expected outcomes, (3) obtained results, (4) reflection on obtained results.
A conclusion that summarizes the main results achieved in the project. I.e., the conclusion should explain under which conditions the system is working. If the system is not working properly, it should be explained what needs to be done in order to arrive at a working system.
Part 2 (maximal 2 pages A4 single column per team member) should be submitted by each student individually and should reflect the following aspects/questions:

Technical contribution. What is your technical contribution to the system?
Design process. What did I learn about the design process? (Do not only mention technical aspects, but also discuss your experience with working in a team on the design.)

Planning and project management. How well did you manage to keep your planning? How did you keep others informed on your progress?
Learning outcomes. What did you learn from the project? About yourself? About working in the field?
Reflection towards the future. What are your lessons for the future? What was successful? Why? What would you do differently in a future project? Why?

### Professional Skills

During this project you may complete the PRVs (professional skills) related to presentations and cooperation (both level 1). These PRVs will be assessed by the project leaders who will also provide feedback to you.

## Equipement

Each team will receive the following equipment:

-   robots (2x)
-   USB cables (2x)
-   ACDC 7,5V power supplies (2x)
-   AA rechargeable batteries (10x)
-   battery charger (2x)

The robots are based on [the Robotics Shield Kit](https://www.parallax.com/product/robotics-shield-kit-for-arduino/) which are equipped with an Arduino Uno micro-controller. The robots have several sensors and actuators:

-   [Ultrasound distance sensor](http://www.parallax.com/product/28015)
-   [Digital encoders on both wheels](https://www.parallax.com/product/sharp-gp2a25j0000f-close-range-reflective-sensor-4-pack-kit/)
-   [Gripper kit](https://www1.parallax.com/product/28202)
-   [ZigBee wireless communication module](https://hub.digi.com/support/products/digi-xbee/digi-xbee-s1/)

Teams may add additional sensors and actuators to the robots. These sensors and actuators may be connected to the robot using the breadboard that is available on the robots. It is strictly forbidden to solder any electronics to the robots. Furthermore, it must be possible to remove all mechanical additions made by a team to a robot without damaging the robots. At the end of the project, teams must return the robots (and all other equipment given to them) in exactly the same state as they received it at the start of the project.

![RobotFrond](https://www.es.ele.tue.nl/education/oo2/img/robot-2.png) ![RobotSide](https://www.es.ele.tue.nl/education/oo2/img/robot-1.png)

## Software

### Getting started

The robots are based on the Robotics Shield Kit which is equipped with an Arduino Uno micro-controller. To program this micro-controller you need to install some software on your laptop. Step-by-step instructions for setting up the Arduino software and connecting it to an Arduino Uno:

-   [Windows](http://arduino.cc/en/Guide/Windows)
-   [Mac OS X](http://arduino.cc/en/Guide/MacOSX)
-   [Linux](http://arduino.cc/en/Guide/Linux)

More information on the Arduino and all hardware components on the robots can be found at the [Arduino website](http://arduino.cc/en/Guide/HomePage). The [robotics Shield Kit website](http://learn.parallax.com/ShieldRobot) from parallax offers another useful introduction into programming the robot.

### Programming the robot

The Wireless SD shield has an on-board switch labelled Serial Select. It determines how the Xbee's serial communication connects to the serial communication between the microcontroller and USB-to-serial chip on the Arduino board.

Put the switch in the Micro position when using the ZigBee communication and put it in the USB position when programming the Arduino.

When in the Micro position, the DOUT pin of the wireless module is connected to the RX pin of the microcontroller; and DIN is connected to TX. The wireless module will then communicate with the microcontroller. Note that the RX and TX pins of the microcontroller are still connected to the TX and RX pins (respectively) of the USB-to-serial converter. Data sent from the microcontroller will be transmitted to the computer via USB as well as being sent wirelessly by the wireless module. The microcontroller will not be programmable via USB in this mode.

With the switch in the USB position, the DOUT pin the wireless module is connected to the RX pin of the USB-to-serial converter, and DIN on the wireless module is connected to the TX pin of the USB-to-serial converter. This means that the module can communicate directly with the computer. The microcontroller on the board will be bypassed. To use the shield in this mode, you must program the microcontroller with an empty sketch (shown below), or remove it from the board.

### Hardware components

Detailed information on how to use the various components on the robot can also be found on the Arduino website. And please see the [hardware section](#hardware-components) for more information.

### I/O pin connections

| Pin        | PWM | CurrentConnection |
| ---------- | --- | ----------------- |
| Digital 0  | no  | RX ZigBee module  |
| Digital 1  | no  | TX ZigBee module  |
| Digital 2  | no  | -                 |
| Digital 3  | yes | -                 |
| Digital 4  | no  | -                 |
| Digital 5  | yes | -                 |
| Digital 6  | yes | -                 |
| Digital 7  | no  | left encoder      |
| Digital 8  | no  | right encoder     |
| Digital 9  | yes | ultrasound sensor |
| Digital 10 | yes | grabber servo     |
| Digital 11 | yes | ultrasound servo  |
| Digital 12 | no  | left servo        |
| Digital 13 | no  | right servo       |
| Analog 0   | -   | -                 |
| Analog 1   | -   | -                 |
| Analog 2   | -   | -                 |
| Analog 3   | -   | -                 |
| Analog 4   | -   | -                 |
| Analog 5   | -   | -                 |

## Learning Objectives

By the time the students finish this design project, they should be able to:

-   design and implement a complex system;
-   organize the design process by decomposing the design problem into a set of smaller design problems;
-   design and implement a robust wireless communication protocol;
-   select and implement distributed control algorithms that run on a set of autonomous robots;
-   integrate new sensors and actuators in an existing control system;
-   report on the system design and its individual components.

## Support

You may contact the student assistant for possible problems with robots or the other hardware components. TAs will be present at Flux 8.096 on Wednesday 15:00-17:00 and Fridays 10:00-12:00. Here is the list of TAs:

-   Panteleimon Katsis (p.katsis@student.tue.nl)
-   Georgios Stekas (g.stekas@student.tue.nl)
-   Andreas Papaevripidis (a.papaevripidis@student.tue.nl)
-   Pavle Varinac (p.varinac@student.tue.nl)

For any issue related to OGO rooms or the lockers, contact dr. Majid Nabi (m.nabi@tue.nl)
