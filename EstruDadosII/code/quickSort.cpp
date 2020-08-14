// Quick sort in C++

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

//#define SWAP(a, b) \
    {              \
        int temp;  \
        temp = a;  \
        a = b;     \
        b = temp;  \
    }

//protótipos
void troca(int *, int *);
void display(int[], int);
int particao(int[], int, int, int);
void quickSort(int[], int, int, int);

// Driver code
int main()
{

    srand((unsigned)time(0));
    int tamanho = 50;
    int *arr = NULL; // Pointer to int, initialize to nothing.

    // Read in the size
    arr = new int[tamanho];
    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < tamanho; i++)
    {
        arr[i] = (rand() % 1000) + 1;
    }

    //  int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, tamanho - 1, tamanho);

    cout << "Conjunto ordenado: \n";
    display(arr, tamanho);

    delete[] arr; // remover da memória.
    arr = NULL;   //limpar a memória

} //fim do main

// função de troca
void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// mostrar o conjunto de inteiros
void display(int array[], int size)
{
    if (size > 20)
        size = 20;
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n........\n";
}

// função recursiva para o pivo
int particao(int array[], int inferior, int superior, int tamanho)
{
    // seleção do pivo
    int pivot = array[superior];
    int i = (inferior - 1);

    // menor que o pivo na esquerda
    // mario que o pivo na direita
    for (int j = inferior; j < superior; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            troca(&array[i], &array[j]);
        }
    }
    //mostrar o passo a passo
    display(array, tamanho);

    //inverte as posições
    troca(&array[i + 1], &array[superior]);
    return (i + 1);
}

void quickSort(int array[], int inferior, int superior, int tamanho)
{
    if (inferior < superior)
    {
        // seleciona o pivo e coloca todos os elementos menores a esquerda e
        // todos os maiores a direita do pivot
        int pi = particao(array, inferior, superior, tamanho / 2);

        // Ordena os elementos a esquerda do pivot
        quickSort(array, inferior, pi - 1, tamanho);

        // Ordena os elementos a direita
        quickSort(array, pi + 1, superior, tamanho);
    }
}