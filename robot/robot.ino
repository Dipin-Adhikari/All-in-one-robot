#include <NewPing.h>
#include <AFMotor.h>
#include <Servo.h>

int distance,pos,linel,liner,linem;
int distancel = 0;
int distancer = 0;
String voice;
int Speed = 200;
int turn = 500;
Servo ser;
char command;
#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 400
#define lineirl A3
#define lineirr A2
#define lineirm A4

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  pinMode(lineirl,INPUT);
  pinMode(lineirr,INPUT);
  pinMode(lineirm,INPUT);
  ser.attach(9);
  ser.write(90);
  delay(500);
}

void loop() {
  start:
  delay(50);
  distance = sonar.ping_cm();
  if (distance <= 20){
    Stop();
    delay(500);
    move_backward();
    delay(turn);
    Stop();
  }

  if (Serial.available()>0){
    command = Serial.read();
    printf(command);
    delay(50);
    distance = sonar.ping_cm();
    
    if (command == 'F'){
      if (distance <=20){
        Stop();
      }
      else{
        move_forward();
      }
    }

    if (command == 'L'){
      for (pos = 90; pos<=180; pos +=2){
        ser.write(pos);
        delay(15);
      }
      delay(50);
      distance = sonar.ping_cm();
      delay(15);
      for (pos = 180; pos >= 90; pos -=2){
        ser.write(pos);
        delay(15);
      }
      if (distance >=20){
        turn_left();
      }
      else{
        Stop();
      }
    }

    if (command == 'R'){
      for (pos = 90; pos >= 0; pos -=2){
        ser.write(pos);
        delay(15);
      }
      delay(50);
      distance = sonar.ping_cm();
      delay(15);
      for (pos = 0; pos <= 90; pos +=2){
        ser.write(pos);
        delay(15);
      }
      if (distance >=20){
        turn_right();
      }
      else{
        Stop();
      }
    }

    if (command == 'S'){
      Stop();
    }

    if (command == 'B'){
      move_backward();
    }


    while (command == 'A'){
      delay(50);
      distance = sonar.ping_cm();

      if (distance <= 20){
        Stop();
        delay(200);
        move_backward();
        delay(turn);
        Stop();
        delay(200);
        for (pos = 90; pos <= 180; pos += 2){
          ser.write(pos);
          delay(15);
          }

        delay(50);
        distancel = sonar.ping_cm();

        delay(15);
        for (pos = 180; pos >= 90; pos -=2){
          ser.write(pos);
          delay(15);
          }

        delay(300);
        for (pos = 90; pos >=0; pos -= 2){
          ser.write(pos);
          delay(15);
        }

        delay(50);
        distancer = sonar.ping_cm();
        delay(15);

        for (pos = 0; pos <= 90; pos +=2){
          ser.write(pos);
          delay(15);  
        }

        if (distancel >= distancer){
          turn_left();
          delay(turn);
          Stop();
        }
        else{
          turn_right();
          delay(turn); 
          Stop();
        }
      }
      else{
        move_forward();
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
          goto  start;
        }
      }
    }




  }
}


void Stop (){
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void move_forward (){
  motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
}

void move_backward (){
  motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
}

void turn_left (){
  motor1.setSpeed(Speed);
  motor1.run(BACKWARD);
  motor2.setSpeed(Speed);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor3.run(BACKWARD);
  motor4.setSpeed(Speed);
  motor4.run(FORWARD);
}

void turn_right (){
  motor1.setSpeed(Speed);
  motor1.run(FORWARD);
  motor2.setSpeed(Speed);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor3.run(FORWARD);
  motor4.setSpeed(Speed);
  motor4.run(BACKWARD);
}
