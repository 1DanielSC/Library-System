#include <iostream>
#include <string>
#include <vector>
#include <new>

#include "Application.h"
#include "Library.h"
#include "Custumer.h"
#include "ExceptionClasses.h"

void Application::showLibraryMenu(){

	std::cout << std::endl;
	std::cout << "APPLICATION MENU" << std::endl;
	std::cout << std::endl;
	std::cout << "1 - Purchase a book" << std::endl;
	std::cout << "2 - Add more money to the custumer" << std::endl;
	std::cout << "3 - Show custumer's bag" << std::endl;
	std::cout << "4 - Show library's storage" << std::endl;
	std::cout << "5 - Restock a library's product" << std::endl;
	std::cout << "6 - Show provider's storage" << std::endl;
	std::cout << "8 - New custumer" << std::endl;
	std::cout << "9 - End program" << std::endl;

	std::cout << std::endl;

	std::cout << "Select an option: ";
}


void Application::purchaseBookOperation(Library& library, std::vector<Custumer*>& custumers){

	std::cin.ignore();
	std::string bookName;
	std::cout << "Type the book's name: ";
	std::getline(std::cin, bookName);

	std::cout << "Quantity desired: ";
	int quantityRequested;
	std::cin >> quantityRequested;
	std::cin.ignore();

	custumers.back()->purchase(library, bookName, quantityRequested);
}



void Application::increaseMoneyOperation(std::vector<Custumer*>& custumers){

	std::cout << "Insert the amount of money: ";
	double money;
	std::cin >> money;

	custumers.back()->addMoney(money);
}




bool Application::newCustumerOperation(std::vector<Custumer*>& custumers){

	std::cin.ignore();
	std::cout << "Custumer's name: ";
	std::string custumerName;
	std::getline(std::cin, custumerName);

	std::cout << "Custumer's initial money: ";
	double custumerMoney;
	std::cin >> custumerMoney;
	std::cin.ignore();

	try{
		custumers.push_back(new Custumer(custumerName, custumerMoney));
		return true;
	}
	catch(const std::bad_alloc &bad_alloc){
		std::cerr << "Error: It was not possible to add a new costumer" << std::endl;
		return false;
	}
}

int Application::endApplication(Library& library, std::vector<Custumer*>& custumers){

	try{
		library.saveSales();
		custumers.back()->savePurchases();
		return 0;
	}

	catch(const LibraryFileException &exception){

		exception.showErrorMessage();
		std::cerr << "It was not possible to save the sales from this library" << std::endl;
	}

	catch(const CustumerFileException &exception){

		exception.showErrorMessage();
		std::cerr << "It was not possible to save the purchases from this custumer" << std::endl;
	}

	
	return 1;
}




int Application::run(int argc, char const *argv[]){

	try{
		Library library ("Saraiva");


		std::vector<Custumer*> custumers;
		custumers.push_back(new Custumer());

		while(true){
			this->showLibraryMenu();

			int option;
			std::cin >> option;

			switch(option){

				case 1: this->purchaseBookOperation(library, custumers); break;
				case 2: this->increaseMoneyOperation(custumers); break;
				case 3: custumers.back()->showBag(); break;
				case 4: library.displayStorage(); break;
				case 8: this->newCustumerOperation(custumers); break;
				case 9: return this->endApplication(library, custumers);
				default: std::cout << "Invalid option" << std::endl; break;
		}
	}



	}
	catch(const bool& exception){

		std::cerr << "Application has failed" << std::endl;
		return 1;
	}
}