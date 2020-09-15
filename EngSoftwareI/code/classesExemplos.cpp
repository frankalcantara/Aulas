
//com ponteiros
/*
*x     can be read:  valor pointed by x
&x     can be read:  address of x
x.y    can be read:  member y of object x
(*x).y can be read:  member y of object pointed by x
x->y   can be read:  member y of object pointed by x (equivalent to the previous one)
x[0]   can be read:  first object pointed by x
x[1]   can be read:  second object pointed by x
x[n]   can be read:  (n+1)th object pointed by x
*/


/*
It is best to avoid using pointers in C++ as much as possible.
The use of pointers can lead to confusion of ownership which can directly or indirectly lead to memory leaks.
Even if object ownership is well managed simple (and difficult to find) bugs can also lead to memory leaks.
(https://articles.emptycrate.com/2009/01/02/nobody_understands_c_part_6_are_you_still_using_pointers.html)
*/

// pointer to classes example
#include <iostream>
using namespace std;

class CRectangle {
    int width, height;
public:
    void set_values(int, int);
    int area(void) { return (width * height); }
};

void CRectangle::set_values(int a, int b) {
    width = a;
    height = b;
}

int main() {
    CRectangle a, * b, * c;
    CRectangle* d = new CRectangle[2];
    b = new CRectangle;
    c = &a;
    a.set_values(1, 2);
    b->set_values(3, 4);
    d->set_values(5, 6);
    d[1].set_values(7, 8);
    cout << "a area: " << a.area() << endl;
    cout << "*b area: " << b->area() << endl;
    cout << "*c area: " << c->area() << endl;
    cout << "d[0] area: " << d[0].area() << endl;
    cout << "d[1] area: " << d[1].area() << endl;
    return 0;
}