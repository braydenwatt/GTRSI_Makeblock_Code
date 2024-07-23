#include "MeMegaPi.h"

#include "Homing.h"
#include "Motors.h"


/****************************** Global Variables ******************************/



/*********************************** Setup ************************************/

void setup() {
    home_arm();

    // moving arm up and opening gripper
    motorA.run(100);
    motorG.run(-200);

    delay(3000);

    // stopping motors
    motorA.run(0);
    motorG.run(0);
}


/************************************ Loop ************************************/

void loop() {

}
