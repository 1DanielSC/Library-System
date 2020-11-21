#include <string>
#include <iostream>

#include "Product.h"
#include "Book.h"

//CONSTRUCTORS AND DESTRUCTOR
Book::Book(std::string bookName, std::string bookAuthor, int bookPagesNumber, int bookQuantity, int bookQuantitySold, double bookPrice):
	Product{bookName, bookQuantity, bookPrice}, Author{bookAuthor}, PagesNumber{bookPagesNumber}, QuantitySold{bookQuantitySold} {}

Book::Book(const Book& other_book):
	Product{other_book}, Author{other_book.Author}, PagesNumber{other_book.PagesNumber}, QuantitySold{other_book.QuantitySold} {}





//OVERLOADING OPERATORS

/*
+= and ++	Their usage is to increase the quantity sold (PRODUCT) of a book

-= and --	Their usage is to decrease the quantity (BOOK) available of a book 
*/



Book &Book::operator=(const Book& other_book){
	if (this == &other_book){
		return *this;
	}

	this->Product::operator=(other_book);
	
	this->Author = other_book.Author;
	this->PagesNumber = other_book.PagesNumber;
	return *this;
}


Book Book::operator++(int){ //Post-increment

	Book buff(*this); 
	this->QuantitySold++;
	return buff;
}


Book Book::operator--(int){ //Post-decrement
	Book buff(*this);
	this->Product::operator--();
	return buff;
}



//Increase book's quantity sold
Book &Book::operator+=(const int value){

	if (value < 0){
		std::cout << "Error: The value inserted is negative. The book quantity cannot be negative" << std::endl;
		return *this;
	}

	this->QuantitySold += value;
	return *this;
}

//Decrease book's quantity
Book &Book::operator-=(const int value){

	if (value > this->getQuantity()){
		std::cout << "Error: The value inserted is greater than the book quantity" << std::endl;
		return *this;
	}

	this->Product::operator-=(value);
	return *this;
}

bool Book::operator==(const Book& other_book) const{

	if (this->getName() == other_book.getName() && this->Author == other_book.Author){
		return true;
	}

	return false;
}




	
//SETTERS AND GETTERS

void Book::setAuthor(const std::string bookAuthor) {this->Author = bookAuthor;}
void Book::setPagesNumber(const int bookPagesNumber) {this->PagesNumber = bookPagesNumber;}
void Book::setQuantitySold(const int bookQuantitySold) {this->QuantitySold = bookQuantitySold;}

std::string Book::getAuthor() const {return this->Author;}
int Book::getPagesNumber() const {return this->PagesNumber;}
int Book::getQuantitySold() const {return this->QuantitySold;}

//Other functions

void Book::display() const{
	std::cout << std::endl;
	this->Product::display();

	std::cout << "Author's Name: " << this->Author << std::endl;
	std::cout << "Number of pages: " << this->PagesNumber << std::endl;
	std::cout << "Quantity sold: " << this->QuantitySold << std::endl;
	
	std::cout << std::endl;
}