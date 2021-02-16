/**
 * @file embaralha.cpp
 * @author Frank de Alcantara
 * @brief  Algoritmo de embaralhamento (Fisher–Yates shuffle)
 * @version 0.1
 * @date 2021-02-16
 */

#include <iostream>
#include <chrono>
using namespace std;

//Protótipos
void embaralha(int[], int);
void troca(int*, int*);
void display(int[], int);

int main() {
    //define um conjunto de inteiros ordenados
    int conjunto[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(conjunto) / sizeof(arr[0]);
    embaralha(conjunto, n);
    display(conjunto, n);

    return 0;
} //fim do main  

/**
 * @brief Troca dos inteiros usando os ponteiros para estes inteiros
 *
 * @param a
 * @param b
 */
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief função para mostar no terminal um conjunto de inteiros
 *
 * @param conjunto
 * @param comprimento
 */
void display(int conjunto[], int comprimento) {
    for (int i = 0; i < comprimento; i++)
        cout << conjunto[i] << " ";
    cout << "\n";
}

/**
 * @brief A função de embaralhamento
 *
 * @param conjunto
 * @param comprimento
 */
void embaralha(int conjunto[], int comprimento) {
   //gerar randomico 
    srand((unsigned)time(0)); //typecast evite isso

    for (int i = comprimento - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&arr[i], &arr[j]);
    }
}
