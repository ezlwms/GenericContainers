#include <sstream>

#include "Pair.h"

template <typename T, typename U>
Pair<T,U>::Pair() {}

template <typename T, typename U>
Pair<T,U>::Pair(T first, U second) {
	this->first = first;
	this->second = second;
}

template <typename T, typename U>
Pair<U, T> Pair<T, U>::swap() {
	return new Pair<U, T>(this->second, this->first);
}

template <typename T, typename U>
std::string Pair<T, U>::toString() {
	std::ostringstream sout;
	sout << "Pair at " << this << std::endl;
	sout << "First element stores " << sizeof(T) << " bytes of data." << std::endl;
	sout << "Second element stores " << sizeof(U) << " bytes of data." << std::endl;
	return sout.str();
}