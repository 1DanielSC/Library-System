#include <string>

#include "Establishment.h"


//CONSTRUCTORS
Establishment::Establishment(std::string establishment_Name, int establishment_TotalSold, double establishment_Revenue)
	:Name{establishment_Name}, TotalSold{establishment_TotalSold}, Revenue{establishment_Revenue} {}

Establishment::Establishment(const Establishment &other_establishment)
	:Name{other_establishment.Name}, TotalSold{other_establishment.TotalSold}, Revenue{other_establishment.Revenue} {}

//SETTERS AND GETTERS
void Establishment::setName(std::string establishment_Name) {this->Name = establishment_Name;}
void Establishment::setTotalSold(int establishment_TotalSold) {this->TotalSold = establishment_TotalSold;}
void Establishment::setRevenue(double establishment_Revenue) {this->Revenue = establishment_Revenue;}


std::string Establishment::getName() {return this->Name;}
int Establishment::getTotalSold() {return this->TotalSold;}
double Establishment::getRevenue() {return this->Revenue;}


//OTHER FUNCTIONS
void Establishment::updateRevenueAndTotalSold(const int quantity, const double price) {
	this->TotalSold += quantity;
	this->Revenue += quantity*price;
}
