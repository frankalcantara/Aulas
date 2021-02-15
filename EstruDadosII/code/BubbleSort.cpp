/**
 * @file BubbleSort.cpp
 * @author Frank de Alcantara
 * @brief Bubble Sort. Apenas para demonstração, evite usar este algoritmo.
 * @version 0.1
 * @date 2020-07-31
 *
 */

#include <iostream>
#include <ctime>

using namespace std; // usando a biblioteca padrão

int main() {

    //iniciando o gerador randômicos
    srand((unsigned)time(0));

    int tam = 10, passo = 0;
    int conjunto[10];

    //preenchendo o conjunto com números randômicos.
    for (int i = 0; i < tam; i++) {
        conjunto[i] = (rand() % 1000) + 1;
    }

    //imprime a lista criada que será ordenada
    cout << "\n\nLista original: {";
    for (int k = 0; k < tam; k++) {
        cout << conjunto[k] << ",";
    }
    cout << "}" << endl;

    /**
     * @brief O algoritmo Bubble Sort.
     *
     */
    int temp = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (conjunto[j] < conjunto[i]) {
                temp = conjunto[i];
                conjunto[i] = conjunto[j];
                conjunto[j] = temp;
            }
        }
        passo++;
    }

    //imprimindo a lista ordenada
    cout << "\n\nLista ordenada: {";
    for (int k = 0; k < tam; k++) {
        cout << conjunto[k] << ",";
    }
    //imprimindo o total de passos
    cout << "\nPassos: " << passo << endl;
}//fim do main