
#define A PA0
#define B PA1
#define C PA2
#define D PA3
#define E PA4
#define F PA5
#define G PA6


void setup() {

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);


}

void loop() {
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