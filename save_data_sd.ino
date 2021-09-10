

// include the SD library:
#include <SPI.h>
#include <mySD.h>
int x =0;
// set up variables using the SD utility library functions:


File root;

// change this to match your SD shield or module;
// Default SPI on Uno and Nano: pin 10
// Arduino Ethernet shield: pin 4
// Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// MKRZero SD: SDCARD_SS_PIN
//define pins of SD card slot
#define SD_CS    32
#define SD_MOSI  14 // no libre
#define SD_MISO  17 // no libre
#define SD_SCK   16 // no libre


void setup() {

  // Open serial communications and wait for port to open:

  Serial.begin(115200);

 

  Serial.println("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries

  // since we're just testing if the card is working!
  //SD.begin(SD_CS, SD_MOSI, SD_MISO, SD_SCK);
    
}

void loop(void) {

  SD.begin(SD_CS, SD_MOSI, SD_MISO, SD_SCK);
    x++;
   root = SD.open("/datos.txt", FILE_WRITE); //open file
  if(root){
  root.println(x); //write count x
  root.flush();
  root.close(); //close file
  Serial.println("Recorded");
  SD.end();
 
}else{
  Serial.println("Doesn't work");
}
  
 delay(3000);
}
