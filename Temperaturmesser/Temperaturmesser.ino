// const declarations
const int sensorPin = A0;
const float baselineTemp = 22.0;

// setting up the serial interface and the pins 2-4
void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}
