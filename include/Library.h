#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <optional>

#include "Establishment.h"
#include "Vector.h"
//#include "Custumer.h"
#include "Book.h"


class Custumer;

class Library: public Establishment{

private:
	Vector<Book> Storage;

	friend class Custumer;

public:

	Library(std::string establishment_Name = "Not defined", int establishment_TotalSold = 0, double establishment_Revenue = 0.0);
	Library(const Library &other_library);

	bool sell(std::string bookName, int quantity);

	int findBookByName(std::string bookName);
	bool sellBook(int bookIndex, int quantityRequested);

	bool loadStorage();
	bool saveSales();

	void displayStorage() const;
};

#endif