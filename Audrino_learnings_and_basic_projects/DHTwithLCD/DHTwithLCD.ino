#include <LiquidCrystal.h>
#include <DHT.h>
#define type DHT11

int senserpin = 2;
float humiditiy;
float tempC;
float tempF;

int Rs = 7;
int En = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(Rs, En, d4, d5, d6, d7);

DHT dht(senserpin,type);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();

}

void loop() {

  humiditiy = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);


  lcd.setCursor(0,0);
  lcd.print("HUMIDITIY :");
  lcd.setCursor(0,1);
  lcd.print(humiditiy);
  lcd.print(" %");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("TEMP C :");
  lcd.print(tempC);
  lcd.print(" C / ");
  lcd.setCursor(0,1);
  lcd.print("TEMP F :");
  lcd.print(tempF);
  lcd.print(" F");
  delay(2000);
  lcd.clear();




}
