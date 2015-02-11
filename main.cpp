#include "main.h"

Server1 server;

#define VERSION_STR "v1.0 Duino"

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
		}
	}
}
