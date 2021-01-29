/**
 * @file classe3Metodo.cpp
 * @author Frank de Alcantara
 * @brief  Apenas para demonstar a criação de classes com métodos.
 * @version 0.1
 * @date 2020-07-10
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief classe com nome criativo apenas para demonstrar a criação de um método.
 *
 */
class Segunda {
public:
    /**
     * @brief Método criado no corpo da classe
     *
     * @param nome - string - texto que será impresso no terminal.
     */
    void hello(string nome) {  //exemplo de método
        cout << nome << ", Oi nós aqui!";
    }
};

//apenas para teste da classe criada
int main() {
    //criação de um objeto saudacao, da classe Segunda, instanciação da classe Segunda em saudacao.
    Segunda saudacao;
    //chamada do método hello na classe 
    saudacao.hello("Turma");

    //usando terminal para passar uma string
    string nome;
    cout << "\n\n\nDigite um nome: ";
    cin >> nome;

    saudacao.hello(nome);

    return 0;
}//fim do main