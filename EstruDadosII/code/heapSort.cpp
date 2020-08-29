#include <iostream>
#include <chrono>
using namespace std;

//protótipos
void display(int[], int);
void ordena(int[], int);
void constroi(int[], int, int);

// Driver program
int main()
{

    //iniciando um gerador de números randômicos
    srand((unsigned)time(0));

    int num = 30;
    int conj[num];
    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < num; i++)
    {
        conj[i] = (rand() % 100) + 1;
    }

    //int conj[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(conj) / sizeof(conj[0]);

    if (num <= 30)
    {
        cout << "O conjunto não ordenado é \n";
        display(conj, n);
    }

    clock1 = clock();
    ordena(conj, n); // o heap sort
    clock2 = clock();

    if (num <= 30)
    {
        cout << "O conjunto ordenado é \n";
        display(conj, n);
    }

    // Apenas imprime o tempo.
    cout << "tempo gasto: " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;
}

// construindo um galho, cuja raiz é o nó i
// i é um indez do conj[].  e n é o tamanho do heap
void constroi(int conj[], int n, int i)
{
    // para guardar as posições dos itens no conjunto
    int raiz = i;      // nova raiz
    int esq = 2 * i;   // esquerda = 2*i
    int dir = esq + 1; // direita = 2*i + 1

    // se o filho da esquerda for menor que a raiz
    if (esq < n && conj[esq] > conj[raiz])
        raiz = esq;

    // se o filho da direita for maior que a raiz
    if (dir < n && conj[dir] > conj[raiz])
        raiz = dir;

    // na biblioteca std, existe uma função swap
    if (raiz != i)
    {
        swap(conj[i], conj[raiz]);

        // chamamos novamente para construir a subárvore da árvore
        constroi(conj, n, raiz);
    }
}

// função de ordenação
void ordena(int conj[], int n)
{
    // constroi o novo conjay
    for (int i = n / 2 - 1; i >= 0; i--)
        constroi(conj, n, i);

    // tira os elementos do heap, um a um
    for (int i = n - 1; i >= 0; i--)
    {
        // move a raiz atual para o fim do conjay
        swap(conj[0], conj[i]);
        // chama a função constroi para criar o heap
        constroi(conj, i, 0);
    }
}

/* Apenas para mostrar o conjay */
void display(int conj[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << conj[i] << " ";
    cout << "\n";
}
