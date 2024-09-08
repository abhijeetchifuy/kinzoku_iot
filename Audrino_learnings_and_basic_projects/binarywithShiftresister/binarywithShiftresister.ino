int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=200;
 
byte LEDs=0B00000000;

 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
} 
 
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,MSBFIRST,LEDs);
digitalWrite(latchPin,HIGH);

delay(dt);

LEDs = LEDs + 1;

Serial.println(LEDs,BIN);

}