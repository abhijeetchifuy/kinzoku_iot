int b1 = 11;
int b2 = 12;
int ledpin = 3;
int ledbright = 0;
int read1;
int read2;
int buzzpin = 2;
int dt = 500;

void setup() {
  pinMode(b1, INPUT);   
  pinMode(b2, INPUT);   
  pinMode(ledpin, OUTPUT); 
  Serial.begin(9600);
  pinMode(buzzpin, OUTPUT);
}

void loop() {
  read1 = digitalRead(b1);  
  read2 = digitalRead(b2);  
  
  delay(dt); 

  Serial.print("button 1: ");
  Serial.println(read1);
  Serial.print("button 2: ");
  Serial.println(read2);
  
  if (read1 == 1) {
    ledbright += 5;
  }

  if (read2 == 1) {
    ledbright -= 5;
  }

  if (ledbright > 255) {
    ledbright = 255;
    digitalWrite(buzzpin, HIGH);
    delay(dt);
    digitalWrite(buzzpin, LOW);
    Serial.println("buzz high");
  }

  if (ledbright < 0) {
    ledbright = 0;
    digitalWrite(buzzpin, HIGH);
    delay(dt);
    digitalWrite(buzzpin, LOW);
    Serial.println("buzz low");
  }

  Serial.print("the value of analogWrite: ");
  Serial.println(ledbright);
  analogWrite(ledpin, ledbright); 
}
