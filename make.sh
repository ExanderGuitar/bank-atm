#!/bin/bash

clear;

echo "Compiling -> main.cpp";

g++ -o bancotest main.cpp -std=c++2a;

echo "Successfully compiled.";
echo "Program saved as: bancotest";
echo "";
