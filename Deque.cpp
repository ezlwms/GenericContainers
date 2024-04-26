#include <sstream>

#include "Deque.h"


template <typename T>
//constructor 
Deque<T>::Deque() {
	lst = new List<T>();
}

//Returns a string representation of deque.
template<typename T>
std::string Deque<T>::toString() {
	std::ostringstream sout;
	sout << "Deque at " << this << std::endl;
	sout << "This Deque stores items of size " << sizeof(T) << std::endl;
	sout << "This Deque contains " << getSize() << " items" << std::endl;
	return sout.str();
}

//Adds the specified data to the front of the deque.
template<typename T>
void Deque<T>::enqueueFront(T data) {
	return lst->insertBefore(0, data);
}

//Removes and returns the data at the front of the deque.
template <typename T>
T Deque<T>::dequeueFront() {
	return lst->remove(0);
}

//Returns true if and only if this deque is empty.
template <typename T>
bool Deque<T>::isEmpty() {
	return lst->isEmpty();
}

//Returns the number of items in the deque.
template <typename T>
int Deque<T>::getSize() {
	return lst->getSize();
}

//Adds the specified data to the back of the deque.
template <typename T>
void Deque<T>::enqueueBack(T data) {
	return lst->addAtEnd(data);
}

//Removes and returns the data at the back of the deque.
template <typename T>
T Deque<T>::dequeueBack() {
	return lst->remove(lst->getSize()-1);
}

//Returns the data at the front of the deque, but does not remove it.
template <typename T>
T Deque<T>::peekAtFront() {
	return lst->peek(0);
}

//Returns the data at the back of the deque, but does not remove it.
template <typename T>
T Deque<T>::peekAtBack() {
	return lst->peek(lst->getSize()-1);
}