#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:

	std::string Name;
	
	int Quantity;

	double Price;

public:
//CONSTRUCTORS	
	Product(std::string productName = "Not defined", int productQuantity = 0, double productPrice = 0.0);
	Product(const Product& other_product);

//OVERLOADING OPERATORS

	Product &operator=(const Product& other_product);

	Product &operator*=(const int value);
	Product &operator+=(const int value);
	Product &operator-=(const int value);

	Product &operator++(); //Pre-increment
	Product operator++(int); //Post-increment
	Product &operator--(); //Pre-decrement
	Product operator--(int); //Post-decrement


//SETTERS AND GETTERS	
	void setName(const std::string productName);
	void setQuantity(const int productQuantity);
	void setPrice(const double productPrice);

	std::string getName() const;
	int getQuantity() const;
	double getPrice() const;

//OTHER FUNCTIONS
	void changePrice(const double newPrice);
	void display() const;	
};

#endif