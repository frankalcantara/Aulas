/**
 * @file quickSort.cpp
 * @author Frank de Alcantara
 * @brief   Quick Sort em C++ - Demonstração
 * @version 0.1
 * @date 2021-02-15
 */

#include <iostream>
#include <chrono> //funçoes para medir o tempo de execução.
using namespace std; //define o uso do std

//protótipos
void troca(int*, int*);
void display(int[], int);
//funções para o quick sort
int particao(int[], int, int, int);
void quickSort(int[], int, int, int);

int main() {

    srand((unsigned)clock()); //semente para o gerador de randômicos

    int tamanho = 15; //determinar o tamanho do conjunto

    //ponteiro para a criação do array_teste dinâmico
    int* array_teste = NULL;

    //gerando o array_teste dinâmico
    array_teste = new int[tamanho];

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < tamanho; i++)    {
        array_teste[i] = (rand() % 100) + 1;
    }

    //só para imprimir
    cout << "Conjunto não ordenado: \n";
    display(array_teste, tamanho);

    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;
    double diferenca = 0.0;

    clock1 = clock(); //registra o tempo
    //ordenamento
    quickSort(array_teste, 0, tamanho - 1, tamanho);

    clock2 = clock(); //registra o tempo

    // Apenas imprime o tempo.
    cout << "\n\nTempo gasto " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;

    // imprimir o resultado
    cout << "Conjunto ordenado: \n";
    display(array_teste, tamanho);

    //trabalhando com o array_teste dinâmicos
    delete[] array_teste; // remover da memória.
    array_teste = NULL;   //limpar a memória

} //fim do main

// função de troca
void troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// mostrar o conjunto de inteiros
void display(int array_teste[], int size) {
    if (size > 20)
        return;
    //coloca na tela
    for (int i = 0; i < size; i++)
        cout << array_teste[i] << " ";

    cout << "\n\n";
}

// função recursiva para o pivô
int particao(int array_teste[], int inferior, int superior, int tamanho) {
    // seleção do pivô
    int pivo = array_teste[superior];
    //cada vez que chamar imprimimos o pivô
    if (tamanho < 20)
        cout << pivo << endl;

    int i = (inferior - 1);

    // menor que o pivo colocado na esquerda, correndo do menor índice para o maior
    // maior que o pivo colocado na direita, correndo do maior índice para o menor
    for (int j = inferior; j < superior; j++)
    {
        if (array_teste[j] <= pivot)
        {
            i++;
            troca(&array_teste[i], &array_teste[j]);
        }
    }

    //mostrar o passo a passo
    display(array_teste, tamanho);

    //inverte as posições faz com que o pivo vá para a posição correta.
    troca(&array_teste[i + 1], &array_teste[superior]);
    return (i + 1);
}

void quickSort(int array_teste[], int inferior, int superior, int tamanho){
    if (inferior < superior){
        // seleciona o pivo e coloca todos os elementos menores a esquerda e
        // todos os maiores a direita do pivot
        int pivo = particao(array_teste, inferior, superior, tamanho);
        // Ordena os elementos a esquerda do pivot
        quickSort(array_teste, inferior, pivo - 1, tamanho);
        // Ordena os elementos a direita
        quickSort(array_teste, pivo + 1, superior, tamanho);
    }
}

/**
 * @brief crie uma versão do quick sort usando templates para inteiros, chars, doubles.
 * 
 */