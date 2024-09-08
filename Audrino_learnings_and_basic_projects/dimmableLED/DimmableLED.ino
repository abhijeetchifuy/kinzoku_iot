int b1 = 11;
int b2 = 12;
int ledpin = 3;
int ledbright = 0;

void setup() {
  pinMode(b1, INPUT);   
  pinMode(b2, INPUT);   
  pinMode(ledpin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int read1 = digitalRead(b1);  
  int read2 = digitalRead(b2);  

  Serial.print("button 1: ");
  Serial.println(read1);
  Serial.print("button 2: ");
  Serial.println(read2);
  
  delay(100); 
  
  if(read1 == 1){
    ledbright += 5;
  }

  if(read2 == 1){
    ledbright -= 5;
  }

  if(ledbright > 255){
    ledbright = 255;
  }

  if(ledbright < 0){
    ledbright = 0;
  }

  Serial.print("the value of analogWrite: ");
  Serial.println(ledbright);
  analogWrite(ledpin, ledbright); 
}
