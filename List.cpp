#include <sstream>
#include <iostream>

#include "List.h"

template <typename T>
//constructor 
List<T>::List(T data) {
	mainStack = new Stack<T>();
	auxStack = new Stack<T>();
	this->mainStack->push(data);
}

//Returns the number of items on list
template <typename T>
int List<T>::getSize() const{
	//calls get size function from the mainStack
	return mainStack->getSize();
}

template<typename T>
List<T>::List()
{
	mainStack = new Stack<T>();
	auxStack = new Stack<T>();
}


//copy constructor 
template <typename T>
List<T>::List(const List<T>& l) {
	this->mainStack = new Stack<T>(*(l.mainStack));
	this->auxStack = new Stack<T>(*(l.auxStack));
}


//destructor 
template <typename T>
List<T>::~List() {
	std::cout << "~List Here..." << std::endl;
	std::cout << " deleting mainStack..." << std::endl;
	delete mainStack;
	std::cout << " deleting auxStack..." << std::endl;
	delete auxStack;
}

//returns true if list contains no items
template <typename T>
bool List<T>::isEmpty() const{
	//calls isEmpty function from the mainStack
	return mainStack->isEmpty();
}

//Returns a string representation of the list: memory address, bytes, and size
template <typename T>
std::string List<T>::toString() const {
	std::ostringstream sout;
	sout << "List at " << this << std::endl;
	sout << "This list stores items of size " << sizeof(T) << std::endl;
	sout << "This list contains " << getSize() << " items" <<  std::endl;
	return sout.str();
}

//Adds specified data to the bottom of list
template <typename T>
void List<T>::addAtEnd(T data) {
	//pushes the data onto the main mainstack
	 mainStack->push(data);
}

template <typename T>
T List<T>::peek(int ndx) const{
	//makes sure that the stack has values to peek at
	if (this->isEmpty()) {
		throw std::runtime_error("Cannot Peak into an empty list");
	}
	// gets numbers of iterations to pop off of the mainStack
	int Size = this->getSize() - ndx;
	//loop to pop data off of the mainStack  onto the auxStack 
	for (int k = 0; k < Size; k++) {
		auxStack->push(mainStack->pop());
	}
	//assigns top value of stack to the PeekValue variable
	T PeekValue = auxStack->peek();
	//Puts data stored on auxStack back onto the mainStack
	for (int k = 0; k < Size; k++) {
		mainStack->push(auxStack->pop());
	}
	//Returns the value of the specificed index
	return PeekValue;
}

//Inserts  specified data before  specified index in  list
template <typename T>
void List<T>::insertBefore(int ndx, T data) {
	// gets numbers of iterations to pop off of the mainStack
	int Size = this->getSize() - ndx;
	//	//loop to pop data off of the mainStack onto the auxStack 
	for (int k = 0; k < Size; k++) {
		auxStack->push(mainStack->pop());
	}
	//pushes the data onto the  mainstack
	mainStack->push(data);
	//Puts data stored on auxStack back onto the mainStack
	for (int k = 0; k < Size; k++) {
		mainStack->push(auxStack->pop());
	}
}
//Returns  data value at specified index, and removes that item from list
template <typename T>
T List<T>::remove(int ndx) {
	// gets numbers of iterations to pop off of the mainStack
	int Size = this->getSize() - ndx;
	//	//loop to pop data off of the mainStack onto the auxStack 
	for (int k = 0; k < Size; k++) {
		auxStack->push(mainStack->pop());
	}
	//pops the data off the auxStack
	T Removal = auxStack->pop();

	//Puts data stored on auxStack back onto the mainStack
	for (int k = 0; k < Size-1; k++) {
		mainStack->push(auxStack->pop());
	}
	return Removal;
}

//Joins the specified list to the end of this one.
template <typename T>
void List<T>::joinBefore(List<T>* suffix) {
	for (int k = 0; k < suffix->getSize(); k++) {
		this->mainStack->push(suffix->peek(k));
	}
}

//Splits  list so that it no longer contains any items with specified index or higher.The returned list contains the removed items
template <typename T>
List<T>* List<T>::splitBefore(int ndx) {
	// gets numbers of iterations to pop off of the mainStack
	int Size = getSize() - ndx;
	//loop to pop data off of the MainStack  onto the SplitSTack 
	List<T>* result = new List<T>();
	for (int k = 0; k < Size; k++) {
		T tempData = mainStack->pop();
		result->insertBefore(0, tempData);
	}
	return result;
}

template  <typename T>
std::ostream& operator<<(std::ostream& outStream, const List<T>& l) {
	outStream << l.toString();
	return outStream;
}
