// These constants won't change:
const int analogPin = 0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 2000;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
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
}
