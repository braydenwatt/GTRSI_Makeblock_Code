#ifndef HOMING_H
#define HOMING_H

/********************************* Includes ***********************************/

#include <ezButton.h>
#include "motors.h"

/****************************** Global Variables ******************************/

const int limitSwitchPin = 22;
ezButton limitSwitch(limitSwitchPin);


/********************************* Functions  *********************************/

int home_arm(){
    // initializing limit switch
    limitSwitch.setDebounceTime(50);
  
    // lowering arm until limit switch is pressed
    motorA.run(-50);
    while(!limitSwitch.isPressed()) {
        limitSwitch.loop(); // MUST call the loop() function first
    }
  
    // raising arm until limit switch is released
    motorA.run(50);
    while(!limitSwitch.isReleased()) {
        limitSwitch.loop();
    }
  
    // stopping arm
    motorA.run(0);
    Encoder_1.updateCurPos();
    return Encoder_1.getCurPos();
}

#endif // HOMING_H
