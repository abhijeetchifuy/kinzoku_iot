int speedPin=5;
int dir1=4;
int dir2=3;
int BP1=10;
int BP2=9;
int B1Val;
int B2Val;
int mSpeed=0;
int dt=500;
 
void setup() {
  // put your setup code here, to run once:
pinMode(speedPin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(BP1,INPUT);
pinMode(BP2,INPUT);
digitalWrite(BP1, HIGH);
digitalWrite(BP2, HIGH);
Serial.begin(9600);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
B1Val=digitalRead(BP1);
B2Val=digitalRead(BP2);
Serial.print("Motor Speed ");
Serial.println(mSpeed);
 
if (B1Val==0){
  mSpeed=mSpeed-10;
  delay(dt);
}
if (B2Val==0){
  mSpeed=mSpeed+10;
  delay(dt);
}
if (mSpeed>255){
  mSpeed=255;
}
if (mSpeed<-255){
  mSpeed=-255;
}
if (mSpeed==10){
  mSpeed=100;
}
if (mSpeed==-10){
  mSpeed=-100;
}
if (mSpeed == 90 || mSpeed == 95){
  mSpeed=0;
}
if (mSpeed == -90 || mSpeed== -95){
  mSpeed=0;
}
if (mSpeed==0){
  analogWrite(speedPin,0);
}

if(mSpeed == 0){
  analogWrite(speedPin,0);
}

if(mSpeed > 0){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(speedPin,mSpeed);
}
 
 if(mSpeed < 0){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  analogWrite(speedPin,abs(mSpeed));
 }
}