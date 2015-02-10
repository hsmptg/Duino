#ifndef LEDBUT_H_
#define LEDBUT_H_

#include "Arduino.h"
#include "server.h"

class LedBut {
	public:
		LedBut(int butPin, int ledPin, Server1 *print);
		void cmdBut();
		void cmdLed(const char *cmd);
		void loop();
	private:
		int _butPin;
		int _ledPin;
		int _butState;
		Server1 *_print;
};

#endif /* LEDBUT_H_ */
