/**
 * @file class1.cpp
 * @author Frank de Alcantara
 * @brief   Exemplo de criação de classes em C++
 * @version 0.1
 * @date 2020-06-10
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief classe muito simples com apenas dois atributos
 *
 */
class Primeira {
public:             // visualização public todos podem ver 
    int numero;     // atributos
    string nome;
};

int main() {
    Primeira teste;   //criando o objeto teste da classe Primeira

    //acessar os membros usando a notação ponto.
    teste.numero = 1357;
    teste.nome = "Sandra";

    cout << teste.nome << "\n" << teste.numero << endl;

    return 0;
} //fim do main

