FILES = main.o Product.o Book.o Establishment.o Library.o Custumer.o Application.o ExceptionClasses.o
COMPILER = g++
PROGRAM = LibrarySystem
GCC_FLAGS = -I include -std=c++11 -Wall

all: $(PROGRAM)

$(PROGRAM): $(FILES)
	$(COMPILER) $(GCC_FLAGS) $(FILES) -o $(PROGRAM)

main.o: src/main.cpp include/Application.h src/Application.cpp
	$(COMPILER) $(GCC_FLAGS) -c src/main.cpp

Product.o: src/Product.cpp include/Product.h
	$(COMPILER) $(GCC_FLAGS) -c src/Product.cpp

Book.o: src/Book.cpp include/Book.h include/Product.h
	$(COMPILER) $(GCC_FLAGS) -c src/Book.cpp

Establishment.o: src/Establishment.cpp include/Establishment.h
	$(COMPILER) $(GCC_FLAGS) -c src/Establishment.cpp

Library.o: src/Library.cpp include/Establishment.h include/Library.h include/Vector.h include/Book.h include/ExceptionClasses.h
	$(COMPILER) $(GCC_FLAGS) -c src/Library.cpp

Custumer.o: src/Custumer.cpp include/Custumer.h include/Vector.h include/Library.h include/Product.h include/Book.h include/ExceptionClasses.h
	$(COMPILER) $(GCC_FLAGS) -c src/Custumer.cpp

Application.o: src/Application.cpp include/Application.h include/Library.h include/Custumer.h include/ExceptionClasses.h
	$(COMPILER) $(GCC_FLAGS) -c src/Application.cpp

ExceptionClasses.o: src/ExceptionClasses.cpp include/ExceptionClasses.h
	$(COMPILER) $(GCC_FLAGS) -c src/ExceptionClasses.cpp

.PHONY: clean run

clean:
	rm *.o

run: LibrarySystem
	./$(PROGRAM)
