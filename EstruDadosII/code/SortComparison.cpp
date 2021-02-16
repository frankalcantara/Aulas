/**
 * @file SortComparison.cpp
 * @author Frank de Alcantara
 * @brief Comparação simples entre os tempos de ordenação do Quick, Merge e Heap
 * @version 0.1
 * @date 2020-08-12
 */

#include <iostream>
#include <chrono>
#include <iomanip>      // std::setprecision
using namespace std;

/**
 * @brief vamos usar as funções desenvolvidas anteriormente 
 * com o mínimo de modificação possível.
 */
//prototipos
//heap
void heap_construir(int[], int, int);
void heap_ordenar(int[], int);
//merge
void merge(int*, int, int, int);
void merge_sort(int*, int, int);
//quick
void troca(int*, int*);
void quick_ordenar(int[], int, int, int);
int quick_particao(int[], int, int, int);

//função main vai rodar o algoritmo
int main() {
    int aval = 10; //número de avaliações, cada teste vai rodar o algoritmo aval vezes
    int num = 200000; //tamanho do conjunto de inteiros que será ordenado

    //ponteiros para a criação conjunto de testes usando array dinâmicos
    int* conjMerge = NULL;
    double* avalMerge = NULL;  //armazena os tempos de execução
    int* conjQuick = NULL;
    double* avalQuick = NULL;

    //inicialização dinámica duas formas diferentes, escolha uma
    int* conjHeap{ new int[num] {} };
    double* avalHeap{ new double[aval] {} };

    conjMerge = new int[num];
    conjQuick = new int[num];
    avalMerge = new double[aval];
    avalQuick = new double[aval];

    //para medir os tempos de execução.
    clock_t clock1, clock2;
    //gerar randomico 
    srand((unsigned)time(0)); //typecast evite isso

    //laço gigante avaliar os algoritmos. Vamos percorrer este laço aval vezes
    for (int i = 0; i < aval; i++) {

        //gerando o mesmo conjunto de aletórios em três endereços de
        //memória diferente. 
        for (int i = 0; i < num; i++) {
            int treco = (rand() % 100) + 1;
            conjHeap[i] = treco;
            conjMerge[i] = treco;
            conjQuick[i] = treco;
        }

        //Executando o heap sort
        //marcar tempo
        clock1 = clock();
        int tamanho = sizeof(conjHeap) / sizeof(conjHeap[0]);
        // ordernar
        heap_ordenar(conjHeap, num);
        //marcar tempo.
        clock2 = clock();
        // armazena o tempo de cada passagem do heap
        avalHeap[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

        //Executando o merge sort
        clock1 = clock();
        // ordernar
        merge_sort(conjMerge, 0, num - 1);
        //marcar tempo.
        clock2 = clock();
        //armazena o tempo de cada passagem do merge
        avalMerge[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

        //Executando o quick sort
        clock1 = clock();
        // ordernar
        quick_ordenar(conjQuick, 0, num - 1, num);
        //marcar tempo.
        clock2 = clock();
        //Armazena o tempo de cada passagem do quick.
        avalQuick[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

    } //fim do for de avaliação

    //imprimir os arrays com os tempos dos algoritmos.
    double tempoTotal = 0.0;
    double tempoMedio = 0.0;
    cout << fixed;
    cout << setprecision(10);
    cout << "\nHeap Sort:\n";
    for (int i = 0; i < aval; i++) {
        cout << avalHeap[i] << endl;
        tempoTotal += avalHeap[i];
    }
    cout << "Tempo Total = " << tempoTotal << endl;
    cout << "Média = " << tempoTotal / aval << endl;

    tempoTotal = 0.0;
    cout << "\nMerge Sort:\n";
    for (int i = 0; i < aval; i++) {
        cout << avalMerge[i] << endl;
        tempoTotal += avalMerge[i];
    }
    cout << "Tempo Total = " << tempoTotal << endl;
    cout << "Média = " << tempoTotal / aval << endl;

    tempoTotal = 0.0;
    cout << "\nQuick Sort:\n";
    for (int i = 0; i < aval; i++) {
        cout << avalQuick[i] << endl;
        tempoTotal += avalQuick[i];
    }
    cout << "Tempo Total = " << tempoTotal << endl;
    cout << "Média = " << tempoTotal / aval << endl;

    cout << "\n\nComo queria demonstrar!!!!\n\n";

    delete[] conjHeap;
    delete[] conjMerge;
    delete[] conjQuick;
    delete[] avalHeap;
    delete[] avalMerge;
    delete[] avalQuick;

    return 0;
} // fim do main

void heap_ordenar(int conj[], int n) {

    for (int i = (n / 2 - 1); i >= 0; i--) {
        heap_construir(conj, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(conj[0], conj[i]);
        heap_construir(conj, i, 0);
    }
} //fim de heap_ordenar

void heap_construir(int conj[], int n, int i) {
    int raiz = i;
    int esq = i + i;
    int dir = esq + 1;

    if (esq < n && conj[esq] > conj[raiz])
        raiz = esq;
    if (dir < n && conj[dir] > conj[raiz])
        raiz = dir;

    if (raiz != i) {
        swap(conj[i], conj[raiz]);
        heap_construir(conj, n, raiz);
    }
} // fim de heap_construir

//Merge
void merge_sort(int* arr, int Limite_inferior, int Limite_superior) {

    int meio;
    if (Limite_inferior < Limite_superior) {
        meio = (Limite_inferior + Limite_superior) / 2; //typecasting ....
        //dividiu o array em dois, usando os limites passados
        //para identificar o array inferior e o superio
        merge_sort(arr, Limite_inferior, meio);
        merge_sort(arr, meio + 1, Limite_superior);
        // juntando os arrays já ordenados.
        merge(arr, Limite_inferior, Limite_superior, meio);
    }
} // fim do merge_sort

void merge(int* arr, int Limite_inferior, int Limite_superior, int meio) {
    int temp[1000000], i, j, k;

    //contadores para ordenar os dados durante o merge
    i = Limite_inferior;
    k = Limite_inferior; //array final
    j = meio + 1;

    while (i <= meio && j <= Limite_superior) {
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
    }     // fim while

    while (i <= meio) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= Limite_superior) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = Limite_inferior; i < k; i++) {
        arr[i] = temp[i];
    }
}// fim do merge

//quick
int quick_particao(int array_teste[], int inferior, int superior, int tamanho) {
    int pivot = array_teste[superior];
    int i = (inferior - 1);

    for (int j = inferior; j < superior; j++) {
        if (array_teste[j] <= pivot) {
            i++;
            troca(&array_teste[i], &array_teste[j]);
        }
    }
    troca(&array_teste[i + 1], &array_teste[superior]);
    return (i + 1);
} // fim do quick_particao

void quick_ordenar(int array_teste[], int inferior, int superior, int tamanho) {
    if (inferior < superior) {
        int pi = quick_particao(array_teste, inferior, superior, tamanho);
        quick_ordenar(array_teste, inferior, pi - 1, tamanho);
        quick_ordenar(array_teste, pi + 1, superior, tamanho);
    }
}

void troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Você pode converter para templates, e fazer com que o teste fique mais interativo
 * talvez indicando que algoritmo está sendo testado, e quantas vezes... o processo todo 
 * ficará mais lento. Em contra-partida, o usuário não fica parado olhando para nada.
 * 
 * Uma vez que esteja usando templates. Compare os algoritmos ordenando chars, doubles, strings.
 * 
 */