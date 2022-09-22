// ds18b20.h

#ifndef _DS18B20_h
#define _DS18B20_h


#include "arduino.h"

class ds18b20 {
	public:
	ds18b20(int pin);
	void init(int pin);
	void startConversion();
	float getTemperature();
	private:
	int _pin;
	
};


#endif

