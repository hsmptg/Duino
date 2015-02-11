#ifndef ACEL_H_
#define ACEL_H_

#include "Arduino.h"

class Acel {
	public:
//		Acel();
		void begin();
		int getID();
		void start();
		void stop();
		void getData();
		void loop();
	private:
		unsigned long _last;
};

#endif /* ACEL_H_ */
