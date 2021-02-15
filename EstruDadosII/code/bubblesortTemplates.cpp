/**
 * @file bubblesortTemplates.cpp
 * @author Frank de Alcantara
 * @brief  O Bubble Sort usando templates do C++
 * @version 0.1
 * @date 2020-08-01
 *
 */
#include <iostream>
using namespace std;

// A template function to implement bubble sort. 
// We can use this for any data type that supports 
// comparison operator < and swap works for it. 
template <class T>
void bubbleSort(T conjunto[], int comprimento) {
    for (int i = 0; i < comprimento - 1; i++)
        for (int j = comprimento - 1; i < j; j--)
            if (conjunto[j] < conjunto[j - 1])
                swap(conjunto[j], conjunto[j - 1]);
}

//apenas para testes
int main() {

    int conjunto[5] = { 10, 50, 30, 40, 20 }; // conjunto de inteiros
    char letras[10] = { 'z', 'g', 'a', 'p', 'u' }; // conjunto de char
    int comprimento = sizeof(conjunto) / sizeof(conjunto[0]);

    //para ordenar inteiros
    bubbleSort<int>(conjunto, comprimento);

    cout << "Conjunto de inteiros ordenado: ";
    for (int i = 0; i < comprimento; i++)
        cout << conjunto[i] << " ";
    cout << endl;

    //para ordenar char
    bubbleSort<char>(letras, 5);

    cout << "Conjunto de letras ordenado: ";
    for (int i = 0; i < 5; i++)
        cout << letras[i] << " ";
    cout << endl;



    return 0;
}//fim do main

/**
 * @brief Você deve modificar este código para ordenar doubles
 *
 */