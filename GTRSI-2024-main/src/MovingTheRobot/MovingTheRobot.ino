#include "MeMegaPi.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;


/*********************************** Setup ************************************/

void setup() {
    // put your setup code here, to run once:
  
    Serial.begin(9600);
    Serial2.begin(9600);

    Serial.println("Initializing Robot...");

    
    grippies(-50);
    delay(4000);
    grippies(0);
}
void moveMotor(float rightMotor, float leftMotor){
  motorR.run(rightMotor);
  motorL.run(leftMotor);
}

void rotateMotor(float a){
  float max = clampActuation(a);
  motorR.run(max);
  motorL.run(max);
}
void grippies(float e){
  float u = e * 1;
  motorG.run(u);
}
void move(float u_lin, float u_ang){
  //run motor
  //ulin linear movement
  //uang angular movement

  float uL = clampActuation(u_ang - u_lin);
  float uR = clampActuation(u_ang + u_lin);


  // moveMotor(150)
  // delay(3000); //gives timer in millisec
  // moveMotor(0);
  moveMotor(uR, uL);
  //rotateMotor(150);
  delay(3000);
  moveMotor(0,0);
}

/************************************ Loop ************************************/

void loop() {
    // put your main code here, to run repeatedly:
}
