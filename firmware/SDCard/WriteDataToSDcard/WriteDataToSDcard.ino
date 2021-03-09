#include <SPI.h>
#include <SD.h>

String serData;



File myFile;
char serIn;
int incomingByte = 0; // for incoming serial data

void setup() {
 Serial.begin(9600);
 while (!Serial){
  ;
 }
 
 Serial.println("Arduino is ready");

 Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

 
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0){
    char rec = Serial.read();
    if(rec != '\n'){
      serData += rec;
    }

    if(rec == '\n'){
       myFile = SD.open("test.txt", FILE_WRITE);
    
      // if the file opened okay, write to it:
      if (myFile) {
        Serial.print("Writing to test.txt...");
        myFile.println(serData);
        // close the file:
        myFile.close();
        Serial.println("done.");
      } else {
        // if the file didn't open, print an error:
        Serial.println("error opening test.txt");
      }
      myFile.close();
      Serial.flush();
      serData = "";
    }

    readData();
  }
  delay(10);
}

void readData(){
   myFile = SD.open("test.txt");
  if (myFile) {
    char readData[125] = {0};
    char x;
    int counter = 0;
    // read from the file until there's nothing else in it:
    while (myFile.available())   
    {
      if((x = myFile.read()) != '\n'){
        readData[counter]= x;
        counter++;        
      }         
    }
    Serial.println(readData);
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
