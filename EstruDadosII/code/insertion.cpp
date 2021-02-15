/**
 * @file insertion.cpp
 * @author Frank de Alcantara
 * @brief Insertion Sort
 * @version 0.1
 * @date 2020-08-12
 *
 */
#include <iostream>
#include <chrono>
using namespace std;

#define TAMANHO_CONJUNTO 15

/**
 * @brief Protótipo da função de apresentação em tela
 *
 * @param   int - ponteiro para um array de inteiros contedo o conjunto a ser ordenado
 * @param   string - texto a ser mostrado no terminal
 */
void display(int*, const string);

int main() {

    /**
     * @brief iniciando um gerador de números randômicos, sem nenhuma preocupação 
     * quanto a qualidade dos números gerados ou com a velocidade de geração.
     * 
     */
    srand((unsigned)time(0));

    int array_teste[TAMANHO_CONJUNTO];
    string string_1;

    // preenchendo nosso conjunto de dados com números inteiros randômicos entre 1 e 100
    for (int i = 0; i < TAMANHO_CONJUNTO; i++) {
        array_teste[i] = (rand() % 100) + 1;
    }

    //variáveis usadas para medir o tempo de execução
    clock_t clock1, clock2;
    display(array_teste, "lista não ordenada: ");

    //função clock() do ctime
    clock1 = clock();

    /**
     * @brief O algortimo Insertion Sort
     * 
     */
    for (int i = 1; i < TAMANHO_CONJUNTO; i++) {

        int temp = array_teste[i];
        int j = i - 1;
        while (j >= 0 && temp <= array_teste[j]) {
            array_teste[j + 1] = array_teste[j];
            j = j - 1;
        }
        array_teste[j + 1] = temp;
    }

    clock2 = clock();

    cout << "Tempo gasto na ordenação>: " << (float)(clock2 - clock1) / CLOCKS_PER_SEC << endl;

    display(array_teste, "lista ordenada: ");

    return 0;
} // fim do main

//implementação da função display para mostar os arrays
void display(int m[TAMANHO_CONJUNTO], const string s) {
    cout << s << endl;
    for (int i = 0; i < TAMANHO_CONJUNTO; i++) {
        cout << m[i] << "\t";
    }
    cout << endl;
}

/**
 * @brief faça uma versão deste algoritmo usando templates para ordenar, inteiros, chars, doubles.
 * 
 */