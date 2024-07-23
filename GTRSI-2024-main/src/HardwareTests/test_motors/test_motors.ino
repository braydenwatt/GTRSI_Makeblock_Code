#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/


/*********************************** Setup ************************************/

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);

    Serial.println("Initializing Robot...");

    /* move forward for 3 seconds and stop */
    move(100, 0);
    delay(3000);
    move(0, 0);
}

void move(float u_lin, float u_ang) 
{
    /* making sure we don't exceed the maximum left and right motor speeds */
    float uL = clampActuation(u_ang - u_lin);
    float uR = clampActuation(u_ang + u_lin);

    /* running the motors */
    motorR.run(uR);
    motorL.run(uL);
}


/************************************ Loop ************************************/

void loop() {
}
