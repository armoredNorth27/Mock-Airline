
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template<class T>
class Array{

	template<class V>
	friend ostream& operator<<(ostream&, const Array<V>&);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		T operator[](int);
		T operator[](int) const;
		int getSize() const;
		bool isFull() const;
	
	private:
		int size;
		T* elements;
	
};

//==============================================//
//				   Constructors  				//
//==============================================//

template<class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template<class T>
Array<T>::~Array(){
	delete [] elements;
}

//==============================================//
//				 Member Functions  				//
//==============================================//

// Add an element to the array
template<class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR) return;
  	elements[size++] = t;
}

// Return the size of the array
template<class T>
int Array<T>::getSize() const{
	return size;
}

// Return true if array is full
// Return false otherwise
template<class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}

template<class T>
T Array<T>::operator[](int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}

	return elements[index];
}

template<class T>
T Array<T>::operator[](int index) const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}

	return elements[index];
}

template<class T>
ostream& operator<<(ostream& ost, const Array<T>& arr){
	ost << endl;

	for(int i=0; i<arr.getSize(); i++){
		ost << arr.elements[i] << endl;
	}
	
	return ost;
}

#endif