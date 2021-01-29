/**
 * @file classe2.cpp
 * @author Frank de Alcantara
 * @brief Outro exemplo de criação de classes em C++
 *          Este exemplo mostra a criação de um constructor
 * @version 0.1
 * @date 2020-07-05
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief Apenas para a demonstração da criação e uso de constructors
 *
 */
class Carro {
public:
    string marca;
    string modelo;
    int ano;
    //em C++ o constructor é um método público com o mesmo nome
    //da classe.
    Carro(string marcax, string modelox, int anox);
};

/**
 * @brief Método para a construção de um objeto da classe Carro.
 * Construct a new Carro:: Carro object
 *
 * @param marcax    - string - marca do carro
 * @param modelox   - string - modelo do carro
 * @param anox      - int   - ano de fabricação do carro
 */
Carro::Carro(string marcax, string modelox, int anox) {
    marca = marcax;
    modelo = modelox;
    ano = anox;
}

//main apenas para teste da classe
int main() {
    //criando o objeto meu, da classe Carro usando o constructor.
    Carro meu("BMW", "X6", 2021);
    //usando a notação ponto para acessar os métodos da classe no objeto.
    cout << "meu carro é um " << meu.marca << ", " << meu.modelo << ", " << meu.ano << endl;

    meu.ano = 2020;
    cout << "\n\nmeu carro é um " << meu.marca << ", " << meu.modelo << ", " << meu.ano << endl;

    return 0;
}// fim do main