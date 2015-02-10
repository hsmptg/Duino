#ifndef SERVER_H_
#define SERVER_H_

#include "Arduino.h"

class Server1 {
	public:
		void begin(unsigned long int baudrate);
		char *getCmd();
		void sendMsg(const char *msg);
};

#endif /* SERVER_H_ */
