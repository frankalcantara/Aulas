

// friend class a friend class is a class whose members have access to the private or protected members of another class:
//"Friendship" in C++ is commonly thought of as a means of allowing non-member functions and other classes to access the 
//private data of a class. This might be done to allow symmetric conversions on non-member comparison operators, or allow 
//a factory class exclusive access to the constructor of a class, or any number of things.
#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;
public:
    int area()
    {
        return (width * height);
    }
    void convert(Square a);
};

class Square {
    friend class Rectangle;
private:
    int side;
public:
    Square(int a) : side(a) {}
};

void Rectangle::convert(Square a) {
    width = a.side;
    height = a.side;
}

int main() {
    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area();
    return 0;
}