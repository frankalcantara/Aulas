/**
 * @file classe4Metodo2.cpp
 * @author Frank de Alcantara
 * @brief Exemplo mais completo usando constructor e métodos mas não overload.
 * @version 0.1
 * @date 2020-07-12
 * 
 * 
 */
#include <iostream>
using namespace std;  

/**
 * @brief classe com um constructor e quatro métodos
 *        implementa uma calculadora muito, muito simples.
 * 
 */
class Operacao{
  public:
  //propriedades
  int operando1, operando2;
  //constructor
  Operacao(int operandoC1, int operandoC2);
  //métodos
  int soma();
  int subtracao();
  int multiplicacao();
  int divisao();
  void setOperadores(int, int);
};

/**
 * @brief Construct a new Operacao:: Operacao object
 * 
 * @param operandoC1 - int - primeiro operando.
 * @param operandoC2 - int - segundo operando
 */
Operacao::Operacao(int operandoC1, int operandoC2){
  operando1 = operandoC1;
  operando2 = operandoC2;
};

/**
 * @brief realiza uma soma usando as propriedades da classe como memória.
 * 
 * @return int 
 */
int  Operacao::soma(){
  return operando1 + operando2;
};
/**
 * @brief realiza uma subtração usando as propriedades da classe como memória.
 *
 * @return int
 */
int  Operacao::subtracao(){
  return operando1 - operando2;
};
/**
 * @brief realiza uma multiplicação usando as propriedades da classe como memória.
 *
 * @return int
 */
int  Operacao::multiplicacao(){
  return operando1 * operando2;
};
/**
 * @brief realiza uma divisao usando as propriedades da classe como memória.
 *
 * @return int
 */
int  Operacao::divisao(){
  return operando1 / operando2;
};

/**
 * @brief Serve apenas de exemplo método para colocar valores nas propriedades da classe
 * 
 * @param oper1 
 * @param oper2 
 */
void  Operacao::setOperadores(int oper1, int oper2){
  operando1 = oper1;
  operando2 = oper2;
};

//apenas para teste
int main() {
  //cria o objeto calculadora da classe Operacao e guarda os valores 3 e 5 nas propriedades da classe
  Operacao calculadora(3,5);

  //experimente chamar os métodos aqui
  
  //para usar o terminal para definir as operações.
  char operacao;
  int oper1, oper2; 
  
  cout << "digite a operação desejada (+,-,*,/): ";
  cin >> operacao;
  cout << "digite operando 1: ";
  cin >> oper1;
  cout << "digite operando 2: ";
  cin >> oper2;

  calculadora.setOperadores(oper1, oper2);

  switch (operacao){
    case '+': 
        cout << calculadora.soma();
        break;
    case '-': 
        cout << calculadora.subtracao();
        break;
    case '*': 
      cout << calculadora.multiplicacao();
      break;
    case '/':
      if(operacao == '/' && oper2 == 0){
        cout << "Erro divisão por zero";
        break;
      }
      cout << calculadora.divisao();
      break;
  } // fim do switch  

  return 0;
}// fim do main

/**
 * @brief Você precisa modificar esta classe usando templates para fazer uma calculadora 
 *        que trabalhe com inteiros e com reais
 * 
 */