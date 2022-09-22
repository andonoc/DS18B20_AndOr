#include "ds18b20_AndOr.h"
#define sensorPin 4
ds18b20 temperatureSensor(sensorPin);        //ds18b20 Sensor
float temperature;
void setup() {
  

}

void loop() {
  temperatureSensor.startConversion();      //request measuring of ds18b20 bulb sensor
  delay(1000);
  temperature = temperatureSensor.getTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  delay(2000);

}
