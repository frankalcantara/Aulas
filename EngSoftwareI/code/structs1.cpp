/**
 * @file structs1.cpp
 * @author Frank de Alcantara 
 * @brief Exemplos de structs em c++ sem o uso de métodos.
 * @version 0.1
 * @date 2020-11-29
 * 
 * Copyright: Todos os direitos reservados - Tefway - 2021
 * 
 */
#include <iostream>
#include <iomanip> //só para a formatação do resultado
#include <string>
using namespace std;

const int NUMRECS = 5; //static numero máximo de registros
// em C++ quando criamos uma struct criamos um tipo
struct registroPagamento{
  int id;
  string nome;
  double salHora;
  double horasTrabalhadas;
};

double calculaSalarioBruto(registroPagamento);
//usando ponteiros
double calculaSalarioBruto2(registroPagamento *);

int main(){
  //Definindo de forma estática o array de empregados
  registroPagamento empregados[NUMRECS] = {
    { 1, "Frank Alcantara", 40.72, 22.3 },
    { 2, "Maria Silva", 30.54, 40},
    { 3, "Silvia Maron", 22.56, 12},
    { 4, "Marcela Souza", 18.43, 3.45 },
    { 5, "Sandra Moura", 48.72, 35.7 }
  };

for (int i = 0; i < NUMRECS; i++)
  cout << setw(9) << empregados[i].id
    << setw(20) << empregados[i].nome << setw(6)
    << empregados[i].salHora << setw(10)
    << calculaSalarioBruto(empregados[i])<<endl;

cout<<"\nUsando ponteiros para o cálculo\n";

for (int i = 0; i < NUMRECS; i++)
  cout << setw(9) << empregados[i].id
    << setw(20) << empregados[i].nome << setw(6)
    << empregados[i].salHora << setw(10)
    << calculaSalarioBruto2(&empregados[i])<<endl;
      
return 0;
}
//função para o cálculo do salário
double calculaSalarioBruto(registroPagamento empregado){
  //acessando os membros da struct local
  return empregado.salHora * empregado.horasTrabalhadas;
}
//aqui temos um ponteiro para uma struct
double calculaSalarioBruto2(registroPagamento * ponteiroEmpregado){
  //acessando os membros da struct apontada
 return ponteiroEmpregado->salHora * ponteiroEmpregado->horasTrabalhadas;
} //fim do main
/**
 * @brief Descubra como alinhar a apresentação em tela à esquerda;
 *        Crie uma função para imprimir esta struc na forma correta.
 *        Inclusive com os salários e horas arredondados para duas casas decimais.
 *        Dica: Você terá que passar para essa função um array de structs
 * 
 */
