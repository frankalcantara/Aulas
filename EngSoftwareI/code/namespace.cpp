/**
 * @file namespace.cpp
 * @author Frank Alcantara
 * @brief   Exemplo de namespaces em C++
 * @version 0.1
 * @date 2021-01-29
 * 
 * Copyright: Todos os direitos reservados - Tefway - 2021
 * 
 */
#include <iostream>
using namespace std;

/**
 * @brief Namespaces são regiões de código nomeadas para criar um escopo específico.
 *          nesta região podemos definir: nomes para tipos, funções, objetos, etc..
 *          O acesso aos fragmentos de código nestes escopos é feito usando a notação ::
 * 
 */

/**
 * @brief primeiro namespace de teste
 * 
 */
namespace teste1{
    int x = 11;
    void mostre(){
       cout << x << endl;
    }
}
/**
 * @brief segundo namespace de teste
 * 
 */
namespace teste2{
    int x = 25.54;
    void mostre(){
        cout << x << endl;
    }
}

int main(){
    //usando o namespace de teste 1
    teste1::mostre();
    //usando o namespace de teste 2
    teste2::mostre();

    return 0;
}

/**
 * @brief tente colocar dois objetos nestes namaspaces.
 * 
 */