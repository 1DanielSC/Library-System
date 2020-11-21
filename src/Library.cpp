#include <string>
#include <fstream>
#include <sstream>
#include <optional>

#include "Establishment.h"
#include "Library.h"
#include "Vector.h"
#include "Book.h"
#include "ExceptionClasses.h"

//CONSTRUCTORS
Library::Library(std::string establishment_Name, int establishment_TotalSold, double establishment_Revenue)
	:Establishment{establishment_Name, establishment_TotalSold, establishment_Revenue} 
	
	{
		
		try{
			this->loadStorage();
		}
		catch(const LibraryFileException& exception){

			exception.showErrorMessage();
			std::cerr << "It was not possible to load storage from the file" << std::endl;
			throw(false);
		}
		
	}

Library::Library(const Library &other_library)
	:Establishment{other_library}, Storage{other_library.Storage} {}
	//other_library is-a Establishment, then other_library is sliced off





//OTHER FUNCTIONS

int Library::findBookByName(std::string bookName){

	for (int index = 0; index < this->Storage.size(); index++){

		if (this->Storage[index].getName() == bookName){

			return index;
		}
	}

	return -1;
}




bool Library::sellBook(int bookIndex, int quantityRequested){


	this->Storage[bookIndex] += quantityRequested; //Increasing book's quantity sold
	this->Storage[bookIndex] -= quantityRequested; //Decreasing book's quantity

	this->updateRevenueAndTotalSold(quantityRequested, this->Storage[bookIndex].getPrice() );

	return true;
}



//PROBLEM IN THE FUNCTION BELOW

bool Library::loadStorage(){
	std::ifstream file;
	file.open("Books.csv");

	if (file.is_open()){
		
		std::string line;
		getline(file, line); //Ignore the first line

		while(!file.eof()){

			Book item;

			getline(file, line, ','); //GET NAME

      		if(line.size() == 0){
        		continue;
      		}

			item.setName(line);


			getline(file, line, ','); //GET AUTHOR'S NAME
			item.setAuthor(line);


			getline(file, line, ','); //GET THE NUMBER OF PAGES
			int pages_number;
			std::stringstream buffer_pages(line);

			buffer_pages >> pages_number;
			item.setPagesNumber(pages_number);


			item.setQuantitySold(0);


			getline(file, line, ','); //GET THE PRICE
			double price;
			char discard;
			std::stringstream buffer_price(line);

			buffer_price >> discard;
			buffer_price >> price;
			item.setPrice(price);



			getline(file, line, '\n'); //GET THE QUANTITY
			int quantity;
			std::stringstream buffer_quantity(line);

			buffer_quantity >> quantity;
			item.setQuantity(quantity);

			this->Storage.push_back(item); //ADD THE BOOK TO THE STORAGE
      
		}

		return true;
	}

	throw LibraryFileException(this->getName(), "Storage file did not open", "Books.csv");
}


bool Library::saveSales(){
	std::ofstream file;
	std::string filename = this->getName() + "_Sales.csv";
	file.open(filename);

	if (file.is_open()){

		file << "Establishment name: " << this->getName() << std::endl;
		file << "Quantity sold: " << this->getTotalSold() << std::endl;
		file << "Establishment revenue: " << this->getRevenue() << std::endl;

		file << "BOOK NAME,AUTHOR,PAGES NUMBER,QUANTITY SOLD,PRICE" << std::endl;

		for (int i = 0; i < this->Storage.size(); i++){
			
			if (this->Storage[i].getQuantitySold() > 0){

				file << this->Storage[i].getName() << ',' << this->Storage[i].getAuthor() << ','
				<< this->Storage[i].getPagesNumber() << ',' << this->Storage[i].getQuantitySold() << ','
				<< this->Storage[i].getPrice() << std::endl;
			}
		}

		std::cout << "Sales from " << this->getName() << " saved" << std::endl;
		return true;
	}

	throw LibraryFileException(this->getName(), "File did not open", filename);
}


void Library::displayStorage() const {this->Storage.display();}