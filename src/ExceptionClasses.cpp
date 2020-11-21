#include <string>
#include <iostream>

#include "ExceptionClasses.h"

LibraryFileException::LibraryFileException(std::string libraryName, std::string error, std::string filename):
	LibraryName{libraryName}, Error{error}, FileName{filename} {}

void LibraryFileException::showErrorMessage() const{

	std::cout << "Library name: " << this->LibraryName << std::endl;
	std::cout << "Error: " << this->Error << std::endl;
	std::cout << "File: " << this->FileName << std::endl;
}



CustumerFileException::CustumerFileException(std::string custumerName, std::string error, std::string filename):
	CustumerName{custumerName}, Error{error}, FileName{filename} {}

void CustumerFileException::showErrorMessage() const{

	std::cout << "Custumer name: " << this->CustumerName << std::endl;
	std::cout << "Error: " << this->Error << std::endl;
	std::cout << "File: " << this->FileName << std::endl;
}