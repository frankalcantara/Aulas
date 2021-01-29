/**
 * @file structs2.cpp
 * @author Frank de Alcantara
 * @brief Mais exemplos com structs
 * @version 0.1
 * @date 2020-11-29
 *
 *
 */
#include <iostream>
#include <iomanip> //só para a formatação do resultado
#include <string>
using namespace std;

const int NUMRECS = 5; //static numero máximo de registros
// em C++ quando criamos uma struct criamos um tipo
struct registroPagamento {

  int id;
  string nome;
  double salHora;
  double horasTrabalhadas;
  //por padrão, por causa da compatibilidade com o C, todos os membros de uma 
  //struct são públicos, em classes, por padrão, todos os membros são privados.
  double calculaSalarioBruto2() {
    return this->salHora * this->horasTrabalhadas;
  }
};

int main() {

  int numEmpregados = 3; // número de empregados
  registroPagamento* registro; // ponteiro, vamos criar um array de structs 

  try {
     //alocando memória para o array
    registroPagamento* registo;
    registro = new registroPagamento[numEmpregados];

  }
  catch (bad_alloc ba) {
   //se entrar aqui é por que não deu certo a alocação
    cout << "Problemas na Alocação de memória." << endl;
    cout << ba.what() << endl; //bad_alloc é um objeto para tratar exceções em C++
    return -1; //sai do main retornando erro -1
  }

  // Se chegamos aqui é porque a alocação de memória funcionou
  //podemos incluir o registro zero do nosso array
  registro->nome = "Frank Alcantara";
  registro->id = 123;
  registro->salHora = 3.93;
  registro->horasTrabalhadas = 4;

  // Podemos incluir o registro 1
  (registro + 1)->nome = "Ana Fonseca";
  (registro + 1)->id = 209;
  (registro + 1)->salHora = 4.98;
  //que tal variar um pouco a forma de entrada de dados
  registro[1].horasTrabalhadas = 30;

  // vamos incluir o registro 2
  registro[2].nome = "Fátima Almeida";
  registro[2].id = 983;
  registro[2].salHora = 4.32;
  //vamos variar novamente
  (registro + 2)->horasTrabalhadas = 5;

  // imprimindo rápidamente
  for (int i = 0; i < numEmpregados; i++) {
    //imprimindo variando a sintaxe da forma de acesso aos membros da 
    //struct
    cout << "Nome: " << registro[i].nome << endl;
    cout << "Identifica: " << (registro + i)->id << endl;
    cout << "Salário Hora: " << registro[i].salHora << endl;
    cout << "Horas Trabalhadas: " << (registro + i)->horasTrabalhadas << endl;
    cout << "Salario Bruto: " << (registro + i)->calculaSalarioBruto2() << endl;
    cout << "\n\n";
  }

  // libera a memória alocada para o array
  delete[] registro;

  return 0;
}

/*
Exercício, modificar este código para não usar a notação de array em lugar nenhum,
gerar dez mil registros aleatórios e aleatóriamente imprimir 10 diferentes.
Não esqueça de transformar todos as propriedades da struct para private.
*/
