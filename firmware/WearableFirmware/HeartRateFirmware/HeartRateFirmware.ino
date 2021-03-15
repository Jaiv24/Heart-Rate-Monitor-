#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// BME280 variables
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;

// Pulse Sensor Variables
// These constants won't change:
const int analogPin = 0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 2000;   // an arbitrary threshold level that's in the range of the analog input

// seven segment varibles
#define A PA0
#define B PA1
#define C PA2
#define D PA3
#define E PA4
#define F PA5
#define G PA6

// sd card variables 
String serData;
File myFile;
char serIn;
int incomingByte = 0; // for incoming serial data

void setup() {
  // segment 8 pin output
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
   while (!Serial){ // time to get serial running 
    ;
   }

 // sd card connection initialization
 Serial.println("Arduino is ready");
 Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");


// BME280 code
 Serial.println(F("BME280 test"));

    unsigned status;
    
    // default settings
    status = bme.begin();  
    // You can also pass in a Wire library object like &Wire2
    // status = bme.begin(0x76, &Wire2)
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
    }
    
    Serial.println("-- Default Test --");
    delayTime = 3000;

    Serial.println();
}

void loop() {

  // BME280 loop code
  printValues();
  delay(delayTime);
  
  // potentimeter code begin 
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);// print the analog value:   
  
  // if the analog value is high enough, turn on the LED:
  if(analogValue > threshold){
    digitalWrite(LED_BUILTIN, LOW); 
    delay(1);  
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1);  
  }

  // sd card code begin
  // read data from the port
    while(Serial.available() > 0){
    char rec = Serial.read();
    if(rec != '\n'){
      serData += rec;
    }
  // open file
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

   //
    readData();
  }

  // seven segment code begin
  delay(10);
  sevenSeg(1,1,1,1,1,1,0);   //   0
  delay(500);

  sevenSeg(0,0,0,1,1,0,0);  //  1
  delay(500);

  sevenSeg(0,1,1,0,1,1,1);  // 2
  delay(500);

  sevenSeg(0,0,1,1,1,1,1); // 3
  delay(500);

  sevenSeg(1,0,0,1,1,0,1); // 4
  delay(500);

  sevenSeg(1,0,1,1,0,1,1); // 5
  delay(500);

  sevenSeg(1,1,1,1,0,1,1);  // 6
  delay(500);

  sevenSeg(0,0,0,1,1,1,0);  // 7
  delay(500);

  sevenSeg(1,1,1,1,1,1,1); // 8
  delay(500);

  sevenSeg(1,0,1,1,1,1,1); // 9
  delay(500);


}
// BME280 print values 
void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

}
// read data from the file on the sd card 
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
// 7 segment function
void sevenSeg (int g, int f, int e, int d, int c, int b, int a)
{
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
  digitalWrite(E, e);
  digitalWrite(F, f);
  digitalWrite(G, g);

}
