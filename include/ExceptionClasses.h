#ifndef EXCEPTIONCLASSES_H
#define EXCEPTIONCLASSES_H

#include <string>



class LibraryFileException{
private:
	std::string LibraryName;
	std::string Error;
	std::string FileName;

public:
	LibraryFileException(std::string libraryName = "Not defined", std::string error = "Error not defined", std::string filename = "File not defined");

	void showErrorMessage() const;
};


class CustumerFileException{
private:
	std::string CustumerName;
	std::string Error;
	std::string FileName;

public:
	CustumerFileException(std::string custumerName = "Not defined", std::string error = "Error not defined", std::string filename = "File not defined");

	void showErrorMessage() const;
};

#endif