#include <sstream>
#include <iostream>

#include "Stack.h"


//implement default constructor 
template <typename T> 
Stack<T>::Stack() {
	this->top = nullptr;
}

//copy constructor 
template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
	this->top = nullptr;
	if (s.top != nullptr) {
		this->top = new Node<T>(*s.top); //calls Node<T> copy constructor 
		Node<T>* currCopyNode = this->top;
		Node<T>* currOrigNode = s.top;
		while (currOrigNode->getNextNode() != nullptr) {
			Node<T>* nextCopyNode = new Node<T>(*(currOrigNode->getNextNode()));
			currCopyNode->setNextNode(nextCopyNode);
			currCopyNode = nextCopyNode;
			currOrigNode = currOrigNode->getNextNode();
		}
	}
}

//destructor
template <typename T>
Stack<T>::~Stack() {
	std::cout << "~Stack() here:" << std::endl;
	Node<T>* currNode = this->top;
	int cnt = 0;
	while (currNode != nullptr) {
		Node<T>* nextNode = currNode->getNextNode();
		delete currNode;
		currNode = nextNode;
		cnt++;
	}
	std::cout << cnt << " items deleted." << std::endl;
}

//implememnt is empty
template <typename T>
bool Stack<T>::isEmpty() const{
	return this->top == nullptr;
}

//implement get size
template <typename T> 
int Stack<T>::getSize() const{
	if (this->top == nullptr) {
		return 0;
	}
	else {
		Node<T>* currentNode = this->top;
		int count = 1;
		while (currentNode->getNextNode() != nullptr) {
			count++;
			currentNode = currentNode->getNextNode();
		}
		return count;
	}
}

// implementation of the push function 
template <typename T>
void Stack<T>::push(T data) {
	if (this->isEmpty()) {
		//creates top node, store data in it 
		this->top = new Node<T>(data);
	}
	else {
		//create a node, put data in it. The new node's 
		//next node pointer should point to current top of the stack
		// Then we set the top to point to the new node 
		Node<T>* newTop = new Node<T>(data);
		newTop->setNextNode(this->top);
		this->top = newTop;
	}
}

//implememnt top()
template <typename T>
T Stack<T>::pop() {
	if (this->isEmpty()) {
		//error situation
		throw std::runtime_error("Cannot pop from an empty stack");
	}
	else if (this->getSize() == 1) {
		//grab data off the top. then set top = nullptr
		T result = this->top->getData();
		this->top = nullptr;
		return result;
	}
	else {
		//grab data off the top, then set top to point to 
		// top->getNextNode()
		T result = this->top->getData();
		this->top = this->top->getNextNode();
		return result;
	}
}

//implement peek()
// returns the data item at the top of the stack but doesn't remove it
template <typename T> 
T Stack<T> ::peek() const {
	if (this->isEmpty()) {
		throw std::runtime_error("Cannot Peak into an empty stack");
	}
	else {
		//Grabs data off top and doesnt remove it 
		T peekResult = this->top->getData(); 
			return peekResult;
	}
}

//implement toString()
// returns a string representation of this stack
template <typename T>
std::string Stack<T>::toString() const {
	std::ostringstream sout;
	sout << "Stack at " << this << std::endl;
	sout << "This stack is currently storing " << getSize() << " items." << std::endl;
	sout << "Each item on this stack occupies " << sizeof(T) << " bytes of storage." << std::endl;
	return sout.str();
}

template  <typename T>
std::ostream& operator<<(std::ostream& outStream, const Stack<T>& s) {
	outStream << s.toString();
	return outStream;
}
