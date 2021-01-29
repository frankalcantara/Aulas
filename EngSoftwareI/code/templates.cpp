/**
 * @file templates.cpp
 * @author Frank de Alcantara
 * @brief Exemplo, o mais simples possível, de uso de templates em C++
 * @version 0.1
 * @date 2021-01-29
 *
 *
 */
#include <iostream> 
using namespace std;

/**
 * @brief Usamos templates para criar método que permitem a definição de tipos diferentes.
 *
 * @param x - tipo a ser definido
 * @param y - tipo a ser definido
 * @return template <typename Tipo>
 */

template <typename Tipo> Tipo maior(Tipo x, Tipo y) {
//quando usarmos templates o operador > sempre sofrerá sobrecarga.
    return (x > y) ? x : y;
}

int main() {
    //chamando maior para o tipo int.
    cout << maior<int>(13, 27) << endl;
    //chamando maior para o tipo double.
    cout << maior<double>(13.0, 27.3) << endl;
    //chamando maior para o tipo char.
    cout << maior<char>('g', 'e') << endl;

    return 0;
} //fim do main