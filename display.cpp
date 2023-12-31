#include "display.h"

void mainBanner() {
	std::cout << '\n';
	std::cout << " Banco SCT\n";
	std::cout << " --------------------------------------------------\n";
	std::cout << '\n';
}

bool mainMenu(double& balance, std::string_view user) {
	
	mainBanner();
	std::cout << "   Bienvenido a tu banco, " << user << "\n";
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

void endSession() {

	mainBanner();
	std::cout << "   Finalizando la sesion.\n";
	std::cout << '\n';
	std::cout << "   Gracias por usar nuestros servicios.\n";
	std::cout << '\n';

	clearWait('2');
}

void clearWait(char second) {

	char command[] = "sleep 1";
	command[6] = second;
	system(command);
	system("clear");
}


