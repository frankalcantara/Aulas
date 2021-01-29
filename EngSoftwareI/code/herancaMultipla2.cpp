
/**
 * @file herancaMultipla2.cpp
 * @author Frank de Alcantara
 * @brief Exemplo de herança múltipla, o exemplo mais simples que consegui pensar.
 * @version 0.1
 * @date 2020-09-15
 * 
 * 
 */
#include <iostream>
using namespace std;

//classes abstratas. 
/**
 * @brief Classe abstrata apenas para guardar dados nas propriedades; 
 *          usa um método protected, método visível apenas para os herdeiros
 *          desta classe
 * 
 */
class Poligono {
protected: //só quem vê esta propriedade é quem herda a classe polígono
    int largura, altura;
public:
    Poligono(int a, int b) : largura(a), altura(b)
    {}
};
/**
 * @brief Outra classe abstrata apenas com o método print
 * 
 */
class Display {
public:
    void print(int i) {
        cout << i << endl;
    }
};

//concretas
/**
 * @brief classes concretas, herdeiras, as classes que usaremos em nossos programas.
 *          no caso a classe Retangulo calcula a área de um retângulo usando propriedades
 *          da classe Poligono e será capaz de imprimir usando um método da classe Display
 * 
 */
class Retangulo : public Poligono, public Display {
public:
    //constructor
    Retangulo(int a, int b) : Poligono(a, b) {}
    //método
    int area() {
        return largura * altura;
    }
};
/**
 * @brief Outra classe concreta, calcula a área de um triangulo, será capaz 
 *          de armazenar os dados nas suas próprias propriedades mas, para 
 *          mostrar o resultado usará o método herdado da classe Display.
 * 
 */
class Triangulo : public Display {
public:
    int largura, altura;
    //constructor
    Triangulo(int largura, int altura) : largura(largura), altura(altura) {}
    //método
    int area() {
        return (largura * altura) / 2;
    }
};

//apenas para testar as classes e a herança
int main() {
    //cria o objeto ret da classe retângulo e inicializa com 7,5 usando o constructor
    Retangulo ret(7, 5);
    //ret usa as propriedades herdadas da classe Poligono para armazenar 7 e 5 e 
    //usa seu próprio método para calcular a área e 
    //passa o resultado do método área para o método print heradado da classe Display
    ret.print(ret.area());

    
    Triangulo tri(7, 5);
    tri.print(tri.area());

}//fim do main

/**
 * @brief Consegue explicar as duas últimas linhas do main?
 * 
 */