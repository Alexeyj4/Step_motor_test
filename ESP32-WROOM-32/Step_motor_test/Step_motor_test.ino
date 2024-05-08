/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-stepper-motor-28byj-48-uln2003/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  Based on Stepper Motor Control - one revolution by Tom Igoe
*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  Serial.setTimeout(100000);
  Serial.begin(115200);   
}

void loop() {
  Serial.print("Введите скорость(0-17):");
  String received_string=Serial.readStringUntil('\n');     
  int speed=received_string.toInt();    
  Serial.println(speed);
  myStepper.setSpeed(speed);
  Serial.println("ok");
  
  Serial.print("Введите угол:");
  received_string=Serial.readStringUntil('\n');
  Serial.println(received_string);
  int steps=int(float(stepsPerRevolution)/360*received_string.toInt());       
  //Serial.print("Шаги:");Serial.println(steps);//debug
  myStepper.step(steps);  
  Serial.println("ok");
}
