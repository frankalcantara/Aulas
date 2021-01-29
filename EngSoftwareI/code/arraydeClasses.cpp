/**
 * @file arraydeClasses.cpp
 * @author Frank de Alcantara
 * @brief  Demonstra o uso de objetos em arrays e o acesso por meio de ponteiros
 * @version 0.1
 * @date 2020-09-10
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief classe bem simples apenas para demonstrar o uso em array e com ponteiros
 *
 */
class Retangulo {
    int largura, altura;
public:
    void setValores(int, int);
    int area() { return largura * altura; };
};
/**
 * @brief Método para definição das propriedades
 *
 * @param a - int - largura
 * @param b - int - altura
 */
void Retangulo::setValores(int a, int b) {
    largura = a;
    altura = b;
};

int main() {
    //cria um objeto e um ponteiro para um objeto, ambos da classe Retangulo
    Retangulo ret, * ret2;
    // aloca memória para o arrayRetangulo para armazenar 2 objetos da classe Retangulo
    Retangulo* arrayRetangulo = new Retangulo[2];

    //uso apenas como variávies.    
    cout << "\nTrabalhando com variáveis:";
    ret.setValores(3, 4);
    cout << ret.area() << endl;

    //fazendo referência aos objetos que estão no array de objetos chamado arrayRetangulo.
    cout << "\nTrabalhando com arrays: " << endl;
    arrayRetangulo[0].setValores(7, 8);
    arrayRetangulo[1].setValores(4, 7);
    cout << arrayRetangulo[0].area() << "\t\t" << arrayRetangulo[1].area() << endl;

    //usando ponteiros.
    //se usar o C++17 ou mais novo evite ponteiros para classes.
    cout << "\nTrabalhando com ponteiros de objetos\n\n";
    //alocando espaço de memória para o objeto ret2
    ret2 = new Retangulo;
    ret2->setValores(4, 9);
    cout << ret2->area() << endl;

    //liberando a memória usada nos ponteiros
    delete ret2;
    delete[] arrayRetangulo;

}//fim main

/**
 * @brief veja se consegue corrigir os warnings que este código deve gerar. 
 *          Existe aqui um erro proposital de alocação de memória.
 * 
 */