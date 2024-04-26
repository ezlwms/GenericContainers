#pragma once
#include <string>

/*
 A box is a generic container that holds a single data item. The typename variable
 T specifies the type of data contained in the box.
 */
template <typename T>
class Box {
protected:

    /*
     The data held by this box
     */
    T data;

public:

    /*
     Creates a box. The data field is uninitialized.
     */
    Box();

    /*
     Creates a box containing the specified data.
     */
    Box(T data);

    /*
     Returns the data held by this box.
     */
    T getData() const;

    //Copy constructor creates an independent copy of the input reference   
    Box(const Box<T>& aBox);

    //class destructor 
    ~Box();

    /*
     Stores the specified data in this box. Any data previously
     stored in this box is overwritten.
     */
    void setData(T data);

    //two boxes are considered equal if their data attributes are equal
    bool operator==(const Box<T>& another);

    //two boxes are not equal if their data attributes are not equal 
    bool operator!=(const Box<T>& another);

    /*
     Returns a string representation of this box.
     */
    std::string toString() const;
};

template  <typename T>
//overload stream insertion
std::ostream& operator<<(std::ostream& outStream, const Box<T>& b);
