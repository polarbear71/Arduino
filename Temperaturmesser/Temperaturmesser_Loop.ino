void loop() {
  // Read sensor value, calculate voltage and temperature in Celcius and transfer using the serial port
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  float temperature = (voltage - 0.5) * 100;
  Serial.println(temperature);

  // Set LEDs depending on temperature
  if (temperature < baselineTemp) {
    /*
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      delay(10);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      delay(1000);
    */
  } else if (temperature >= baselineTemp && temperature < baselineTemp + 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature > baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  // wait some time before reading next value
  delay(200);
}
