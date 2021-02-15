/**
 * @file Mergesort.cpp
 * @author Frank de Alcantara
 * @brief Programa de demonstração do Merge Sort em C++ para um conjunto de inteiros.
 * @version 0.1
 * @date 2020-07-17
 *
 *
 */
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

//protótipos de funções
/**
 * @brief função apenas para mostar o conjunto ordenado.
 *
 */
void display(int*, string);
void merge(int*, int, int, int);
void merge_sort(int*, int, int);

/**
 * @brief Lembre-se que o LIMITE é o número de itens no conjunto
 * que será ordenado. Um número grande inviabiliza a impressão
 * na tela do terminal.
 *
 */
#define LIMITE 15 

int main() {
    //iniciando um gerador de números randômicos
    srand((unsigned)time(0));
    //array para criar o conjunto de testes
    int array_teste[LIMITE];

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < LIMITE; i++) {
        array_teste[i] = (rand() % 100) + 1;
    }

    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;

    display(array_teste, "\nNão ordenado:\n");

    clock1 = clock();
    merge_sort(array_teste, 0, LIMITE - 1);
    clock2 = clock();

    display(array_teste, "\nOrdenado:\n");

    cout << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;

} //fim do main

//funções implementação
void merge_sort(int* arr, int baixo, int alto) {

    if (baixo < alto) {
        int meio;
        meio = (baixo + alto) / 2; //automático typecasting evite isso....
        //dividiu o array em dois, usando os limites passados
        //para identificar o array inferior e o superio
        merge_sort(arr, baixo, meio);
        merge_sort(arr, meio + 1, alto);
        // juntando os arrays já ordenados.
        merge(arr, alto, baixo, meio);
    }
}

void merge(int* arr, int alto, int baixo, int meio)
{
    int temp[200000], i, j, k;
    i = baixo;
    k = baixo; //array final
    j = meio + 1;

    while (i <= meio && j <= alto) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
        } // fim do if
    }// fim while

    while (i <= meio) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= alto) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = baixo; i < k; i++) {
        arr[i] = temp[i];
    }
}

void display(int m[LIMITE], string s) {
    cout << s << endl;

    for (int i = 0; i < LIMITE; i++) {
        cout << m[i] << "\t";
    }

    cout << endl;
}