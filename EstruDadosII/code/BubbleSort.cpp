/* 
AUTHOR: Frank de Alcantara (frank.alcantara@gmail.com)
DATA: 31 jul. 2020
Programa de demonstração do uso do Bubble Sort.
*/

#include <iostream>
#include <ctime>

using namespace std; // usando a biblioteca padrão

int main()
{

    //iniciando o gerador randômicos
    srand((unsigned)time(0));

    int temp = 0, tam = 10, passo = 0;
    int a[10];

    //preenchendo o conjunto (array a) com números randômicos.
    for (int i = 0; i < tam; i++)
    {
        a[i] = (rand() % 100) + 1; //randômicos menores que cem
    }

    //imprime a lista criada que será ordenada
    cout << "\n\nLista original: {";
    for (int k = 0; k < tam; k++)
    {
        cout << a[k] << ",";
    }
    cout << "}" << endl;

    //O bubble Sort
    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (a[j] < a[i])
            {
                //imprimindo sempre que trocar
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        passo++;
    }
    //imprimindo a lista ordenada
    cout << "\n\nLista ordenada: {";
    for (int k = 0; k < tam; k++)
    {
        cout << a[k] << ",";
    }
    //imprimindo o total de passos
    cout << "\nPassos: " << passo << endl;
}