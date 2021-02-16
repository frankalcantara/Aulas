/**
 * @file MersenneTwistter.cpp
 * @author Frank de Alcantara
 * @brief Geração de números randômicos usando a biblioteca padrão do C++
 * @version 0.1
 * @date 2020-10-20
 */

#include <iostream>
#include <random>
using namespace std;

#define QUANTIDADE 16

int main() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 10000);
    for (int i = 0; i < QUANTIDADE; ++i) {
        cout << dist(mt) << " ";
    }
    cout << endl;
}
