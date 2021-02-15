/**
 * @file Mergesort.cpp
 * @author Frank de Alcantara
 * @brief Programa de demonstração do Merge Sort em C++ usando conjuntoes e templates.
 * @version 0.1
 * @date 2020-07-07
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;

#define COMPRIMENTO_TESTES 10

//protótipo 
string gen_random(const int);

template<class T>
void merge(vector<T>& conjunto, int p, int q, int r) {
    int size1 = q - p + 1;
    int size2 = r - q;
    vector<T> L(size1);
    vector<T> R(size2);

    for (int i = 0; i < size1; i++) {
        L[i] = conjunto[p + i];
    }

    for (int j = 0; j < size2; j++) {
        R[j] = conjunto[q + j + 1];
    }

    int i = 0, j = 0;
    int k;
    for (k = p; k <= r && i < size1 && j < size2; k++) {
        if (L[i] <= R[j]) {
            conjunto[k] = L[i];
            i++;
        }
        else {
            conjunto[k] = R[j];
            j++;
        }
    }

    for (i = i; i < size1; ++i) {
        conjunto[k] = L[i];
        k++;
    }

    for (j = j; j < size2; j++) {
        conjunto[k] = R[j];
        k++;
    }
}

template<class T>
void merge_sort(vector<T>& v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int main() {

    //criando um conjunto de dados
    vector<int> conjunto;

     /**
     * @brief iniciando um gerador de números randômicos, sem nenhuma preocupação
     * quanto a qualidade dos números gerados ou com a velocidade de geração.
     *
     */
    srand((unsigned)time(0));

    //testando com inteiros
    for (int i = 0;i < COMPRIMENTO_TESTES;i++) {
      //inserindo números inteiros aleatórios no conjunto
        conjunto.push_back((rand() % 100) + 1);
    }

    int comprimento = conjunto.size();

    cout << "Conjunto não ordenado: ";
    for (int n = 0; n < comprimento; n++) {
        cout << conjunto[n] << " ";
    }
    cout << "\n";
    cout << "Conjunto ordenado: ";

    merge_sort(conjunto, 0, comprimento - 1);
    for (int n = 0; n < comprimento; n++) {
        cout << conjunto[n] << " ";
    }

    cout << "\n\n";

    //testando com caracteres
    vector<char> letras;

    for (int i = 0;i < COMPRIMENTO_TESTES;i++) {
      //inserindo letras entre a e z de forma randômica no conjunto letras
        letras.push_back('a' + (rand() % 26));
    }

    comprimento = letras.size();
    cout << "Conjunto não ordenado: ";
    for (int n = 0; n < comprimento; n++) {
        cout << letras[n] << " ";
    }
    cout << "\n";
    cout << "conjunto ordenado: ";
    merge_sort(letras, 0, comprimento - 1);

    for (int n = 0; n < comprimento; n++) {
        cout << letras[n] << " ";
    }
    cout << "\n\n";

    //testando com strings
    vector<string> str;

    for (int i = 0;i < COMPRIMENTO_TESTES;i++) {
        //inserindo strings randomicas de comprimento randomico
        str.push_back(gen_random((rand() % 10)));
    }

    int comprimento2 = str.size();

    cout << "Conjunto ordenado: ";
    for (int n = 0; n < comprimento2; n++)
    {
        cout << str[n] << " ";
    }
    cout << "\n";
    cout << "Conjunto não ordenado: ";
    merge_sort(str, 0, comprimento2 - 1);
    for (int n = 0; n < comprimento2; n++)
    {
        cout << str[n] << " ";
    }
    cout << "\n";

    return 0;
}//fim do main


/**
 * @brief Função para gerar strings aleatórios de Ates Goral em
 * https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
 */
string gen_random(const int len) {
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    return tmp_s;
}
