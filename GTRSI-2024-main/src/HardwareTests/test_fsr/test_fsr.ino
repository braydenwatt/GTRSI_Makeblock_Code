/****************************** Global Variables ******************************/

const int fsrPin = 9;
int fsrReading;


/*********************************** Setup ************************************/

void setup(void) {
  Serial.begin(9600);   
}


/************************************ Loop ************************************/

void loop(void) {
    fsrReading = analogRead(fsrPin);  
   
    Serial.print("Analog reading = ");
    Serial.print(fsrReading);
   
    /* we'll have a few threshholds, qualitatively determined */
    if (fsrReading < 10) {
        Serial.println(" - No pressure");
    } else if (fsrReading < 200) {
        Serial.println(" - Light touch");
    } else if (fsrReading < 500) {
        Serial.println(" - Light squeeze");
    } else if (fsrReading < 800) {
        Serial.println(" - Medium squeeze");
    } else {
        Serial.println(" - Big squeeze");
    }

  /* makes the output easier to read */
  delay(1000);
} 
