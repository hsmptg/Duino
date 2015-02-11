#include "acel.h"
#include "Wire.h"

const int ADXL345 = 0x53; // I2C address for ADXL345
int x, y, z;
uint8_t dat[10];

//Acel::Acel() {
//}

void Acel::begin() {
	Wire.begin(); // set up Arduino I2C support

    Wire.beginTransmission(ADXL345);
    Wire.write(0x2D);
    Wire.write(0x08); // Set "Measure bit" (D3) of "POWER_CTL" register (page 25 of datasheet)
    Wire.endTransmission();
}

void Acel::start() {
	_last = millis();
}

void Acel::stop() {
	_last = 0;
}

int Acel::getID() {
	Wire.beginTransmission(ADXL345);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom (ADXL345, 1);
    Wire.readBytes(dat, 1);

    return dat[0];
}

#define DELAY 100

void Acel::loop() {
	unsigned long now;

	if (_last) {
		now = millis();
		if ((now - _last) > DELAY) {
			_last += DELAY;
			getData();
		}
	}
}

void Acel::getData() {
	Wire.beginTransmission(ADXL345);
    Wire.write(0x32);
    Wire.endTransmission();
    Wire.requestFrom (ADXL345, 6);
    Wire.readBytes(dat, 6);
    x = ((uint16_t)dat[1] << 8) + dat[0];
	y = ((uint16_t)dat[3] << 8) + dat[2];
	z = ((uint16_t)dat[5] << 8) + dat[4];

	// envia uma mensagem "t ttt xxx yyy zzz\n"
	// o ttt e' o tempo em milisegundos
//	Serial.print("t ");
//	Serial.print(t);
//	Serial.print(" ");
	Serial.print("a ");
	Serial.print(x);
	Serial.print(" ");
	Serial.print(y);
	Serial.print(" ");
	Serial.println(z); // O println envia "\r\n" no fim!
}
