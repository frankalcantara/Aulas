/**
 * @file bubblesortTemplates.cpp
 * @author Desconhecido 
 * @brief Apresenta o uso de templates (programação genérica) em C++
 * @version 0.1
 * @date 2020-07-10
 * @mod Frank de Alcantara
 * 
 * 
 */
#include <iostream>
using namespace std;

/**
 * @brief implementação da função de uma função de ordenação
 *          (bubble sort) em c++ usando tempates
 * 
 * @param conj - array de inteiros 
 * @param comp - comprimento do array
 * @return template <class T> 
 */
template <class T>
void bubbleSort(T conj[], int comp) {
    for (int i = 0; i < comp - 1; i++)
        for (int j = comp - 1; i < j; j--)
            if (conj[j] < conj[j - 1])
                swap(conj[j], conj[j - 1]);
}

int main() {
    //definindo um array de inteiros
    int a[5] = { 10, 50, 30, 40, 20 };
    //calculando o comprimento deste array
    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort<int>(a, 5);

    cout << "Array Ordenado:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}//fim do main

/**
 * @brief Tente criar um programa para array de doubles.
 * 
 */