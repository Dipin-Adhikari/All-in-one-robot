# All-In-One Robot
## Introduction
All-In-One Robot is a multipurpose robot that can be controlled in four different modes:
- Bluetooth Controlled Mode
- Voice Controlled Mode
- Line Following Mode
- Obstacle Avoiding Mode

When the robot is powered on, the first thing the robot does is try to get commands through the HC-05 Bluetooth module. Bluetooth-controlled mode is the default mode. The command is given in character form (char) by our robot app except in voice-controlled mode. When our robot gets a command it sees whether something related to that command is written in code or not. If that is written, it will follow the respective task. The examples of command are:
- Forward: “F”,
- Backward: “B”,
- Line following mode: “C”, etc.

While following the task related to command, it interacts with an ultrasonic sensor to avoid obstacles.
## Bluetooth Controlled Mode
In this mode, we need to provide commands from the Robot app. To move the robot forward we need to click the forward arrow button and by pressing the respective arrow buttons, the robot moves. This robot is more sophisticated than others as it can sense distance from the front with the help of an ultrasonic sensor. When we give a command to the robot to turn left, the robot first sees whether something is present on the left or not i.e. to avoid obstacles, and if nothing is present only the robot turns left otherwise it will remain in its position and right also there is the same process. For turning Ultrasonic Sensor, it uses a Servo Motor.
## Voice Controlled Mode
For controlling the robot in this mode, we need to just press the Voice Controlled Mode. And after that, we need to click the mic button and speak what we want and the robot will act according to its algorithm(code). It uses Google's Voice Recognition API.
## Obstacle Avoiding Mode
In this mode, the robot moves by itself without getting a command from the app. To activate this mode we need to click the Object Avoiding Mode button. And the robot moves completely by itself without colliding with the obstacles. For this mode, the robot takes data(distance) from the ultrasonic and IR sensor. When the Object Avoiding Mode is clicked then the robot starts to move in a straight path until any obstacle is in the path. When any obstacle is felt by the robot through an ultrasonic sensor, then the robot turns the ultrasonic sensor in both the left and right direction and calculates the distance of both the left and right paths. After calculating the distance, it compares and turns where there is no obstacle.
## Line Following Mode
In this mode robot sense the line by three IR sensor located at front. When command is given to the robot, it activate the 3 IR sensors and this sensors continuously transmits IR rays. We know reflection of light is lesser in darker objects as they absorbs the light. So when robot is align in its path, the middle IR sensor receives less IR rays. 
