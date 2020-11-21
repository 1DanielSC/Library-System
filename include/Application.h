#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>

//#include "Library.h"
//#include "Custumer.h"

class Library;
class Custumer;


struct Application
{
	int run(int argc, char const *argv[]);
	int endApplication(Library& library, std::vector<Custumer*>& custumers);

	void showLibraryMenu();
	void purchaseBookOperation(Library& library, std::vector<Custumer*>& custumers);
	void increaseMoneyOperation(std::vector<Custumer*>& custumers);

	bool newCustumerOperation(std::vector<Custumer*>& custumers);
};

#endif
