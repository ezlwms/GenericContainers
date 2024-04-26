#pragma once

#include "Stack.h"

/*
 A list is a container that holds data items of the same type. Data items are
 indexed from 0, with index 0 corresponding to the first item in the list.
 Data can be accessed, added, or removed from any position in the list. Lists
 can be joined and split.
 */
template <typename T>
class List {

protected:

    /*
    The main stack holds the list elements. The top of the stack corresponds
    to the last item on the list.
    */
    Stack<T>* mainStack;

     /*
     The auxilliary stack is used to temporarily hold items while list
     processing is being done.
     */
    Stack<T>* auxStack;


public:

    /*
     Creates an empty list.
     */
    List();

    /*

    */
    List(T data);


    //copy constructor
    List(const List<T>& l);


    //destructor

    ~List();
    /*
     Returns true if and only if this list contains no items.
     */
    bool isEmpty() const;

    /*
     Returns the number of items on this list.
     */
    int getSize() const;

    /*
     Adds the specified data to the bottom of this list.
     */
    void addAtEnd(T data);

    /*
     Inserts the specified data before the specified index in this list.
     */
    void insertBefore(int ndx, T data);

    /*
     Returns the data value at the specified index, but does not remove that
     item from this list.
     */
    T peek(int ndx) const;

    /*
     Returns the data value at the specified index, and removes that item from
     this list.
     */
    T remove(int ndx);

    /*
     Joins the specified list to the end of this one.
     */
    void joinBefore(List<T>* suffix);

    /*
     Splits this list so that it no longer contains any items with the
     specified index or higher. The returned list contains the removed
     items.
     */
    List <T>* splitBefore(int ndx);

    /*
     Returns a string representation of this list.
     */
    std::string toString() const;
};

template  <typename T>
//overload stream insertion
std::ostream& operator<<(std::ostream& outStream, const List<T>& l);

