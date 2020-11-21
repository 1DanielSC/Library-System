#include <string>
#include <fstream>
#include <optional>

#include "Custumer.h"
#include "Library.h"

#include "Product.h"
#include "Book.h"
#include "Vector.h"

#include "ExceptionClasses.h"

//CONSTRUCTORS
Custumer::Custumer(std::string custumerName, double custumerMoney)
	:Name{custumerName}, Money{custumerMoney} {}
	
Custumer::Custumer(const Custumer& other_custumer)
	:Name{other_custumer.Name}, Money{other_custumer.Money} {}


//SETTERS AND GETTERS
void Custumer::setName(std::string custumerName) {this->Name = custumerName;}
void Custumer::setMoney(double custumerMoney)  {this->Money = custumerMoney;}

std::string Custumer::getName() const {return this->Name;}
double Custumer::getMoney() const {return this->Money;}




//OTHER FUNCTIONS

void Custumer::updateBag(std::string bookName, int quantityRequested, double price){


	for (int i = 0; i < this->Bag.size(); i++){
		
		if (this->Bag[i].getName() == bookName){
			
			this->Bag[i] += quantityRequested;
			return;
		}
	}

	Product product(bookName, quantityRequested, price);

	this->Bag.push_back(product);
}

bool Custumer::purchase(Library& library, std::string productName, int quantityRequested){

	int bookIndex = library.findBookByName(productName);

	if (bookIndex >= 0){

		double productPrice = library.Storage[bookIndex].getPrice();

		if (this->Money < productPrice * quantityRequested){

			std::cout << "Custumer does not have sufficient money to perform this purchase" << std::endl;
			return false;
		}

		if (library.Storage[bookIndex].getQuantity() < quantityRequested){
			
			std::cout << "Book no longer available" << std::endl;
			return false;
		}		


		this->Money -= productPrice * quantityRequested;

		library.sellBook(bookIndex, quantityRequested);
		this->updateBag(productName, quantityRequested, productPrice);

		std::cout << "Product purchased!" << std::endl;

		return true;
	}	

	std::cout << "This book does not exist" << std::endl;
	return false;
}




bool Custumer::savePurchases(){
	std::ofstream file;
	std::string filename = "custumer_" + this->Name + ".csv";

	file.open(filename);

	if (file.is_open() ){
		
		file << "Custumer's name: " << this->Name << std::endl;
		file << "PRODUCT NAME,QUANTITY PURCHASED,PRICE" << std::endl;

		for (int i = 0; i < this->Bag.size(); i++){
			
			file << this->Bag[i].getName() << ',' << this->Bag[i].getQuantity() << ',' 
			<< this->Bag[i].getPrice() << std::endl;
		}

		return true;
	}

	throw CustumerFileException(this->Name, "File did not open", filename);
}


void Custumer::addMoney(const double money) {this->Money += money;}

void Custumer::showBag() const {

	std::cout << "Products bought by the custumer: " << this->Name << std::endl;
	this->Bag.display();
}