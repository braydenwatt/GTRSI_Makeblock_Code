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
}


/************************************ Loop ************************************/

void loop() {
    // put your main code here, to run repeatedly:
}
