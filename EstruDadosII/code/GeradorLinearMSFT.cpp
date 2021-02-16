/**
 * @file GeradorLinearMSFT.cpp
 * @author Frank de Alcantara
 * @brief Gerador de randômicos, linear congruente usando os números da Microsoft
 * @version 0.1
 * @date 2021-02-16
 */

#include <iostream>
#include <chrono> 
using namespace std;

#define QUANTIDADE 30

/**
 * @brief Classe para criar o gerador linear congruente
 * Os números utilizados são os números propostos pela Microsoft
 */
class GeradorLinear {
public:
    int _a = 214013, _c = 2531011;
    unsigned int _m = 2147483648, _seed;

    //determina a semente.
    void seed(unsigned int s) {
        _seed = s;
    }
    // gera o número randômico
    int rnd() {
        //o shift a direita de 16bits é equivalente a dividir por 16 só que muito mais rápidob
        return (_seed = (_a * _seed + _c) % _m) >> 16;
    }
    //constructor
    GeradorLinear() { seed(0); }
};

int main() {
    //cria o objeto
    GeradorLinear aleatorio;
    //determina a semente
    aleatorio.seed((unsigned)clock());

    cout << "Gerados:" << endl;
    for (int i = 0; i < QUANTIDADE; i++)
        cout << aleatorio.rnd() << endl;

    return 0;
} //fim do main