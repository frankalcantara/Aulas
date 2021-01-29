/**
 * @file classeConstructorDestructor2.cpp
 * @author Frank de Alcantara
 * @brief  Exemplo de classe, mostrando constructors e destructors
 * @version 0.1
 * @date 2020-07-18
 *
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief apenas para mostrar constructors e destructors
 *
 */
class retangulo {
public:
    int* largura, * altura;
    //constructor
    retangulo(int, int);
    //destructor
    ~retangulo();
    //método comum
    int area() {
        return *largura * *altura;
    }
};

/**
 * @brief Construct a new retangulo::retangulo object
 *
 * @param a - int largura
 * @param b - int altura
 */
retangulo::retangulo(int a, int b) {
    largura = new int;
    altura = new int;
    //não é a melhor opção para isso o melhor seria usar a lista de propriedades.
    //esta é uma forma alternativa que deve ser evitada sempre que possível.
    *largura = a;
    *altura = b;
}
/**
 * @brief Destroy the retangulo::retangulo object
 *
 */
retangulo::~retangulo() {
    delete largura;
    delete altura;
}

int main() {
    //apenas para pegar os valores no terminal
    int largura, altura;
    cout << "digite a largura: ";
    cin >> largura;
    cout << "digite a altura: ";
    cin >> altura;

    //cria dos objetos da classe Retangulo, ambos inicializados via constructor
    retangulo ret1(largura, altura), ret2(2, 3);
    cout << "\n\n";
    //chama o método área de cada objeto.
    cout << ret1.area() << "\t\t" << ret2.area() << endl;
}//fim main