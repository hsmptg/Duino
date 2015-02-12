#include "main.h"

Server1 server;

#define VERSION_STR "v1.0 LedBut"

#define LED 13
#define BUT 8
LedBut ledbut(BUT, LED, &server);

void setup() {
	server.begin(115200);
	server.sendMsg(VERSION_STR);
}

void loop() {
	char *cmd;
	if ((cmd = server.getCmd()) != 0) {
		switch(cmd[0]) {
			case 'v':
				server.sendMsg(VERSION_STR);
				break;
			case 'l':
				ledbut.cmdLed(cmd);
				break;
			case 'b':
				ledbut.cmdBut();
				break;
		}
	}
	ledbut.loop();
}
