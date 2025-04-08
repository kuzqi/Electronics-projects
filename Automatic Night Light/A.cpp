// Define LEDs sensor pin
const int Green_LED = 8;
const int Blue_LED = 4;
const int Red_LED = 2;

// Define LDR sensor pin
const int Sensor_PIN = A0;

// Threshold to turn on the LEDs
const int Green_Threshold = 250;
const int Blue_Threshold = 400;
const int Red_Threshold = 520;

// Sensor reading value
int sensorValue;

void setup() {
  pinMode(Green_LED, OUTPUT);   // Define the green LED as an output
  pinMode(Blue_LED, OUTPUT);    // Define the blue LED as an output
  pinMode(Red_LED, OUTPUT);     // Define the red LED as an output
  Serial.begin(9600);           // Initialize serial communication
}

void loop() {

  sensorValue = analogRead(Sensor_PIN);   // Read the sensor's value
  Serial.println(sensorValue);    // Print the sensor's value in the serial monitor (for Debugging)

  // Reset all LEDs to LOW (turn them off)
  digitalWrite(Green_LED, LOW);
  digitalWrite(Blue_LED, LOW);
  digitalWrite(Red_LED, LOW);

  // Turn on the LED based on the sensor value
  if (sensorValue < Green_Threshold) {
    digitalWrite(Green_LED, HIGH); // Turn on green LED
  } else if (sensorValue < Blue_Threshold) {
    digitalWrite(Blue_LED, HIGH);  // Turn on blue LED
  } else if (sensorValue < Red_Threshold) {
    digitalWrite(Red_LED, HIGH);   // Turn on red LED
  }
}
