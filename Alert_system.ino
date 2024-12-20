void setup() {
  pinMode(9, OUTPUT);       // Set pin 9 as output
  pinMode(A0, INPUT);       // Set pin A0 as input
  pinMode(11, OUTPUT);      // Set pin 11 as output
  Serial.begin(9600);       // Initialize serial communication at 9600 baud
}

void loop() {
  int x = analogRead(A0);   // Read analog value from A0
  Serial.println(x);        // Print the value to the Serial Monitor

  int y = x / 4;            // Map the 0-1023 range to 0-255 (PWM range)

  if (x >= 300) {           // Check if the input value is greater than or equal to 300
    digitalWrite(9, HIGH);  // Turn on the digital pin 9
    analogWrite(11, y);     // Write the PWM value to pin 11
  } else {                  // If the input value is less than 300
    digitalWrite(9, LOW);   // Turn off the digital pin 9
    analogWrite(11, 0);     // Set PWM value to 0 (off)
  }
  delay(100);               // Add a short delay to stabilize readings
}
