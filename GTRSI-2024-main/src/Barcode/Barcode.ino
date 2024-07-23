#include "MeMegaPi.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;

const int barcodeID = 3;

const float Kp_lin = 6.5;
const float Kp_ang = 18;




/*********************************** Setup ************************************/
void center_barcode(int id){
  int x;
  int y;
  float error_x;
  float error_y; 
  float Kp_center_lin = 13;
  float Kp_center_ang = 11;
  Serial.begin(9600);
  Serial2.begin(9600);

  while (true) {
    
      pixy.line.getAllFeatures(); //func: camera info to microcontroller
      
      if(pixy.line.numBarcodes < 1){ //if nothing there keep repeating
        move(0, 0);
        continue;
      }

      x = pixy.line.barcodes[0].m_x;
      y = pixy.line.barcodes[0].m_y; //get location of barcode

      error_x = x - FRAME_WIDTH/2; //dist from point to center
      error_y = y - FRAME_HEIGHT/2;

      float u_lin = Kp_center_lin * error_y; //apply constant
      float u_ang = Kp_center_ang * error_x;
      Serial.println("I see a barcode");
      Serial.println("--------");
      Serial.println(error_x );
      Serial.println(error_y);
      Serial.println("--------");
      move(-u_lin, u_ang);
      
  }
}
float getAngleErr(){
  float x1 = pixy.line.vectors[0].m_x1;
  float ang_err = x1 - FRAME_WIDTH/2; 

  return ang_err;
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
void move(float u_lin, float u_ang){
  
  float uL = clampActuation(u_ang - u_lin);
  float uR = clampActuation(u_ang + u_lin);

  motorR.run(uR);
  motorL.run(uL);
}

void seeLine(){
   pixy.line.getMainFeatures();

    float err_ang = getAngleErr();
    float err_lin = getLinErr();

    float u_ang = Kp_ang * err_ang;
    float u_lin = Kp_lin * err_lin;

    move(u_lin, u_ang);
}

void setup() {
    // put your setup code here, to run once:
  
    Serial.begin(9600);
    Serial2.begin(9600);
    
    pixy.init();
    pixy.setLamp(255, 255);

    Serial.println("Initializing Robot...");
    
   
    
}

/************************************ Loop ************************************/

void loop() {
    // put your main code here, to run repeatedly:

   

    center_barcode(barcodeID);
}
