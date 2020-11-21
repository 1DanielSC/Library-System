#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "Product.h"

class Book: public Product{
private:

	std::string Author;

	int PagesNumber;
	int QuantitySold;

public:
//CONSTRUCTORS and DESTRUCTOR
	Book(std::string bookName = "Not defined", std::string bookAuthor = "Not defined", int bookPagesNumber = 0, int bookQuantity = 0, int bookQuantitySold = 0, double bookPrice = 0.0);
	Book(const Book& other_book);

//OVERLOADING OPERATORS
	Book &operator=(const Book& other_book); //Copy assignment
	
	Book operator++(int); //Post-increment
	Book operator--(int); //Post-decrement

	Book &operator+=(const int value);
	Book &operator-=(const int value);

	bool operator==(const Book& other_book) const; //Verify whether 2 books are equal or not

	
//SETTERS AND GETTERS
	
	void setAuthor(const std::string bookAuthor);
	void setPagesNumber(const int bookPagesNumber);
	void setQuantitySold(const int productQuantitySold);

	std::string getAuthor() const;
	int getPagesNumber() const;
	int getQuantitySold() const;


//Other functions

	void display() const;
};

#endif