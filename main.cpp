#include "main.h"

Server1 server;

#define LED 13
#define BUT 8
LedBut ledbut(BUT, LED, &server);

void setup() {
	server.begin(115200);
}

void loop() {
	char *cmd;
	if ((cmd = server.getCmd()) != 0) {
		switch(cmd[0]) {
			case 'v':
				server.sendMsg("v1.0 LedBut");
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
