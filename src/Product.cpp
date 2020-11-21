#include <iostream>
#include <string>

#include "Product.h"

//CONSTRUCTORS
Product::Product(std::string productName, int productQuantity, double productPrice):
	Name{productName}, Quantity{productQuantity}, Price{productPrice} {}


Product::Product(const Product& other_product){

	this->Name = other_product.Name;
	this->Quantity = other_product.Quantity;
	this->Price = other_product.Price;
}


//OVERLOADING OPERATORS

Product &Product::operator=(const Product& other_product){

	if (this == &other_product){
		return *this;
	}

	this->Name = other_product.Name;
	this->Quantity = other_product.Quantity;
	this->Price = other_product.Price;

	return *this;
}

Product &Product::operator*=(const int value){
	this->Quantity *= value;
	return *this;
}

Product &Product::operator+=(const int value){

	this->Quantity += value;
	return *this;
}


Product &Product::operator-=(const int value){
	this->Quantity -= value;
	return *this;
}


Product &Product::operator++(){ //Pre-increment
	
	this->Quantity++;
	return *this;
}

Product Product::operator++(int){ //Post-increment
	Product buff(*this);
	this->operator++();
	return buff;
}

Product &Product::operator--(){ //Pre-decrement

	if (this->Quantity == 0){
		std::cout << "This book's quantity cannot be decremented" << std::endl;
		return *this;
	}

	this->Quantity--;
	return *this;
}

Product Product::operator--(int){ //Post-decrement
	Product buff(*this);
	this->operator--();
	return buff;
}


//SETTERS AND GETTERS
void Product::setName(const std::string productName) {this->Name = productName;}
void Product::setQuantity(const int productQuantity) {this->Quantity = productQuantity;}
void Product::setPrice(const double productPrice) {this->Price = productPrice;}

std::string Product::getName() const {return this->Name;}
int Product::getQuantity() const {return this->Quantity;}
double Product::getPrice() const {return this->Price;}



//OTHER FUNCTIONS

void Product::changePrice(const double newPrice) {this->Price = newPrice;}

void Product::display() const{
	std::cout << std::endl;

	std::cout << "Name: " << this->Name << std::endl;
	std::cout << "Quantity: " << this->Quantity << std::endl;
	std::cout << "Price: $" << this->Price << std::endl;
}