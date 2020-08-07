/* 
AUTHOR: Frank de Alcantara (frank.alcantara@gmail.com)
DATA: 07 ago. 2020
Programa de demonstração do uso do Merge Sort.
*/

#include <iostream>
#include <ctime>
using namespace std;

// protótipos
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void display(int *, string, int);

int main()
{
    int num = 30;
    int array_teste[30];
    string string_1;

    //iniciando o gerador randômicos
    srand((unsigned)time(0));

    //preenchendo o conjunto (array a) com números randômicos.
    for (int i = 0; i < 30; i++)
    {
        array_teste[i] = (rand() % 100) + 1; //randômicos menores que cem
    }

    string_1 = "\n\nLista não ordenada";
    display(array_teste, string_1, 30);

    merge_sort(array_teste, 0, num - 1);

    string_1 = "\n\nLista ordenada";
    display(array_teste, string_1, 30);
}

// funções - implementação.
void display(int m[10], string s, int tam)
{
    cout << s << endl;
    for (int k = 0; k < tam; k++)
    {
        cout << m[k] << "\t";
    }
}
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        //divide o array no meio chama as funções de ordenação para cada metade
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //junta as partes
        merge(arr, low, high, mid);
    }
}
// o Merge Sort
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        arr[i] = c[i];
    }
}
