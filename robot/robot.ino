
#include <NewPing.h> //library for ultrasonic sensor
#include <AFMotor.h> // library for motor driver shield 
#include <Servo.h> // library for servo motor

// declaring variables
int distance,pos,linel,liner,linem,backd;
int distancel = 0;
int distancer = 0;
// declaring pins of sensors
#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 400
#define lineirl A3
#define lineirr A2
#define lineirm A4
#define backir A5 

String voice; // for voice control
int Speed = 200;
int turn = 500;
 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo ser;
char command;

void setup (){
  Serial.begin(9600);
  pinMode(lineirl,INPUT);
  pinMode(lineirr,INPUT);
  pinMode(lineirm,INPUT);
pinMode(backir,INPUT);
ser.attach(9); // servo motor is attached in digital pin 9
ser.write(90);
delay(500);

}

void loop (){
   dipin: // jumping statement
   nepal:
  delay(50);
  distance = sonar.ping_cm();

 
  
  if (distance <= 20){
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
  backd = digitalRead(backir);
  if (backd == 1){
    motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  
  delay(turn);}
  else {}
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  }
 backd = digitalRead(backir);
 
  if (backd == 0){
     motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
   delay(50);
  distance = sonar.ping_cm();
  if (distance >= 30){
    motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  
  delay(turn);}
  else {}
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  }

  

  if (Serial.available()>0){
    command = Serial.read();
   delay(50);
  distance = sonar.ping_cm();
  
   if (command == 'F'){ // forward
    if (distance <= 20){
     motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
  backd = digitalRead(backir);
  if (backd == 1){
    motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);}
  else {}
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }
   else {
    motor1.setSpeed(Speed);
motor1.run(FORWARD);
motor2.setSpeed(Speed);
motor2.run(FORWARD);
motor3.setSpeed(Speed);
motor3.run(FORWARD);
motor4.setSpeed(Speed);
motor4.run(FORWARD); 
   }
   }

   if (command == 'L'){ //left
     for (pos = 90; pos <= 180; pos += 2){
ser.write(pos);
delay(15);}

delay(50);
  distance = sonar.ping_cm();
delay(15);
for (pos = 180; pos >= 90; pos -=2){
ser.write(pos);
delay(15);}


if (distance >= 20)
{
  motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
 
}
else {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
   }

   if (command == 'R'){ // right
     for (pos = 90; pos >= 0; pos -= 2){
ser.write(pos);
delay(15);}

delay(50);
  distance = sonar.ping_cm();
  delay(15);

for (pos = 0; pos <= 90; pos +=2){
  ser.write(pos);
  delay(15);  
}

if (distance >= 20)
  {
  motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
 
}
else{
motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
 
}
   }
  
   if (command == 'S'){ // stop
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }

   if (command == 'B'){ //backward
    if (backd == 1){
     motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
   }
   else {
      motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
   delay(50);
  distance = sonar.ping_cm();
  if (distance >= 30){
    motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  delay(turn);}
  else {}
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }
   }
   
   

   while (command == 'A'){ // Object avoiding mode
    delay(50);
distance = sonar.ping_cm();
 if (distance <= 20){
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);

  delay(400);
  motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(300);
  for (pos = 90; pos <= 180; pos += 2){
ser.write(pos);
delay(15);}

delay(50);
  distancel = sonar.ping_cm();
delay(15);
for (pos = 180; pos >= 90; pos -=2){
ser.write(pos);
delay(15);}
delay(300);
 for (pos = 90; pos >= 0; pos -= 2){
ser.write(pos);
delay(15);}
 
delay(50);
  distancer = sonar.ping_cm();
  delay(15);

for (pos = 0; pos <= 90; pos +=2){
  ser.write(pos);
  delay(15);  
}
if (distancel>=distancer){
   motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
else {
   motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
  }
 else if (distance>= 20){
    motor1.setSpeed(Speed);
motor1.run(FORWARD);
motor2.setSpeed(Speed);
motor2.run(FORWARD);
motor3.setSpeed(Speed);
motor3.run(FORWARD);
motor4.setSpeed(Speed);
motor4.run(FORWARD); 
  }
if (Serial.available()>0){
    command = Serial.read();
    if (command == 'S'){
      motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  goto  dipin;
    }
}
  }

  while (command == 'C'){ // Line following mode
      linel = digitalRead(lineirl);
  liner = digitalRead(lineirr);
  linem = digitalRead(lineirm);

delay(50);
distance = sonar.ping_cm();

if ((linel == 0) && (liner == 0) && (linem == 1) ){
  if (distance >= 20){
  motor1.setSpeed(150);
motor1.run(FORWARD);
motor2.setSpeed(150);
motor2.run(FORWARD);
motor3.setSpeed(150);
motor3.run(FORWARD);
motor4.setSpeed(150);
motor4.run(FORWARD); 
}
else {
     motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);

}
}


else if ((linel == 1) && (liner == 0) && (linem == 0)){
 motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
}

else if ((linel == 1) && (linem == 1) && (liner == 0)){
 motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
}
  else if ((linel == 0) && (liner == 1) && (linem == 0)){
    motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  }

else if ((linel == 0) && (linem == 1)&& (liner == 1)){
     motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
}

else if ((linel == 1) && (linem == 1) && (liner == 1)) {
   motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
}




if (Serial.available()>0){
    command = Serial.read();
    if (command == 'S'){
      motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  goto  dipin;
    }
  }
   }

   while (command == 'D'){ // voice control mode

delay(50);
  distance = sonar.ping_cm();

  if (distance <= 20){
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
    motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  }
 backd = digitalRead(backir);
 
  if (backd == 0){
     motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
    motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  }

  if (Serial.available()>0)
        {
          voice="";
  delay(2);
  voice = Serial.readString();
  delay(2);

delay(50);
  distance = sonar.ping_cm();
  
   if (voice == "move forward"){
    if (distance <= 20){
     motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
    motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }
   else {
    motor1.setSpeed(Speed);
motor1.run(FORWARD);
motor2.setSpeed(Speed);
motor2.run(FORWARD);
motor3.setSpeed(Speed);
motor3.run(FORWARD);
motor4.setSpeed(Speed);
motor4.run(FORWARD); 
   }
   }

   if (voice == "turn left"){
     for (pos = 90; pos <= 180; pos += 2){
ser.write(pos);
delay(15);}

delay(50);
  distance = sonar.ping_cm();
delay(15);
for (pos = 180; pos >= 90; pos -=2){
ser.write(pos);
delay(15);}


if (distance >= 20)
{
  motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  delay(turn);
   motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
else {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
   }

   if (voice == "turn right"){
     for (pos = 90; pos >= 0; pos -= 2){
ser.write(pos);
delay(15);}

delay(50);
  distance = sonar.ping_cm();
  delay(15);

for (pos = 0; pos <= 90; pos +=2){
  ser.write(pos);
  delay(15);  
}

if (distance >= 20)
  {
  motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
else{
motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
 
}
   }
  
   if (voice == "stop"){
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }

   if (voice == "backward"){
    if (backd == 1){
     motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
   }
   else {
      motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  delay(500);
    motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
  delay(turn);
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
   }
   }

   if (voice == "exit"){
    motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
  goto nepal;
   }
    
   }
  }
}
}

  
