#include <iostream>
#include <fstream>
#include "display.h"
#include "access.h"

int main() {
	
	system("clear");

	Client client{};	

	bool loopFlag {true};

	if(!login(client.name, client.code, client.balance)) {
		return 1;
	}
	else {
		while(loopFlag) {
			loopFlag = mainMenu(client.balance, client.name);	
		}
	}
}

