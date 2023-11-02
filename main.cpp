#include <iostream>

bool mainMenu(double& balance);
void cashDeposit(double& balance); 
void withdrawCash(double& balance); 
void displayBalance(double& balance); 
void endSession(); 
void clearWait();

int main() {
	
	system("clear");

	double accountBalance {0.0};
	bool loopFlag {true};

	while(loopFlag) {
		loopFlag = mainMenu(accountBalance);	
	}
}

void clearWait() {

	system("sleep 2");
	system("clear");
}

void displayBalance(double& balance) {

	std::cout << "Consulta de saldo.\n";
	std::cout << '\n';
	std::cout << "Su saldo actual es\n";
	std::cout << '\n';
	std::cout << balance << "€\n";
	std::cout << '\n';

	clearWait();
}

bool mainMenu(double& balance) {

	std::cout << "Bienvenido a tu banco\n";
	system("sleep 2");
	std::cout << '\n';
	std::cout << "Selecciona la operación que desees realizar.\n";
	std::cout << '\n';
	std::cout << "1. Ingresar efectivo.\n";
	std::cout << "2. Retirar efectivo.\n";
	std::cout << "3. Consultar saldo.\n";
	std::cout << "4. Terminar sesión.\n";
	std::cout << "Selección: ";
	
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
		std::cout << "Selección errónea. Intentelo de nuevo.\n";
		std::cout << '\n';
		break;
	}

	return loopFlag;
}

void endSession() {
	std::cout << "Finalizando la sesion.\n";
	std::cout << '\n';
	std::cout << "Gracias por usar nuestros servicios.\n";
	std::cout << '\n';

	clearWait();
}

void cashDeposit(double& balance) {
	std::cout << "Ingreso de efectivo\n";
	std::cout << '\n';
	std::cout << "Indique la cantidad a ingresar\n";
	std::cout << ">> ";

	double amount {};
	std::cin >> amount;

	balance += amount;

	std::cout << "Efectivo realizado con exito.\n";
	std::cout << '\n';

	clearWait();
}

void withdrawCash(double& balance) {
	std::cout << "Retirada de efectivo\n";
	std::cout << '\n';
	std::cout << "Indique la cantidad a extraer\n";
	std::cout << ">> ";

	double amount {};
	std::cin >> amount;

	balance -= amount;

	std::cout << "Efectivo retirado con exito.\n";
	std::cout << '\n';

	clearWait();
} 
