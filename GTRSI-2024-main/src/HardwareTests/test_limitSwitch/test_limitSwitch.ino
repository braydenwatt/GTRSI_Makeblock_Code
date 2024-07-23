/* must be downloaded from Arduino library */
#include <ezButton.h>


/****************************** Global Variables ******************************/
const int limitSwitchPin = 22;
ezButton limitSwitch(limitSwitchPin);


/*********************************** Setup ************************************/

void setup() {
    Serial.begin(9600);
    limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
}


/************************************ Loop ************************************/

void loop() {
    /* MUST call the loop() function first */
    limitSwitch.loop();
  
    if(limitSwitch.isPressed())
        Serial.println("The limit switch: UNTOUCHED -> TOUCHED");
  
    if(limitSwitch.isReleased())
        Serial.println("The limit switch: TOUCHED -> UNTOUCHED");
}
