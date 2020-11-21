#ifndef ESTABLISHMENT_H
#define ESTABLISHMENT_H

#include <string>

#include "Vector.h"

class Establishment
{
private:

	std::string Name;

	int TotalSold;
	double Revenue;

public:
	Establishment(std::string establishment_Name = "Not defined", int establishment_TotalSold = 0, double establishment_Revenue = 0.0);
	Establishment(const Establishment &other_establishment);


	void setName(std::string establishment_Name);
	void setTotalSold(int establishment_TotalSold);
	void setRevenue(double establishment_Revenue);

	std::string getName();
	int getTotalSold();
	double getRevenue();

	void updateRevenueAndTotalSold(const int quantity, const double price);

};

#endif