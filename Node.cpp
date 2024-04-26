#include <sstream>
#include <iostream>
#include "Node.h"

template <typename T>
Node<T>::Node() {
    this->nextNode = nullptr;
};

template <typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->nextNode = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node<T>* nextNode) {
    this->data = data;
    this->nextNode = nextNode;
}

//copy constructor 
template <typename T>
Node<T>::Node(const Node<T>& another) {
  //  std::cout << "Node copy constructor here." << std::endl;
    this->data = another.data;
    this->nextNode = another.nextNode;
}

//class destructor
template <typename T>
Node<T>::~Node() {
    //std::cout << "Node destructor here: " << std::endl;
}

template <typename T>
Node<T>* Node<T>::getNextNode() const{
    return this->nextNode;
}

template <typename T>
bool Node<T>::operator==(const Node<T>& another) {
    return (this->data == another.data && this->nextNode == another.nextNode);
}


template <typename T>
void Node<T>::setNextNode(Node* next) {
    this->nextNode = next;
}

template <typename T>
std::string Node<T>::toString() const {
    std::ostringstream sout;
    sout << "Node at " << this << std::endl;
    sout << " storing " << sizeof(T) << " bytes of data at " << &(this->data) << std::endl;
    return sout.str();
}

template  <typename T>
std::ostream& operator<<(std::ostream& outStream, const Node<T>& n) {
    outStream << n.toString();
    return outStream;
}
