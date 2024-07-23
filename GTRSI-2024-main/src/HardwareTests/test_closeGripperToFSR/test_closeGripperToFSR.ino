#include <MeMegaPi.h>


/****************************** Global Variables ******************************/

MePort portSet(PORT_5);
MeMegaPiDCMotor motorG(PORT4B);

int fsrAnalogPin = A9;  // FSR is connected to analog 0
int fsrReading = 0;     // the analog reading from the FSR resistor divider

float gripperSpeed = 100;


/*********************************** Setup ************************************/

void setup() {
    Serial.begin(9600);
    close_gripper(gripperSpeed);
}

void close_gripper(float spd){
    while (fsrReading < 100) {
        fsrReading = analogRead(fsrAnalogPin);
        motorG.run(spd);
        Serial.println(fsrReading);
    }

    motorG.run(0);
    delay(1000);
    
    /* run the motors for a predetermined amount of time */
    motorG.run(-spd);
    delay(5000);
    
    motorG.run(0);
}


/************************************ Loop ************************************/

void loop() {

}
