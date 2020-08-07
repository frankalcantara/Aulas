/* 
AUTHOR: Frank de Alcantara (frank.alcantara@gmail.com)
DATA: 07 ago. 2020
Programa de demonstração do uso do Insertion Sort.
*/

#include <iostream>
#include <ctime>

using namespace std;

void display(int *, string);

int main()
{
    //iniciando o gerador randômicos
    srand((unsigned)time(0));

    string string_1;
    int array_teste[10];

    //preenchendo o conjunto (array a) com números randômicos.
    for (int i = 0; i < 10; i++)
    {
        array_teste[i] = (rand() % 100) + 1; //randômicos menores que cem
    }

    //para visualizar a lista
    string_1 = "\n\nLista Não ordenada";
    display(array_teste, string_1);

    // O insertion Sort
    for (int i = 1; i < 10; i++)
    {
        int temp = array_teste[i];
        int j = i - 1;
        while (j >= 0 && temp <= array_teste[j])
        {
            array_teste[j + 1] = array_teste[j];
            j = j - 1;
        }
        array_teste[j + 1] = temp;
    }

    string_1 = "\n\nLista ordenada";
    display(array_teste, string_1);
}

void display(int m[10], string s)
{
    cout << s << endl;

    // display array elements
    for (int k = 0; k < 10; k++)
    {
        cout << m[k] << "\t";
    }
}