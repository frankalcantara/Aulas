/* 
AUTHOR: Frank de Alcantara (frank.alcantara@gmail.com)
DATA: 07 ago. 2020
Programa de demonstração do uso do Merge Sort.
*/

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

//protótipo de função
void display(int *, string);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main()
{

    //iniciando um gerador de números randômicos
    srand((unsigned)time(0));
    int num = 100000;
    int array_teste[100000];
    //string string_1;

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < 100000; i++)
    {
        array_teste[i] = (rand() % 100) + 1;
    }

    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;

    //display(array_teste, "\nNão ordenado:\n");

    clock1 = clock();
    merge_sort(array_teste, 0, num - 1);
    clock2 = clock();
    //display(array_teste, "\nNão ordenado:\n");

    //O(nlogn) 100 x log 100
    //O(n^2) 100^2

    cout << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;

} //fim do main

//funções implementação
void merge_sort(int *arr, int baixo, int alto)
{

    int meio;

    if (baixo < alto)
    {
        meio = (baixo + alto) / 2; //typecasting ....
        //dividiu o array em dois, usando os limites passados
        //para identificar o array inferior e o superio
        merge_sort(arr, baixo, meio);
        merge_sort(arr, meio + 1, alto);
        // juntando os arrays já ordenados.
        merge(arr, alto, baixo, meio);
    }
}

void merge(int *arr, int alto, int baixo, int meio)
{
    int temp[200000], i, j, k;
    i = baixo;
    k = baixo; //array final
    j = meio + 1;

    while (i <= meio && j <= alto)
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

    while (j <= alto)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (i = baixo; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

void display(int m[100000], string s)
{

    cout << s << endl;

    for (int i = 0; i < 100000; i++)
    {
        cout << m[i] << "\t";
    }

    cout << endl;
}