int greenpin = 9;
int bluepin = 10;
int redpin = 6;
String mycolour;

void setup() {
  Serial.begin(9600);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
}

void loop() {
  Serial.println("Choose a color option:");
  Serial.println("1. red");
  Serial.println("2. blue");
  Serial.println("3. green");
  Serial.println("4. cyan");
  Serial.println("5. magenta");
  Serial.println("6. yellow");
  Serial.println("7. orange");
  Serial.println("8. white");
  Serial.println("9. off");

  while (Serial.available() == 0) {}

  mycolour = Serial.readString();
  mycolour.trim();

  if (mycolour == "1" || mycolour == "red") {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 0);
  }
  
  if (mycolour == "2" || mycolour == "blue") {
    analogWrite(redpin, 0);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 255);
  }
  
  if (mycolour == "3" || mycolour == "green") {
    analogWrite(redpin, 0);
    analogWrite(greenpin, 255);
    analogWrite(bluepin, 0);
  }
  
  if (mycolour == "4" || mycolour == "cyan") {
    analogWrite(redpin, 0);
    analogWrite(greenpin, 255);
    analogWrite(bluepin, 255);
  }
  
  if (mycolour == "5" || mycolour == "magenta") {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 255);
  }
  
  if (mycolour == "6" || mycolour == "yellow") {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 255);
    analogWrite(bluepin, 0);
  }
  
  if (mycolour == "7" || mycolour == "orange") {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 128);
    analogWrite(bluepin, 0);
  }
  
  if (mycolour == "8" || mycolour == "white") {
    analogWrite(redpin, 255);
    analogWrite(greenpin, 255);
    analogWrite(bluepin, 255);
  }
  
  if (mycolour == "9" || mycolour == "off") {
    analogWrite(redpin, 0);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 0);
  }
  
  if (mycolour != "1" && mycolour != "2" && mycolour != "3" && mycolour != "4" &&
      mycolour != "5" && mycolour != "6" && mycolour != "7" && mycolour != "8" &&
      mycolour != "9" && mycolour != "red" && mycolour != "blue" && mycolour != "green" &&
      mycolour != "cyan" && mycolour != "magenta" && mycolour != "yellow" && mycolour != "orange" && mycolour != "white" && mycolour != "off") {
    Serial.println("Invalid option. Please enter a valid option number or color name.");
  }
  
  while (Serial.available() > 0) {
    Serial.read();
  }
}
