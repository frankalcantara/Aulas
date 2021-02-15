#include <iostream>
#include <chrono>
using namespace std;

//protótipos
void display(int[], int);
void ordena(int[], int);
void constroi(int[], int, int);

int main() {

    //iniciando um gerador de números randômicos
    srand((unsigned)time(0));

    //tamanho do conjunto que será gerado
    //observe o limite do int
    int num = 2000000; 

    int conjunto[num];
    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;

    // preenchendo nosso conjunto com números aleatórios
    for (int i = 0; i < num; i++)
    {
        conjunto[i] = (rand() % 100) + 1;
    }

    //int conjunto[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(conjunto) / sizeof(conjunto[0]);

    cout << "O conjunto não ordenado é \n";
    display(conjunto, n);
  
    clock1 = clock();
    ordena(conjunto, n); // o heap sort
    clock2 = clock();

    cout << "O conjunto ordenado é \n";
    display(conjunto, n);
  
    // Apenas imprime o tempo.
    cout << "tempo gasto: " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;
}

/**
 * @brief vamos construir uma árvore no formato heap
 * 
 * @param conjunto - dados a serem ordenados
 * @param comprimento - comprimento do heap
 * @param i - index do conjunto.
 */
void constroi(int conjunto[], int comprimento, int i) {
    // para guardar as posições dos itens no conjunto
    int raiz = i;      // nova raiz
    int esq = 2 * i;   // esquerda = 2*i
    int dir = esq + 1; // direita = 2*i + 1

    // se o filho da esquerda for menor que a raiz
    if (esq < comprimento && conjunto[esq] > conjunto[raiz])
        raiz = esq;

    // se o filho da direita for maior que a raiz
    if (dir < comprimento && conjunto[dir] > conjunto[raiz])
        raiz = dir;

    // na biblioteca std, existe uma função swap
    if (raiz != i) {
        swap(conjunto[i], conjunto[raiz]);
        // chamamos novamente para construir a subárvore da árvore
        constroi(conjunto, comprimento, raiz);
    }
}

// função de ordenação
void ordena(int conjunto[], int n) {
    // constrói o novo conjunto
    for (int i = n / 2 - 1; i >= 0; i--)
        constroi(conjunto, n, i);

    // tira os elementos do heap, um a um
    for (int i = n - 1; i >= 0; i--) {
        // move a raiz atual para o fim do conjunto
        swap(conjunto[0], conjunto[i]);
        // chama a função constroi para criar o heap
        constroi(conjunto, i, 0);
    }
}

/**
 * @brief Apenas para mostrar o conjunto de dados
 * 
 * @param conjunto - dados a serem ordenados
 * @param comprimento - comprimento destes dados
 */
void display(int conjunto[], int comprimento) {
  if (comprimento <= 30){
    // só mostar na tela se isso fizer sentido
      for (int i = 0; i < comprimento; ++i)
        cout << conjunto[i] << " ";
    cout << "\n";
  } else {
    cout << "o conjunto não cabe no terminal!!" << endl;
  }
}
