//passagem por referência. Neste caso, passamos o endereço 
#include <iostream>
using namespace std;

//vamos variar usando double
//os argumentos são dois ponteiros para valores double
void troca(double *, double *);
//trabalhando com arrays vamos passar um array de inteiros e um inteiro
int maior(int [], int);
//ou podemos fazer isso com ponteiros
int maior2(int *, int );

//trabalhando com matrizes
void matriz(int (*) [3]);


int main(){
  double primeiroNumero = 8.5, segundoNumero = 1.25;
  
  cout << "O valor armazenado em primeiroNumero é: " << primeiroNumero << endl;
  cout << "O valor armazenado em segundoNumero is: " << segundoNumero << "\n\n";
  
  troca(&primeiroNumero, &segundoNumero);

  cout << "O valor armazenado em primeiroNumero é: " << primeiroNumero << endl;
  cout << "O valor armazenado em segundoNumero is: " << segundoNumero << "\n\n";

  const int NUMNOTAS = 5;
  int notas[NUMNOTAS] = {2, 18, 1, 27, 16};
  cout << "\nO maior valor é: "<< maior(notas,NUMNOTAS) << endl;
  cout << "\nO maior valor usando ponteiros é: "<< maior2(notas,NUMNOTAS) << endl;

  //matrizes
  const int LINHAS = 2;
  const int COLUNAS = 3;
  int nums[LINHAS][COLUNAS] = { {33,16,29}, {54,67,99}};
  matriz(nums);

  return 0;
}//end main

//função para trocar dois valores
void troca(double *enderecoNumero1, double *enderecoNumero2){
  double temp;
  temp = *enderecoNumero1;
  *enderecoNumero1 = *enderecoNumero2;
  *enderecoNumero2 = temp;
  return;
}

int maior(int notas[], int total){
  int maior = notas[0];

  for (int i = 0; i < total; i++)
    if (maior < notas[i])
      maior = notas[i];

return maior;
}
/*
int findmaior(int *notas, int total)
// find the maiorimum value
{
int i, maior = notas[0];
for (i = 1; i < total; i++)
if (maior < notas[i])
maior = notas[i];
return maior;
}

*/

/*
int findmaior(int *notas, int total)
// find the maiorimum value
{
int i, maior = *notas;
for (i = 1; i < total; i++)
if (maior < *(notas + i) )
maior = *(notas + i);
return maior;
}
*/

//fazendo tudo com ponteiros
int maior2(int *notas, int total){
  int maior = *notas;
  for (int i = 0; i < total; i++, notas++)
    if (maior < *(notas))
      maior = *(notas);
return maior;
}

//matriz
void matriz(int (*val) [3]){
  // int nums[LINHAS][COLUNAS] = { {33,16,29}, {54,67,99}};
  cout << endl << *(*val); //equivalente a val[0][0]
  cout << endl << *(*val + 1);//equivalente a val[0][1]
  cout << endl << *(*(val + 1) + 2); //equivalente a val[1][2]
  cout << endl << *(*val) + 1; //equivalente a val[0][0]+1
return;
}

//EXERCÍCIO MATRIZ TRANSPOSTA