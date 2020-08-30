//quando tiver saco, corrija este código

#include <iostream>
#include <chrono>
using namespace std;

//heap
void heap_construir(int[], int, int);
void heap_ordenar(int[], int);
//merge
void merge(int*, int, int, int);
void merge_sort(int*, int, int);
//prototipos
void troca(int*, int*);
void quick_ordenar(int[], int, int, int);
int quick_particao(int[], int, int, int);

//função main vai rodar o algoritmo
int main() {
    int aval = 1; //número de avaliações
    int num = 20; //tamanho do conjunto

    //ponteiros para a criação conjunto de testes usando array dinâmicos
 //   int* conjHeap = NULL;
    int* conjMerge = NULL;
    int* conjQuick = NULL;
    //guardar os tempos dos algoritmos
    //double* avalHeap = NULL;
    double* avalMerge = NULL;
    double* avalQuick = NULL;

    int* conjHeap{ new int[num] {} };
    double* avalHeap{ new double[aval] {} };


    //um conjunto para cada algoritmo de ordenação
   // conjHeap = new int[num];
    conjMerge = new int[num];
    conjQuick = new int[num];
    //um array para cada resultado por algoritmo
 //   avalHeap = new double[aval];
    avalMerge = new double[aval];
    avalQuick = new double[aval];


    //para medir os tempos de execução.
    clock_t clock1, clock2;
    //gerar randomico 
    srand((unsigned)time(0)); //typecast

    //laço gigante avaliar os algoritmos.
    for (int i = 0; i < aval; i++)
    {

        //gerando o mesmo conjunto de aletórios em três endereços de
        //memória diferente. Isolei os conjuntos de dados.
        //usar a mesma geração para os três algoritmos.
        for (int i = 0; i < num; i++)
        {
            int treco = (rand() % 100) + 1;
            conjHeap[i] = treco;
            conjMerge[i] = treco;
            conjQuick[i] = treco;
        }
        for (int i = 0; i < 10; i++)
        {
            cout << conjHeap[i] << " ";
        }

        //heap
        //marcar tempo
        clock1 = clock();
        int tamanho = sizeof(conjHeap) / sizeof(conjHeap[0]);

        // ordernar
        heap_ordenar(conjHeap, num);
        //marcar tempo.
        clock2 = clock();

        for (int i = 0; i < 10; i++)
        {
            cout << conjHeap[i] << " ";
        }

        // armazena o tempo de cada passagem do heap
        avalHeap[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

        //merge
        clock1 = clock();
        // ordernar
      //  merge_sort(conjMerge, 0, num - 1);
        //marcar tempo.
        clock2 = clock();
        //armazena o tempo de cada passagem do merge
        avalMerge[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

        //quick
        clock1 = clock();
        // ordernar
      //  quick_ordenar(conjQuick, 0, num - 1, num);
        //marcar tempo.
        clock2 = clock();
        //Armazena o tempo de cada passagem do quick.
        avalQuick[i] = (float)(clock2 - clock1) / CLOCKS_PER_SEC;

    } //fim do for de avaliação
    //imprimir os arrays com os tempos dos algoritmos.
    cout << "Heap Sort:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << avalHeap[i] << endl;
    }
    cout << "Merge Sort:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << avalMerge[i] << endl;
    }
    cout << "Quick Sort:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << avalQuick[i] << endl;
    }

    cout << "\n\nComo queria demonstrar!!!!\n\n";

    /*   //limpando a memória.
       delete[] conjHeap;
       conjHeap = NULL;
       delete[] conjMerge;
       conjMerge = NULL;
       delete[] conjQuick;
       conjQuick = NULL;
       delete[] avalHeap;
       avalHeap = NULL;
       delete[] avalMerge;
       avalMerge = NULL;
       delete[] avalQuick;
       avalQuick = NULL;
   */
    return 0;
} // fim do main

void heap_ordenar(int conj[], int n)
{

    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        heap_construir(conj, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(conj[0], conj[i]);
        heap_construir(conj, i, 0);
    }
} //fim de ordenar

void heap_construir(int conj[], int n, int i)
{
    int raiz = i;
    int esq = i + i;
    int dir = esq + 1;

    if (esq < n && conj[esq] > conj[raiz])
        raiz = esq;
    if (dir < n && conj[dir] > conj[raiz])
        raiz = dir;

    if (raiz != i)
    {
        swap(conj[i], conj[raiz]);
        heap_construir(conj, n, raiz);
    }
}

//Merge
void merge_sort(int* arr, int Limite_inferior, int Limite_superior)
{

    int meio;
    if (Limite_inferior < Limite_superior)
    {
        meio = (Limite_inferior + Limite_superior) / 2; //typecasting ....
        //dividiu o array em dois, usando os limites passados
        //para identificar o array inferior e o superio
        merge_sort(arr, Limite_inferior, meio);
        merge_sort(arr, meio + 1, Limite_superior);
        // juntando os arrays já ordenados.
        merge(arr, Limite_inferior, Limite_superior, meio);
    }
}
// oi allan aqui :)
void merge(int* arr, int Limite_inferior, int Limite_superior, int meio)
{
    int temp[1000000], i, j, k;

    //contadores para ordenar os dados durante o merge
    i = Limite_inferior;
    k = Limite_inferior; //array final
    j = meio + 1;

    while (i <= meio && j <= Limite_superior)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        } // fim do if
    }     // fim while

    while (i <= meio)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= Limite_superior)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = Limite_inferior; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

//quick
int quick_particao(int array_teste[], int inferior, int superior, int tamanho)
{
    int pivot = array_teste[superior];
    int i = (inferior - 1);

    for (int j = inferior; j < superior; j++)
    {
        if (array_teste[j] <= pivot)
        {
            i++;
            troca(&array_teste[i], &array_teste[j]);
        }
    }
    troca(&array_teste[i + 1], &array_teste[superior]);
    return (i + 1);
}

void quick_ordenar(int array_teste[], int inferior, int superior, int tamanho)
{
    if (inferior < superior)
    {
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