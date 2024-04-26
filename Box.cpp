#include <sstream>
#include <iostream>

#include "Box.h"

template <typename T>
Box<T>::Box() {}

template  <typename T>
Box<T>::Box(T data) { this->data = data; }

//copy constructor 
template <typename T>
Box<T>::Box(const Box<T>& aBox) {
   // std::cout << "Box copy constructor here:" << std::endl;
    this->data = aBox.data;
}

//class destructor 
template <typename T>
Box<T>::~Box() {
  //  std::cout << "Box Destructor Here" << std::endl;
}

template  <typename T>
T Box<T>::getData() const { return this->data; }

template  <typename T>
void Box<T>::setData(T data) { this->data = data; }

template <typename T>
bool Box<T>::operator==(const Box<T>& another)
{
    std::cout << "Box<T>::operator here" << std::endl;
    return(this->data == another.data);
}

template <typename T>
bool Box<T>::operator!=(const Box<T>& another)
{
    return !(*this == another);
}

template  <typename T>
std::string Box<T>::toString() const {
    std::ostringstream sout;
    sout << "Box at " << this << std::endl;
    sout << " storing data of size " << sizeof(T) << " bytes." << std::endl;
    return sout.str();
}

template  <typename T>
std::ostream& operator<<(std::ostream& outStream, const Box<T>& b) {
    outStream << b.toString();
    return outStream;
}
