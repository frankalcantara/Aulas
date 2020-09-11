#include <iostream>
#include <chrono> 

using namespace std;

//gerando números randõmicos usando os números da microsoft 
class GeradorLinear {
public:
    int _a = 214013, _c = 2531011;
    unsigned int _m = 2147483648, _seed;

    void seed(unsigned int s) {
        _seed = s;
    }

    int rnd() {
        //o shift a direita de 16bits é equivalente a dividir por 16 só que muito mais rápido
        return (_seed = (_a * _seed + _c) % _m) >> 16;
    }
    //constructor
    GeradorLinear() { seed(0); }


};


int main() {
    GeradorLinear aleatorio;
    aleatorio.seed((unsigned)clock());
    cout << "Gerados:" << endl;
    for (int x = 0; x < 30; x++)
        cout << aleatorio.rnd() << endl;

    return 0;
}