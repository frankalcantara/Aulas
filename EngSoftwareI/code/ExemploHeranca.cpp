/**
 * @file ExemploHeranca1.cpp
 * @author Frank de Alcantara
 * @brief
 * @version 0.1
 * @date 2020-10-07
 *
  *
 */
#include <iostream>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    string getnome() const { return nome; }
    int getIdade() const { return idade; }

    Pessoa(string nome = "", int idade = 0)
        : nome(nome), idade(idade)
    {  }
};

/**
 * @brief A classe Funcionario herda, public, de Pessoa.
 *
 */
class Funcionario : public Pessoa {
public:
    double salarioHora;
    long FuncionarioID;

    /**
     * @brief Construct a new Funcionario object
     *          Os construtores podem usar uma lista inicial de propriedades.
     *          Essa é uma forma eficiente de inicializar as propriedades.
     *          Prefira esta solução a atribuir valores no corpo do construct
     *          referência: https://docs.microsoft.com/pt-br/cpp/cpp/constructors-cpp?view=msvc-160
     *
     * @param salarioHora - double
     * @param FuncionarioID - long
     */
    Funcionario(double salarioHora = 0.0, long FuncionarioID = 0)
        : salarioHora(salarioHora), FuncionarioID(FuncionarioID) {
    }
    /**
     * @brief Mostra o Nome e o salário, apenas para demonstração
     *
     */
    void displayNomeSalario() const {
        std::cout << nome << ": " << salarioHora << '\n';
    }
};

int main() {
    //cria o objeto frank da classe Funcionario
    Funcionario frank(20.25, 12345);
    frank.nome = "Frank"; // frank não tem a propriedade nome, 
                          //  ele herda esta propriedade da classe Pessoa. 
    //frank tem o método displayNomeSalario, este método é da classe Funcionário.
    frank.displayNomeSalario();

    return 0;
}