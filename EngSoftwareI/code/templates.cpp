#include <iostream> 
using namespace std;

// One function works for all data types.  This would work 
// even for user defined types if operator '>' is overloaded 
template <typename Tipo> Tipo maior(Tipo x, Tipo y) {
    return (x > y) ? x : y;
}

int main()
{
    cout << maior<int>(3, 7) << endl;  // Call maior for int 
    cout << maior<double>(3.0, 7.0) << endl; // call maior for double 
    cout << maior<char>('g', 'e') << endl;   // call maior for char 

    return 0;
}