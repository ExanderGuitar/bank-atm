#!/bin/bash

clear;

echo "Compiling main -> main.cpp";
echo "";

echo "Compiling dependencies:";
echo " -  display.h";
echo " -  access.h";
echo "";

g++ -o Bank_ATM main.cpp display.cpp access.cpp -std=c++2a;

echo "Successfully compiled.";
echo "Program saved as: bancotest";
echo "";
