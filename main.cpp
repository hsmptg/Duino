#include "main.h"

Server1 server;

void setup() {
	server.begin(115200);
}

void loop() {
	char *cmd;
	if ((cmd = server.getCmd()) != 0) {
		switch(cmd[0]) {
			case 'v':
				server.sendMsg("v1.0 Duino");
				break;
		}
	}
}
