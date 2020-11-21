#ifndef VECTOR_H
#define VECTOR_H

#include <new>
#include <string>
#include <iostream>


template <class T>
class Vector{

private:
	T* Elements;

	int Size;
	int Capacity;

public:

	Vector(int vectorSize = 0, int vectorCapacity = 10);
	Vector(const Vector &other_vector);
	Vector(Vector &&other_vector);
	~Vector();

	int size() const;

	bool reallocate();
	bool push_back(const T &element);
	bool search(const T &element) const;

	T& back();
	T& get(const int index);

	T& operator[](const int index);

	void display() const;
};



//CONSTRUCTORS AND DESTRUCTORS

template <class T>
Vector<T>::Vector(int vectorSize, int vectorCapacity):
	Size{vectorSize}, Capacity{vectorCapacity} 
	{this->Elements = new T[this->Capacity];}


template <class T>
Vector<T>::Vector(const Vector &other_vector):
	Size{other_vector.Size}, Capacity{other_vector.Capacity} 

	{
		this->Elements = new T[other_vector.Capacity];

		for (int i = 0; i < other_vector.Size; i++){
			this->Elements[i] = other_vector.Elements[i];
		}
	}


template <class T>
Vector<T>::Vector(Vector &&other_vector):
	Size{other_vector.Size}, Capacity{other_vector.Capacity}
{
	delete[] this->Elements;
	this->Elements = other_vector.Elements;

	other_vector.Elements = nullptr;
	other_vector.Size = 0;
	other_vector.Capacity = 0;
}


template <class T>
Vector<T>::~Vector(){
	delete[] this->Elements;
	this->Size = 0;
	this->Capacity = 0;
}



//OTHER FUNCTIONS
template <class T>
T& Vector<T>::operator[](const int index) {return this->Elements[index];}

template <class T>
int Vector<T>::size() const {return this->Size;}

template <class T>
bool Vector<T>::reallocate(){
	T* buff = new T[this->Capacity *2]; //In case of error during memory allocation, 'new' has the ability to throw an error
												//Then this function stops, stack unwinding
	this->Capacity *= 2;

	for (int i = 0; i < this->Size; i++){
		buff[i] = this->Elements[i];
	}

	delete[] this->Elements;
	this->Elements = buff;
	buff = nullptr;

	return true;
}


template <class T>
bool Vector<T>::push_back(const T &element){

	if (this->Size < this->Capacity){
		
		this->Elements[this->Size] = element;
		this->Size++;
		return true;
	}

	try{
		this->reallocate();
		this->Elements[this->Size] = element;
		this->Size++;
		return true;
	}
	catch(const std::bad_alloc &bad_alloc){
		std::cerr << "Error: Could not add this product" << std::endl;
		return false;
	}
}


template <class T>
bool Vector<T>::search(const T &element) const{

	for (int i = 0; i < this->size(); i++){
		
		if(this->Elements[i].getName() == element.getName() ){
			return true;
		}

	}

	std::cout << "Could not find the following product: " << element.getName() << std::endl;
	return false;
}


template <class T>
T& Vector<T>::back() {return this->Elements[this->Size];}



template <class T>
T& Vector<T>::get(const int index) {return this->Elements[index];}



template <class T>
void Vector<T>::display() const{

	if (this->size() == 0){
		std::cout << "Empty list" << std::endl;
		return;
	}

	for (int i = 0; i < this->size(); i++){
		this->Elements[i].display();
	}
}


#endif