#define A PA0
#define B PA1
#define C PA2
#define D PA3
#define E PA4
#define F PA5
#define G PA6
String a0 = "1";
String a = "2";
String b = "3";
String c = "4";
String d = "5";
String aa = "6";
String bb = "7";
String cc = "8";
String dd = "9";

void setup() {
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);


}

void loop() {
  if(Serial.available()){ // only send data back if data has been sent
      sevenSeg(1, 1, 1, 0, 0, 1, 0); // C
      delay(500);
      sevenSeg(0, 1, 1, 1, 0, 0, 1); // o
      delay(500);
      sevenSeg(0, 1, 0, 1, 0, 0, 1); // n
      delay(500);
      sevenSeg(0, 1, 0, 1, 0, 0, 1); // n
      delay(500);
      sevenSeg(1, 1, 1, 0, 0, 1, 1); // E
      delay(500);
      sevenSeg(1, 1, 1, 0, 0, 1, 0); // c
      delay(500);
      sevenSeg(1, 1, 1, 0, 0, 0, 1); // t
      delay(500);
      sevenSeg(1, 1, 1, 0, 0, 1, 1); // E
      delay(500);
      sevenSeg(0, 1, 1, 1, 1, 0, 1); // d
      delay(500);
    }else{
      sevenSeg(0, 0, 0, 0, 0, 0, 1); //  1
      delay(500);
    }

  }
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
