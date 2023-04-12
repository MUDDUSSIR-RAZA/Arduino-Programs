// Define the pin numbers for the flame sensor, IR sensor, buzzer, laser, and lights
#define flamePin 2
#define irSensorpin 3
#define buzzer 12
#define laser 11
#define lights 7

void setup() {
  // Set the pin modes for the sensors and output devices
  pinMode(flamePin, INPUT);
  pinMode(irSensorpin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(laser, OUTPUT);

  // Start the serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Read the value of the IR sensor
  int irSensorValue = digitalRead(irSensorpin);

  // Read the value of the flame sensor
  int flameValue = digitalRead(flamePin);

  // If the IR sensor is detecting something, turn on the laser
  if (irSensorValue == HIGH) {
    digitalWrite(laser, HIGH);
  } else {
    digitalWrite(laser, LOW);
  }

  // If the flame sensor detects a flame, turn on the buzzer for 20ms and then turn it off for 20ms
  if (flameValue == LOW) {
    digitalWrite(buzzer, HIGH);
    delay(20);
    digitalWrite(buzzer, LOW);
    delay(20);
  } else {
    digitalWrite(buzzer, LOW);
  }

  // If both the flame sensor and IR sensor detect something, turn on the lights for 20ms and then turn them off for 20ms
  if (flameValue == LOW && irSensorValue == HIGH) {
    digitalWrite(lights, HIGH);
    delay(20);
    digitalWrite(lights, LOW);
    delay(20);
  }
}
