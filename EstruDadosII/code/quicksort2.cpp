#include<iostream>
#include<vector>
using namespace std;

//Protótipos
template <typename T>
int Particao(T[], int, int);

template <typename T>
void Quicksort(T[], int, int);

template <typename T>
void display(T[], int);

int main() {

    int conjunto[] = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19, 43, 57, 3, 2 };
    int n = sizeof(conjunto) / sizeof(int);

    cout << "Não Ordenado: " << "\n";
    display(conjunto, n);

    Quicksort(conjunto, 0, n - 1);

    cout << "Ordenado: " << "\n";
    display(conjunto, n);

    char letras[] = { 'a', 'x', 'd', 'h', 'm' };
    n = sizeof(letras) / sizeof(char);

    cout << "Não Ordenado: " << "\n";
    display(letras, n);

    Quicksort(letras, 0, n - 1);

    cout << "Ordenado: " << "\n";
    display(letras, n);

}//fim do main


 // template function to find the position of pivo element
// last element is taken as pivo

/**
 * @brief Função de partição para dividir o conjunto em dois
 *
 * @tparam T - template
 * @param conjunto - conjunto a ser dividido
 * @param comeco - inicio do conjunto
 * @param fim - fim do conjunto
 * @return int - posição do pivô
 */
template <typename T>
int Particao(T conjunto[], int comeco, int fim) {

    int pivo = fim;
    int j = comeco;
    for (int i = comeco;i < fim;++i) {
        if (conjunto[i] < conjunto[pivo]) {
            swap(conjunto[i], conjunto[j]);
            ++j;
        }
    }
    swap(conjunto[j], conjunto[pivo]);
    return j;
}

/**
 * @brief Função recursiva de ordenamento usando quick sort
 *
 * @tparam T - template
 * @param conjunto - conjunto a ser ordenado
 * @param comeco - inicio do conjunto a ser ordenado
 * @param fim  - fim do conjunto a ser ordenado
 */
template <typename T>
void Quicksort(T conjunto[], int comeco, int fim) {

    if (comeco < fim) {
        int p = Particao(conjunto, comeco, fim);
        Quicksort(conjunto, comeco, p - 1);
        Quicksort(conjunto, p + 1, fim);
    }
}

/**
 * @brief mostar no terminal o conjunto de dados
 *
 * @tparam T - template
 * @param conjunto - dados a serem mostrados
 * @param comprimento  - comprimento dos dados
 */
template <typename T>
void display(T conjunto[], int comprimento) {
    for (int i = 0;i < comprimento;++i)
        cout << conjunto[i] << " ";
    cout << "\n\n";
}