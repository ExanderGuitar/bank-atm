#ifndef ACCESS_H
#define ACCESS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "display.h"

struct Client {
	std::string name {"Unknown"};
	std::string code {"0000"};
	double balance {0.0};
};

void saveClients (std::vector<Client> clientsList);
void updateClient (std::vector<Client>& clientsList, Client clientRef);
std::vector<Client> getClients ();
std::string getUser (std::string_view lineToCheck);
std::string getPass (std::string_view lineToCheck);

bool login(std::string& userLogged, std::string& passLogged, double& balance);
bool checkCredentials(std::string_view userToCheck, std::string_view passToCheck, double& balance); 
bool checkUser(std::string_view lineToCheck, std::string_view userToCheck); 
bool checkPass(std::string_view lineToCheck, std::string_view passToCheck); 
void getBalance(std::string_view lineToCheck, double& balance);


#endif
