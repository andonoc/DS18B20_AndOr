// 
// 
// 

#include "ds18b20_AndOr.h"
#include <OneWire.h>


ds18b20::ds18b20(int pin) {
	_pin=pin;
}//constructor end

void ds18b20::startConversion(){
	OneWire ds(_pin);
	//##1,2## Tx  Master Read ROM address
	ds.reset();
	
	//##3## Tx  "Skip ROM" command vor "temp read" command um ohne adresse messung zu starten
	ds.write(0xCC);

	//##4,5## Tx  sending Temp reading command
	ds.write(0x44, 1);
}




float ds18b20::getTemperature() {
	OneWire ds(_pin);
	byte data[9];
	bool present1 = 0;
	bool present2 = 0;
	/*
	//##1,2## Tx  Master Read ROM address
	ds.reset();
	
	//##3## Tx  "Skip ROM" command vor "temp read" command um ohne adresse messung zu starten
	ds.write(0xCC);

	//##4,5## Tx  sending Temp reading command
	ds.write(0x44, 1);
	delay(1000);

*/

	//##6,7## Tx  Master Reset
	ds.reset();
	
	//##8## Tx  "Skip ROM" command vor "read scratchpad" command um ohne adresse das scratchpad zu lesen
	ds.write(0xCC);

	//##9## Rx read Scratchpad command
	ds.write(0xBE);

	//##10## Rx read 9 bytes
	for (int i = 0; i < 9; i++) {
		data[i] = ds.read();
	}
	

	
	int16_t convert = (data[1] << 8) | data[0];
	float convertToFloat = ((float)convert) / 16;
	//Serial.println(convertToFloat);
	return  convertToFloat;

	
}


