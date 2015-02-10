#include "ledbut.h"

LedBut::LedBut(int butPin, int ledPin, Server1 *print) {
	_print = print;

	_butPin = butPin;
	pinMode(_butPin, INPUT);
	digitalWrite(_butPin, HIGH);
	_butState = digitalRead(_butPin);

	_ledPin = ledPin;
	pinMode(_ledPin, OUTPUT);
	digitalWrite(_ledPin, LOW);
}

void LedBut::cmdBut() {
	if (!_butState)
		_print->sendMsg("b1");
	else
		_print->sendMsg("b0");

}

void LedBut::cmdLed(const char *cmd) {
  if (cmd[1] == '1') {
    digitalWrite(_ledPin, HIGH);
  }
  else {
    digitalWrite(_ledPin, LOW);
  }
}

void LedBut::loop() {
	int b = digitalRead(_butPin);
	if (b != _butState) {
		_butState = b;
		cmdBut();
	}
}





