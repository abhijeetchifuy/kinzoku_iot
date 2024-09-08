#include <Servo.h>


int lightpin=A4;
int lightval;
int dt=250;
int servopin=9;
Servo myservo;
int angle;

void setup() {
Serial.begin(9600);
pinMode(lightpin,INPUT);
pinMode(servopin,OUTPUT);
myservo.attach(servopin);
}

void loop() {

lightval = analogRead(lightpin);

Serial.print("light val: ");
Serial.println(lightval);
delay(dt);

angle = (-18. /58. ) * lightval + (18. *760. /58. );

if (angle>180){
  angle = 180;
}

if (angle < 0){
  angle = 0;
}

myservo.write(angle);
Serial.print("angle: ");
Serial.println(angle);
}
