#include <iostream>
using namespace std;
int main()
{

  //uma variável e seu ponteiro
  int numero = 25; //declara um inteiro e inicializa com o valor 25
  cout << "O valor armazenado em numero é:  " << numero << endl;
  cout << "O endereço de numero é: " << &numero << "\n\n";

  //trabalhando com ponteiros
  int *endNumero;           //declara um ponteiro para um int chamado endNumero
  int kms = 157, dist = 26; //declara dois inteiros e inicializa

  endNumero = &kms; //armazena o endereço de kms em endNumero

  cout << "O endereço armazenado em endNumero é: " << endNumero << endl;
  cout << "O valor apontado por endNumero é: " << *endNumero << "\n";
  cout << "O endereço de endNumero é: " << &endNumero << "\n\n";

  //lêmos *endNumero como o VALOR DE endNumero, ou O VALOR APONTADO POR endNumero
  //Lêmos &endNumero como o Endereço de endNumero

  // Repete o mesmo para a armazenar o endereço de dist em endNumero
  endNumero = &dist;
  cout << "O endereço armazenado em endNumero é:  " << endNumero << endl;
  cout << "O valor apontado por endNumero é: " << *endNumero << endl;
  cout << "O endereço de endNumero é: " << &endNumero << "\n\n";

  //entendendo variáveis e ponteiros
  int total = 20;    //declara e inicializa um identificador inteiro - variável
  int &soma = total; //cria uma referência para total chamada soma: o endereço de soma é igual ao
  //endereço de total.

  cout << "O valor de soma é: " << soma << endl;
  //como soma e total são identificadores para o mesmo endereço na memória
  soma = 5;
  cout << "O valor de total é: " << total << "\n\n"; //mudamos o valor de total alterando o valor de soma

  //mas, precisamos tomar cuidado
  int coisa = 30;         //criamos um identificador para o valor 30. Criamos a variável e inicializamos
  int *endCoisa = &coisa; // endCoisa é um ponteiro que vai armazenar o endereço de coisa.
  cout << "O endereço de coisa é:  " << &coisa << endl;
  cout << "O endereço armazenado em endCoisa é:  " << endCoisa << endl;
  cout << "O valor apontado por endCoisa é: " << *endCoisa << endl;
  cout << "O endereço de endCoisa é: " << &endCoisa << "\n\n";

  *endCoisa = 10;
  cout << "O endereço armazenado em endCoisa é:  " << endCoisa << endl;
  cout << "O valor apontado por endCoisa é: " << *endCoisa << endl;
  cout << "O endereço de endCoisa é: " << &endCoisa << "\n\n";

  cout << "O valor de coisa é: " << coisa << endl;
  cout << "O endereço de coisa é: " << &coisa << "\n\n";

  //para lembrar de arrays
  const int TAMANHOARRAY = 5; //constante para definir o tamanho do array
  //definimos o array
  int notas[TAMANHOARRAY] = {8, 7, 2, 9, 5};
  for (int i = 0; i < TAMANHOARRAY; i++)
    cout << "\nElemento " << i << " é " << notas[i];
  cout << endl;

  cout << "\n\nUsando ponteiros para percorrer um array\n\n";
  //como um array é uma estrutura na memória, podemos utilizar ponteiros para isso
  int *notasPtr;        //primeiro vamos definir um ponteiro para isso
  notasPtr = &notas[0]; //atribuimos a este ponteiro, o endereço do primeiro elemento e notas

  // Agora podemos imprimir
  for (int i = 0; i < TAMANHOARRAY; i++)
    cout << "\nElemento " << i << " é " << *(notasPtr + i);
  //cada elemento de notas é um inteiro
  cout << endl;

  cout << "\n\nAlocação dinâmica\n\n";
  int numNotas;
  cout << "Digite o número de notas que serão processadas: ";
  cin >> numNotas; //lêmos o teclado
  // um ponteiro para um array dinâmico de notas cujo comprimento será dinâmicamente alocado
  // o tamanho deste array será dado pelo valor digitado pelo usuário.
  int *notas2 = new int[numNotas];
  /*
new : reserva o número de bytes necessário para o artefato desejado. E devolve um ponteiro para o tipo definido. No caso um ponteiro do tipo inteiro para a primeira posição de notas2. Se 
não existir memória disponível devolve um valor NULL. Estes dados são armazenados no Heap.
*/

  // vamos criar o array
  for (int i = 0; i < numNotas; i++)
  {
    cout << "Digite a nota: ";
    cin >> notas2[i]; //armazena a nota na posição i do array
  }
  cout << "\nCriamos um array para " << numNotas << " inteiros\n";
  cout << "E neste array armazenamos os seguintes valores:";
  for (int i = 0; i < numNotas; i++)
    cout << "\nNa posição " << i << ": " << notas2[i] << " no endereço: " << &notas2[i];

  cout << endl;

  delete[] notas2; //devolvemos o espaço usado para o heap
  //sempre apague seus arrays, sempre destrua seus objetos.

  //aritmética de ponteiros... lembra deste código?
  cout << "\n\nO array que criamos estáticamente";
  for (int i = 0; i < TAMANHOARRAY; i++)
    cout << "\nElemento " << i << " é " << *(notasPtr + i);
  //cada elemento de notas é um inteiro
  cout << endl;

  //este código funciona por que em (notasPtr + i) estamos somando i no valor de notasPtr e
  //apontando para o próximo valor armazenado no array. Podemos fazer isso mais rápido
  cout << "\n\nPercorrendo um array usando aritmética de ponteiros";
  for (int i = 0; i < TAMANHOARRAY; i++)
    cout << "\nElemento " << i << " é " << *notasPtr++;
  //cada elemento de notas é um inteiro
  cout << endl;

  //como notasPtr aponta para um inteiro, quando somo um a ele, estou somando o endereço de 4bytes
  //um inteiro usa 4bytes na memória

  return 0;
}