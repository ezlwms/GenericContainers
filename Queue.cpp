#include <sstream>

#include "Queue.h"

template <typename T>
//constructor 
Queue<T>::Queue(){
	lst = new List<T>();
}

//Returns a string representation of  queue.
template<typename T>
std::string Queue<T>::toString() {
	std::ostringstream sout;
	sout << "Queue at " << this << std::endl;
	sout << "This Queue stores items of size " << sizeof(T) << std::endl;
	sout << "This Queue contains " << getSize() << " items" << std::endl;
	return sout.str();
}

//Adds the specified data to back of queue.
template<typename T>
void Queue<T>::enqueue(T data) {
	return lst->addAtEnd(data);
}

//Removes and returns the data at front of queue.
template<typename T>
T Queue<T>::dequeue() {
	return lst->remove(0);
}

//Returns true if and only if this queue is empty.
template <typename T>
bool Queue<T>::isEmpty() {
	return lst->isEmpty();
}

//Returns the number of items in the queue.
template <typename T>
int Queue<T>::getSize() {
	return lst->getSize();
}

//Returns the data at the front of the queue, but does not remove it.
template <typename T>
T Queue<T>::peekAtFront() {
	return lst->peek(0);
}