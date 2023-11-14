#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>

void mainBanner(); 
bool mainMenu(double& balance, std::string_view user);
void cashDeposit(double& balance); 
void withdrawCash(double& balance); 
void displayBalance(double& balance); 
void endSession(); 
void clearWait(char second = '1'); 

#endif
