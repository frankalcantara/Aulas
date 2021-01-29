/**
 * @file pertencimento.cpp
 * @author Frank de Alcantara
 * @brief Demonstra a relação de pertencimento entre classes do C++
 * @version 0.1
 * @date 2021-01-29
 * 
 * 
 */
#include <iostream>
using namespace std;

//classe estudante para demonstrar a relação de pertencimento
//a classe Endereco pertence a classe estudante.
class Estudante {
protected:
//propriedades protegidas.
    string  nome;
    int   matricula;
    float   nota;
public:
  //métodos públicos
    void setDetalhes(void);
    void displayDetalhes(void);
    // uma forma de fazer a relação de associação entre classes
    // outra forma seria colocar um ponteiro, nesta classe que 
    //fosse do tipo da classe Endereco
    class Endereco {
    protected:
        string Rua;
        string Cidade;
        string Estado;
        string CEP;
        string Pais;
       // bool validaCEP();
    public:
        string getCEP() {
            return this->CEP;
        };
        void setEndereco(string Rua, string Cidade, string Estado, string Pais, string Cep) {
            this->Rua = Rua;
            this->Cidade = Cidade;
            this->Estado = Estado;
            this->CEP = Cep;
            this->Pais = Pais;
        };
    };

    //cria na classe estudante um objeto da classe Endereco
    Endereco endereco;
};

//declaração do método fora da classe
void Estudante::setDetalhes(void) {
    //comando\033[1;31m" muda para vermelho e coloca em bold 
    //coloca a cor da fonte novamente em branco sem bold "\033[0m"
    cout << "\033[1;31m" << "Digite nome: " << "\033[0m";
    cin >> nome; //carrega a propriedade
    cout << "\033[1;31m" << "Digite matricula: " << "\033[0m";
    cin >> matricula;
    cout << "\033[1;31m" << "Digite nota (máximo 200): " << "\033[0m";
    cin >> nota;

    string ruaEscolhida, cepEscolhido;
    cout << "Qual a rua:" << endl;
    cin >> ruaEscolhida;
    cout << "Qual o CEP:" << endl;
    cin >> cepEscolhido;
    endereco.setEndereco(ruaEscolhida, "Curitiba", "PR", "Brasil", cepEscolhido);
}

 //método para mostrar os valores armazenados.
void Estudante::displayDetalhes(void) {
   //para limpar a tela
  // cout << "\033[2J)" << "\033[1;1H";

    cout << "\033[1;31m" << "nome:" << "\033[0m" << nome <<
        "\033[1;31m" << "\nMatricula:" << "\033[0m" << matricula << "\033[1;31m" << "\nNotal:" << "\033[0m" << nota << "\033[1;31m" << "\nPercentual Atingido:" << "\033[0m" << "\n\n" << endl;

    cout << endereco.getCEP();

}

/**
 * @brief outra relação entre classes: herança
 * 
 */
//classe herdeira. class Child : public Parent 
class Estudante_CURSO : public Estudante {
public:
    string curso;
    void setCurso(string curso) {
        this->curso = curso;
    };
    void getCurso() {
        cout << curso << endl;
    };
};

//apenas para teste
int main() {
    //variável para saber quantos alunos
    int n;
    string cursoEscolhido;

    cout << "\033[1;34m" << "Quantidade de Estudantes: " << "\033[0m";
    cin >> n;
    
    //criando um array dinâmico da classe   
    Estudante_CURSO* Estd;
    //alocando memória para uma coleção de estudantes.
    Estd = new Estudante_CURSO[n];

    //percorrendo o array item por item
    for (int i = 0; i < n; i++) {
        cout << "\033[1;34m" << "Qual o Curso: " << "\033[0m";
        
        cin >> cursoEscolhido;
        cout << "\033[1;32m" << "\nDados dos Estudante (" << i + 1 << "): \n" << "\033[0m";
        //chamando a função que preenche os detalhes.
        Estd[i].setCurso(cursoEscolhido);
        Estd[i].setDetalhes();
    }

    cout << endl;

    //para imprimir os dados...
    for (int i = 0; i < n; i++) {
      //cout<< "\033[2J"<<"\033[1;1H";
        cout << "\033[1;32m" << "\nNome do Curso:" << "\033[0m";
        Estd[i].getCurso();
        cout << "\033[1;32m" << "\nDetalhes do Estudante (" << (i + 1) << "):\n";
        Estd[i].displayDetalhes();
    }
    //removendo o array dinâmico da memória 
    delete[] Estd;
    return 0;
}

/**
 * @brief tente desenhar o Diagrama de classes das classes criadas neste código.
 * 
 */