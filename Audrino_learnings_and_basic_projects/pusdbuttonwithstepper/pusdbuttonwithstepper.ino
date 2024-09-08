#include <Stepper.h>

int stepsPerRevolution = 2048;
int motspeed = 10; 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int dt = 500;

int buttonpin = 2;
int buttonvalnew;
int buttonvalold = 1;
int motdir = 1;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motspeed);
  pinMode(buttonpin, INPUT);
  digitalWrite(buttonpin, HIGH);
}

void loop() {
  buttonvalnew = digitalRead(buttonpin);
  
  if (buttonvalold == 1 && buttonvalnew == 0) {
    motdir = motdir * (-1); 
  }

  buttonvalold = buttonvalnew;
  myStepper.step(motdir * 1);
}
