#include "main.h"

Server1 server;
Acel acel;

#define VERSION_STR "v1.1 Acel"

void setup() {
	server.begin(115200);
	server.sendMsg(VERSION_STR);
	acel.begin();
}

void loop() {
	int id;
	char *cmd;
	if ((cmd = server.getCmd()) != 0) {
		switch(cmd[0]) {
		case 'v':
			server.sendMsg(VERSION_STR);
			break;
		case 'i':
			id = acel.getID();
			Serial.print("ID= ");
			Serial.println(id, HEX);
//			server.sendMsg("ID= " + id);
			break;
		case 'a':
			if (cmd[1] == '1')
				acel.start();
			else
				acel.stop();
			break;
		}
	}
	acel.loop();
}
