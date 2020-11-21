#ifndef CUSTUMER_H
#define CUSTUMER_H

#include <string>

#include "Product.h"
#include "Vector.h"


class Library; //Forward declaration

class Custumer
{
private:
	std::string Name;

	double Money;

	Vector<Product> Bag;

public:
	Custumer(std::string custumerName = "Not defined", double custumerMoney = 50.0);
	Custumer(const Custumer& other_custumer);

	void setName(std::string custumerName);
	void setMoney(double custumerMoney);

	std::string getName() const;
	double getMoney() const;

	bool purchase(Library& library, std::string productName, int quantityRequested);
	bool savePurchases();

	void updateBag(std::string bookName, int quantityRequested, double price);
	void addMoney(const double money);
	void showBag() const;
	
};
#endif