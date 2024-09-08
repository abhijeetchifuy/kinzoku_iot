#include<LiquidCrystal.h>
int Rs = 7;
int En = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(Rs,En,d4,d5,d6,d7);

int trigPin = 2;
int echoPin = 3;
float duration;
float distanceCm;
float distanceInches;
int buttonpin = A0;
int buttonval;
int dt = 5000;


void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buttonpin,INPUT); 
  digitalWrite(buttonpin,HIGH);
  Serial.begin(9600);
  lcd.begin(16,2);   
}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Place the Target");
  delay(5000); // Wait for 1 second
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press the Button");

  buttonval = digitalRead(buttonval);

  while(buttonval == 1){
    buttonval = digitalRead(buttonpin); 
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  

  duration = pulseIn(echoPin, HIGH);

  distanceCm = (duration * 0.0343) / 2;
  distanceInches = distanceCm / 2.54; 

  Serial.print("Distance: ");
  Serial.print(distanceInches);
  Serial.println(" inches");


  lcd.setCursor(0, 0);
  lcd.print("DISTANCE TARGET: ");
  lcd.setCursor(0 , 1);
  lcd.print(distanceInches);
  lcd.setCursor(6,1);
  lcd.print("in");
  delay(dt); 

}
