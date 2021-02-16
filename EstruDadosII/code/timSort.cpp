/**
 * @file timSort.cpp
 * @author Frank de Alcantara
 * @brief Impementação do Tim Sort
 * @version 0.1
 * @date 2020-09-01
 */

#include<iostream>
#include <chrono>  
using namespace std;
//há um limite para o tamanho do array ser uma potência de 2 múltipla de 32
#define TAMANHO_CONJUNTO 500

//protótipos
//só para mostrar o conjunto
void display(int[], int);
//só para imprimir o conjunto
void criaConjunto(int[], int, int);
//módulos de ordenação
void insertionSort(int[], int, int);
void merge(int[], int, int, int, int);
void timSort(int[], int, int);

int main() {

    const int tamanho = TAMANHO_CONJUNTO;    //determinar o tamanho do conjunto
    const int run = 32;                     //número de passagens
    const int tamanhoRandon = 1000; //tamanho do random

    //ponteiro para a criação do conjunto dinâmico
    int* conjunto = NULL;
    //gerando o conjunto dinâmico
    conjunto = new int[tamanho];

    //preencher o conjunto com número randômicos
    criaConjunto(conjunto, tamanho, tamanhoRandon);

    cout << "\nNão ordenado: \n";
    display(conjunto, tamanho);

    //variáveis usadas para medir o tempo de execução
    clock_t  clock1, clock2;

    clock1 = clock(); //registra o tempo
    //ordenamento
    timSort(conjunto, tamanho, run);

    cout << "\nOrdenado: \n";
    display(conjunto, tamanho);

    clock2 = clock(); //registra o tempo

    // Apenas imprime o tempo.
    cout << "\n\nTempo gasto " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;

    //trabalhando com o conjunto dinâmicos
    delete[] conjunto;  // remover da memória.
    conjunto = NULL;  //limpar a memória

    return 0;
}

//função para criar um conjunto de randomicos 
void criaConjunto(int conjunto[], int tamanho, int tamanhoRandon) {
    srand((unsigned)clock()); //semente para o gerador de randômicos
   // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < tamanho; i++) {
        conjunto[i] = (rand() % tamanhoRandon) + 1;
    }
}

// mostrar o conjunto de inteiros 
// não imprime ser o conjunto for maior que 30 itens
void display(int conjunto[], int size) {
    if (size <= 30) {
        for (int i = 0; i < size; i++)
            cout << conjunto[i] << " ";
        cout << "\n\n";
    }
    else {
        cout << "O conjunto não faz sentido no terminal." << endl;
    }
}

/**
 * @brief implementa o Insertion Sort
 *
 * @param conjunto - inteiros que serão ordenados
 * @param esquerda
 * @param direita
 */
void insertionSort(int conjunto[], int esquerda, int direita) {
    for (int i = esquerda + 1; i <= direita; i++) {
        int temp = conjunto[i];
        int j = i - 1;
        while (conjunto[j] > temp && j >= esquerda) {
            conjunto[j + 1] = conjunto[j];
            j--;
        }
        conjunto[j + 1] = temp;
    }
}

/**
 * @brief implementa o Merge Sort
 *
 * @param conjunto
 * @param l
 * @param m
 * @param r
 */
void merge(int conjunto[], int l, int m, int r) {
    //dividimos o array orginal em dois esquerda (l) e direita (r)
    //dois arrays novos serão criados
    //este é a tarefa de função partição na nossa implementação
    int len1 = m - l + 1, len2 = r - m;

    int* esquerda = new int[len1];
    int* direita = new int[len2];

    for (int i = 0; i < len1; i++)
        esquerda[i] = conjunto[l + i];
    for (int i = 0; i < len2; i++)
        direita[i] = conjunto[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    //agora vamos comparar e fazer o merge dos dois arrays
    while (i < len1 && j < len2) {
        if (esquerda[i] <= direita[j]) {
            conjunto[k] = esquerda[i];
            i++;
        }
        else {
            conjunto[k] = direita[j];
            j++;
        }
        k++;
    }

    // copia o que tiver sobrado em l 
    while (i < len1) {
        conjunto[k] = esquerda[i];
        k++;
        i++;
    }

    // copia o que tiver sobrado em r 
    while (j < len2) {
        conjunto[k] = direita[j];
        k++;
        j++;
    }

    delete[] esquerda;  // remover da memória.
    esquerda = NULL;  //limpar a memória
    delete[] direita;  // remover da memória.
    direita = NULL;  //limpar a memória
}


//função interativa timSort

void timSort(int conjunto[], int n, int run)
{
    // ordena arrays individuais do tamanho n-1 
    for (int i = 0; i < n; i += run)
        insertionSort(arr, i, min((i + 31), (n - 1)));

    // começa o merge a partir do tamanho RUN (32). 
    // formando arrays de tamanho 64, then 128, 256 and so on .... 
    for (int size = run; size < n; size = 2 * size) {
        // escolhe um ponto de início no subarray L. We 
        // vamos fazer o merge entre os subarrays[esquerda..esquerda+size-1] 
        // e os arrays[esquerda+size, esquerda+2*size-1] 
        // depois de cada merge mudamos a posição de esquerda por 2*size 
        for (int esquerda = 0; esquerda < n; esquerda += 2 * size) {
            // encontra o ponto final do array esquerda 
            // mid+1 é o ponto inicial do array direita  
            int mid = esquerda + size - 1;
            int direita = min((esquerda + 2 * size - 1), (n - 1));

            // merge subarray[esquerda.....mid] com conjunto[mid+1....direita] 
            merge(arr, esquerda, mid, direita);
        }
    }
}

