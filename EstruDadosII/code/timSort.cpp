
// C++ program to perform TimSort. 
#include<iostream>
#include <chrono>  

using namespace std;

//protótipos
//só para mostrar o conjunto
void display(int[], int);
//só para imprimir o conjunto
void criaConjunto(int[], int, int);
//módulos de sort
void insertionSort(int[], int, int);
void merge(int[], int, int, int, int);
void timSort(int[], int, int);

int main() {

    const int tamanho = 32768;    //determinar o tamanho do conjunto
    const int run = 32;         //número de passagens
    const int tamanhoRandon = 1000; //tamanho do random

    //ponteiro para a criação do conjunto dinâmico
    int* conjunto = NULL;
    //gerando o conjunto dinâmico
    conjunto = new int[tamanho];

    //popula o conjunto com número randômicos
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
// não imprime ser o conjunto for maior que 20 itens
void display(int conjunto[], int size) {
    if (size > 20) return;
    //coloca na tela
    for (int i = 0; i < size; i++)
        cout << conjunto[i] << " ";
    cout << "\n\n";
}


// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= left) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// merge sort
void merge(int arr[], int l, int m, int r) {
    //dividimos o array orginal em dois esquerda (l) e direita (r)
    //dois arrays novos serão criados
    //este é a tarefa de função partição na nossa implementação
    int len1 = m - l + 1, len2 = r - m;

    int* left = new int[len1];
    int* right = new int[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    //agora vamos comparar e fazer o merge dos dois arrays
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copia o que tiver sobrado em l 
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    // copia o que tiver sobrado em r 
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }

    delete[] left;  // remover da memória.
    left = NULL;  //limpar a memória
    delete[] right;  // remover da memória.
    right = NULL;  //limpar a memória
}


//função interativa timSort
//há um limite para o tamanho do array ser uma potência de 2 múltipla de 32
void timSort(int arr[], int n, int run)
{
    // ordena arrays individuais do tamanho n-1 
    for (int i = 0; i < n; i += run)
        insertionSort(arr, i, min((i + 31), (n - 1)));

    // começa o merge a partir do tamanho RUN (32). 
    // formando arrays de tamanho 64, then 128, 256 and so on .... 
    for (int size = run; size < n; size = 2 * size) {
        // escolhe um ponto de início no subarray L. We 
        // vamos fazer o merge entre os subarrays[left..left+size-1] 
        // e os arrays[left+size, left+2*size-1] 
        // depois de cada merge mudamos a posição de Left por 2*size 
        for (int left = 0; left < n; left += 2 * size) {
            // encontra o ponto final do array left 
            // mid+1 é o ponto inicial do array right  
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            // merge subarray[left.....mid] com arr[mid+1....right] 
            merge(arr, left, mid, right);
        }
    }
}

