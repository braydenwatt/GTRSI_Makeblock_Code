#include "MeMegaPi.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;
float arm_offset = 0;
const float Kp_lin = 6.5;
const float Kp_ang = 18;





/*********************************** Setup ************************************/

void setup() {
    // put your setup code here, to run once:
    
    Serial.begin(9600);
    Serial2.begin(9600);

    Serial.println("Initializing Robot...");

    setup_encoder();
    Serial.print("Here");
    
    
    
    closeGrippie(3800);
    delay(1000);
    arm_offset = home_arm();
    delay(1000);
    moveArm(-2000);
    delay(1000);
    openGrippie(3500);
    
    
}
void closeGrippie(int time){
  motorG.run(100);
  delay(time);
  motorG.run(0);
}
void openGrippie(int time){
  motorG.run(-100);
  delay(time);
  motorG.run(0);
  motorA.run(100);
  delay(200);
  motorA.run(-100);
  delay(200);
  motorA.run(0);
}

void moveArm(int desPos){
  //womp womp
  float Kp_arm = 1;
  float u;
  float actual_pos;
  float deadband = 30;
  float error = deadband+1;


  if(desPos > 0){
    Serial.print("Invalid Position");
  }
  while(abs(error)>deadband){

    actual_pos =  get_arm_position()-arm_offset;
    
    error = actual_pos - desPos;
    u= Kp_arm*error;
    motorA.run(u);
  }
  motorA.run(0);
}
/************************************ Loop ************************************/

void loop() {
    // put your main code here, to run repeatedly:
}
