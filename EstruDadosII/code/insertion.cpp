/* 
AUTHOR: Frank de Alcantara (frank.alcantara@gmail.com)
DATA: 07 ago. 2020
Programa de demonstração do uso do Insertion Sort.
*/

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

//protótipo de função
void display(int *, string);

int main()
{

    //iniciando um gerador de números randômicos
    srand((unsigned)time(0));

    int array_teste[100000];
    string string_1;

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < 100000; i++)
    {
        array_teste[i] = (rand() % 100) + 1;
    }

    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;
    display(array_teste, "lista não ordenada: ");
    //função clock() do ctime
    clock1 = clock();
    //insertion sort
    for (int i = 1; i < 100000; i++)
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

    clock2 = clock();

    cout << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;
    display(array_teste, "lista ordenada: ");

    return 1;
} // fim do main

//implementação da função display para mostar os arrays
void display(int m[100000], string s)
{

    cout << s << endl;

    for (int i = 0; i < 100000; i++)
    {
        cout << m[i] << "\t";
    }

    cout << endl;
}