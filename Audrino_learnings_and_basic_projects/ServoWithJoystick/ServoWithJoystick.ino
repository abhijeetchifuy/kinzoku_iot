#include <Servo.h>
Servo Xservo;
Servo Yservo;
int xpin=A0;
int ypin=A1;
int spin=2;
int xspin=10;
int yspin=11;
int buzzpin=7;
int xval;
int yval;
int Sval;
int WVx;
int WVy;
int dt=200;


void setup() {
Serial.begin(9600);
pinMode(xpin,INPUT);
pinMode(ypin,INPUT);
pinMode(spin,INPUT);
digitalWrite(spin,HIGH);

pinMode(xspin,OUTPUT);
pinMode(yspin,OUTPUT);
Xservo.attach(xspin);
Yservo.attach(yspin);
pinMode(buzzpin,OUTPUT);

}

void loop() {

  xval=analogRead(xpin);
  WVx = (180./1023.)*xval;

  yval=analogRead(ypin);
  WVy = (180./1023.)*yval;

  Sval=digitalRead(spin);
  
  if(Sval == 0){
    digitalWrite(buzzpin,HIGH);
  }
  else {
    digitalWrite(buzzpin,LOW);
  }
  
  Xservo.write(WVx);
  Yservo.write(WVy);

  delay(dt);
  Serial.print("X val : ");
  Serial.print(xval);
  Serial.print(" Y val : ");
  Serial.print(yval);
  Serial.print(" Switch state is ");
  Serial.println(Sval);

}
