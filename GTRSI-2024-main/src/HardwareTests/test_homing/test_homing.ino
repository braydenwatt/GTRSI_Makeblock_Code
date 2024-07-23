#include "MeMegaPi.h"
#include <SoftwareSerial.h>

#include "homing.h"


/****************************** Global Variables ******************************/

int arm_offset = 0;


/*********************************** Setup ************************************/

void setup() {
  Serial.begin(9600);

  /* zeroing encoder */
  setup_encoder();
  arm_offset = home_arm();
  
  Serial.println(arm_offset);
}

/************************************ Loop ************************************/

void loop() {
  
}
