# DS18B20_AndOr
 Arduino library to read DS18B20 Temperature Sensors for low power applications.

The downside of the DS18B20 is the long conversion Time.
Simply call startConversion(), sleep for the requested convesion time, wake up and with getTemperature() you have the desired temperature