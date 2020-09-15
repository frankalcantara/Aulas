#include <iostream>
class Pessoa
{
public:
    std::string nome;
    int idade;

    std::string getnome() const { return nome; }
    int getIdade() const { return idade; }

    Pessoa(std::string nome = "", int idade = 0)
        : nome(nome), idade(idade)
    {  }
};

// Funcionario publicly inherits from Pessoa
class Funcionario : public Pessoa
{
public:
    double salarioHora;
    long FuncionarioID;

    Funcionario(double salarioHora = 0.0, long FuncionarioID = 0)
        : salarioHora(salarioHora), FuncionarioID(FuncionarioID)
    {
    }

    void displayNomeSalario() const
    {
        std::cout << nome << ": " << salarioHora << '\n';
    }
};

int main() {
    Funcionario frank(20.25, 12345);
    frank.nome = "Frank"; // we can do this because nome is public

    frank.displayNomeSalario();

    return 0;
}