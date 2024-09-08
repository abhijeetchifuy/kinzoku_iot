#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

float num1;
float num2;
String op;

float val;

 

void setup() {
lcd.begin(16,2);
Serial.begin(9600);

}

void loop() {
 lcd.setCursor( 0, 0);
 lcd.print("Input 1st number");
 while(Serial.available() == 0){

 }
 num1 = Serial.parseFloat();
 Serial.read();
 lcd.clear();
 
 lcd.setCursor( 0, 0);
 lcd.print("Input 2nd number");
 while(Serial.available() == 0){

 }
 num2 = Serial.parseFloat();
 Serial.read();
 lcd.clear();

 lcd.setCursor( 0, 0);
 lcd.print("Input Operater");
 lcd.setCursor( 0, 1);
 lcd.print("+or*or/or-");

 while(Serial.available() == 0){

 }

 op = Serial.readString();
 op.trim();
 lcd.clear();

 if(op == "+"){
  val = num1+num2;
 }

  if(op == "/"){
  val = num1/num2;
 }

  if(op == "-"){
  val = num1-num2;
 }

  if(op == "*"){
  val = num1*num2;
 }

  lcd.setCursor(0, 0);
  lcd.print(num1,1);
  lcd.print(" ");
  lcd.print(op);
  lcd.print(" ");
  lcd.print(num2,1);
  lcd.print(" = ");
  lcd.setCursor( 0 , 1);
  lcd.print(val);
  delay(4000);
  lcd.print(" Thank You!!");
  delay(1000); 
  lcd.clear();

 


}
