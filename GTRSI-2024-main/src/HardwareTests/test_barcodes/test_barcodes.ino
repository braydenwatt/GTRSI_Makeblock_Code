#include "Pixy2I2C.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;


/*********************************** Setup ************************************/

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);

    /* initializing PixyCam 2.2 */
    pixy.init();
    pixy.setLamp(255, 255);

    Serial.println("Initializing Robot...");
}


/************************************ Loop ************************************/

void loop() {
    /* update PixyCam line follower */
    pixy.line.getAllFeatures();

    /* if no barcode was found, do nothing */ 
    if (!pixy.line.barcodes) {
        return;
    }

    /* printing out the IDs of the barcodes found */
    Serial.print("Found: ");
    for (int i=0; i < pixy.line.numBarcodes; i++) {
        Serial.print(pixy.line.barcodes[i].m_code);
        Serial.print("  ");
    }
    Serial.println("");

    /* makes the output easier to read */
    delay(100);
}
