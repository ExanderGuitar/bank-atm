#include "access.h"

bool checkUser(std::string_view lineToCheck, std::string_view userToCheck) {

	std::string userRead {};

	userRead = lineToCheck.substr(0, lineToCheck.find(", Pass"));
	userRead = userRead.substr(userRead.find(":") + 2);

	return (userRead == userToCheck);
}

bool checkPass(std::string_view lineToCheck, std::string_view passToCheck) {

	std::string passRead {};

	passRead = lineToCheck.substr(lineToCheck.find("Pass:"));
	passRead = passRead.substr(passRead.find(":") + 2);
	passRead = passRead.substr(0, passRead.find(", B"));

	return (passRead == passToCheck);
}

void getBalance(std::string_view lineToCheck, double& balance) {

	std::string balanceRead {};

	balanceRead = lineToCheck.substr(lineToCheck.find("Balance:"));
	balanceRead = balanceRead.substr(balanceRead.find(":") + 2);

	balance = std::stod(balanceRead);
}

bool checkCredentials(std::string_view userToCheck, std::string_view passToCheck, double& balance) {
	std::ifstream fileIn {"users.txt", std::ios::in};
	
	if(!fileIn) {
		std::cout << "   Error con el archivo de lectura.\n";
		system("touch users.txt");
		return 1;
	}

	std::string line {};
	bool credentials {false};

	while(fileIn) {
		std::getline(fileIn, line);

		if(!line.empty()) {
			if(checkUser(line, userToCheck) && checkPass(line, passToCheck)) {
				getBalance(line, balance);
				credentials = true;
			}
		}
	}

	return credentials;
}

bool login(std::string& userLogged, std::string& passLogged, double& balance) {
	mainBanner();
	std::cout << "   Introduce tus datos de inicio de sesion.\n";
	std::cout << '\n';
	std::cout << "   Usuario: ";
	
	std::string user{};
	std::cin >> user;

	std::cout << "   Clave: ";

	std::string pass {};
	std::cin >> pass;

	std::cout << '\n';
	std::cout << "   Comprobando...\n";
	std::cout << '\n';

	if(checkCredentials(user, pass, balance)) {
		userLogged = user;
		passLogged = pass;
		clearWait('2');
		return true;
	}
	else {
		std::cout << "   Error al abrir la sesion.\n";
		clearWait('2');
		return false;
	}

} 
