// Define analog input pin for light sensor and digital output pin for buzzer
int lightpin = A0;
int buzzpin = 9;

int lightval;  // Variable to store analog value from light sensor
int delayt;    // Variable to store delay time

void setup() {
  pinMode(lightpin, INPUT);   // Set lightpin (A0) as input
  pinMode(buzzpin, OUTPUT);   // Set buzzpin (9) as output
  Serial.begin(9600);         // Initialize serial communication at 9600 baud
}

void loop() {
  lightval = analogRead(lightpin);   // Read analog value from light sensor (0-1023)
  
  // Calculate delay based on lightval
  delayt = (9. / 550) * lightval - (9. * 200. / 550) + 1;
  
  Serial.println(delayt);    // Print delayt value to Serial Monitor
  
  digitalWrite(buzzpin, HIGH);   // Turn buzzer on
  delay(delayt);                  // Wait for delayt milliseconds
  digitalWrite(buzzpin, LOW);    // Turn buzzer off
  delay(delayt);                  // Wait for delayt milliseconds (to create a tone)
}
