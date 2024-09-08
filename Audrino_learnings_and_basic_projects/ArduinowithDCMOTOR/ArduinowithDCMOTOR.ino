int speedpin=5;
int dir1=4;
int dir2=3;
int mspeed;
int jpin=A1;
int jval;

void setup() {
  // put your setup code here, to run once:
pinMode(speedpin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
Serial.begin(9600);
pinMode(jpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

jval = analogRead(jpin);
Serial.println(jval);

if(jval<514){
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);

  mspeed = (-255./514.) * jval + 255;
  analogWrite(speedpin,mspeed);
}

if(jval>+514){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);

  mspeed = (255./514) * jval - 255;
  analogWrite(speedpin,mspeed);
}

}