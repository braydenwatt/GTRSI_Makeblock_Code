#include "MeMegaPi.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;

const float Kp_lin = 6.5;
const float Kp_ang = 18;



/********************************************************************************************************* Setup ************************************/
void move(float u_lin, float u_ang){
  
  float uL = clampActuation(u_ang - u_lin);
  float uR = clampActuation(u_ang + u_lin);

  motorR.run(uR);
  motorL.run(uL);
}

float getAngleErr(){
  float x1 = pixy.line.vectors[0].m_x1;
  float ang_err = x1 - FRAME_WIDTH/2; 

  return ang_err;
}

void grippie(){
  
  int grips = -1;
  while(grips == -1){
    grips = Serial.read();
    Serial.print(grips);
    delay(5000);
  }
  switch (grips){
    case 1://out
      motorG.run(100);
      delay(1000);
      motorG.run(0);
    case 0:
      motorG.run(-100);
      delay(1000);
      motorG.run(0);
  }
}

float getLinErr(){
  float y1 = pixy.line.vectors[0].m_y1;
  float y0 = pixy.line.vectors[0].m_y0;

  if(y0 < y1){
    y1 = y0;
  }
  float lin_err = y1 - FRAME_HEIGHT;

  return lin_err;
}
void setup() {
    // put your setup code here, to run once:
  
    Serial.begin(9600);
    
    pixy.init();
    pixy.setLamp(255, 255);
    Serial.println("Initializing Robot...");
    delay(5000);
}


/************************************ Loop ************************************/

void loop() {
    // put your main code here, to run repeatedly:
    pixy.line.getMainFeatures();

    float err_ang = getAngleErr();
    float err_lin = getLinErr();

    float u_ang = Kp_ang * err_ang;
    float u_lin = Kp_lin * err_lin;

    move(u_lin, u_ang);
   
    // grippie();

}
