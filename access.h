#ifndef ACCESS_H
#define ACCESS_H

#include <iostream>
#include <fstream>
#include "display.h"

struct Client {
	std::string name {"Unknown"};
	std::string code {"0000"};
	double balance {0.0};
};

bool login(std::string& userLogged, std::string& passLogged, double& balance);
bool checkCredentials(std::string_view userToCheck, std::string_view passToCheck, double& balance); 
bool checkUser(std::string_view lineToCheck, std::string_view userToCheck); 
bool checkPass(std::string_view lineToCheck, std::string_view passToCheck); 
void getBalance(std::string_view lineToCheck, double& balance);


#endif
