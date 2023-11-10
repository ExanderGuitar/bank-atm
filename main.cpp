#include <iostream>
#include <fstream>

void mainBanner(); 
bool mainMenu(double& balance);
void cashDeposit(double& balance); 
void withdrawCash(double& balance); 
void displayBalance(double& balance); 
void endSession(); 
void clearWait(char second); 
bool login();
bool checkUser(std::string_view user); 

int main() {
	
	system("clear");

	double accountBalance {0.0};
	bool loopFlag {true};

	while(loopFlag) {
		if(!login()) {
			break;
		}	
		loopFlag = mainMenu(accountBalance);	
	}
}

void clearWait(char second = '1') {

	char command[] = "sleep 1";
	command[6] = second;
	system(command);
	system("clear");
}

void displayBalance(double& balance) {
	mainBanner();
	std::cout << "   Consulta de saldo.\n";
	std::cout << '\n';
	std::cout << "   Su saldo actual es\n";
	std::cout << '\n';
	std::cout << "   " << balance << "€\n";
	std::cout << '\n';

	clearWait('3');
}

void mainBanner() {
	std::cout << '\n';
	std::cout << " Banco SCT\n";
	std::cout << " --------------------------------------------------\n";
	std::cout << '\n';
}

bool mainMenu(double& balance) {
	
	mainBanner();
	std::cout << "   Bienvenido a tu banco\n";
	system("sleep 1");
	std::cout << '\n';
	std::cout << "   Selecciona la operación que desees realizar.\n";
	std::cout << '\n';
	std::cout << "      1. Ingresar efectivo.\n";
	std::cout << "      2. Retirar efectivo.\n";
	std::cout << "      3. Consultar saldo.\n";
	std::cout << "      4. Terminar sesión.\n";
	std::cout << '\n';
	std::cout << "   Selección: ";
	
	int selection {};
	std::cin >> selection;

	clearWait();

	bool loopFlag {true};

	switch(selection) {
	case 1:
		//Ingresar efectivo
		cashDeposit(balance);
		break;
	case 2:
		//Retirar efectivo
		withdrawCash(balance); 
		break;
	case 3:
		//Consultar saldo
		displayBalance(balance); 
		break;
	case 4:
		//Finalizar sesion
		loopFlag = false;
		endSession();
		break;
	default:
		//Error
		std::cout << "   Selección errónea. Intentelo de nuevo.\n";
		std::cout << '\n';
		break;
	}

	return loopFlag;
}

void endSession() {

	mainBanner();
	std::cout << "   Finalizando la sesion.\n";
	std::cout << '\n';
	std::cout << "   Gracias por usar nuestros servicios.\n";
	std::cout << '\n';

	clearWait('2');
}

void cashDeposit(double& balance) {
	mainBanner();
	std::cout << "   Ingreso de efectivo\n";
	std::cout << '\n';
	std::cout << "   Indique la cantidad a ingresar\n";
	std::cout << '\n';
	std::cout << "   >> ";

	double amount {};
	std::cin >> amount;

	balance += amount;

	std::cout << '\n';
	std::cout << "   Efectivo realizado con exito.\n";
	std::cout << '\n';

	clearWait('2');
}

void withdrawCash(double& balance) {
	mainBanner();
	std::cout << "   Retirada de efectivo\n";
	std::cout << '\n';
	std::cout << "   Indique la cantidad a extraer\n";
	std::cout << '\n';
	std::cout << "   >> ";

	double amount {};
	std::cin >> amount;

	balance -= amount;

	std::cout << '\n';
	std::cout << "   Efectivo retirado con exito.\n";
	std::cout << '\n';

	clearWait('2');
} 

bool checkUser(std::string_view user) {
	std::ifstream fileIn {"users.txt", std::ios::in};

	if(!fileIn) {
		std::cout << "   Error con el archivo de lectura.\n";
		system("touch users.txt");
	}

	bool userExist {false};

	while(fileIn) {
		std::string userRead{};
		std::getline(fileIn, userRead);

		if(userRead == user) {
			//User exists
			userExist = true;
		}
	}

	return userExist;
}

bool login() {
	mainBanner();
	std::cout << "   Introduce tus datos de inicio de sesion.\n";
	std::cout << '\n';
	std::cout << "   Usuario: ";
	
	std::string user{};
	std::cin >> user;

	std::cout << "   Clave: ";

	int pass {};
	std::cin >> pass;

	std::cout << '\n';
	std::cout << "   Comprobando...\n";
	std::cout << '\n';

	bool loginSucces {false};

	if(checkUser(user)) {
		std::cout << "   Usuario correcto.\n";
		loginSucces = checkUser(user);
	}
	else {
		std::cout << "   El usuario introducido es incorrecto o no existe.\n";
	}

	clearWait('2');
	return loginSucces;
} 
