/**
 * @file GeraGrafo1.cpp
 * @author Frank de Alcantara
 * @brief  Geração de grafos sem nenhuma regra de formação, além da aleatoriedade
 * @version 0.1
 * @date 2020-10-10
 */
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

/**
 * @brief estrutura de dados dos vértices, com um dado inteiro
 *
 */
struct Vertice {
  int val;
  Vertice* next; //aponta para o próximo vértice.
};

/**
 * @brief Estrutura de dados para as arestas
 *
 */
struct Aresta {
  int src, dest;
};


class Grafo {
    //vê o vértice da lista
  Vertice* getNestVertice(int dest, Vertice* head) {
    Vertice* newVertice = new Vertice; //ponteiro temporário 
    newVertice->val = dest;
    newVertice->next = head;
    return newVertice;
  };
  int vertices; //tamanho do grafo, número de vértices
public:

  Vertice** head; //cria o ponteiro para a lista

  /**
   * @brief Constructor de um objeto da classe Grafo
   *
   * @param Arestas - conjunto de arestas
   * @param numAres - número de arestas
   * @param vertices  - número de vértices
   */
  Grafo(Aresta Arestas[], int numAres, int vertices) {
    //alocando a memória necessária para a linked list
    head = new Vertice * [vertices]();   //cria a lista
    this->vertices = vertices;          //valor de vertices em vertices

    for (int i = 0; i < vertices; i++)    //limpa a lista preenchendo todos os vertices com nullptr
      head[i] = nullptr;

    //preenche as arestas para cada vértice
    for (int i = 0; i < numAres; i++) {
      int src = Arestas[i].src;
      int dest = Arestas[i].dest;
      //inserir o próximo nó Vertice começo da lista
      Vertice* newVertice = getNestVertice(dest, head[src]);
      head[src] = newVertice;
    }
  }; //termina o contructor

  //destructor - apenas para limpar a memória quando o objeto é desturido  
  ~Grafo() {
    for (int i = 0; i < vertices; i++) {
      delete[] head[i]; //limpa todas as arestas
    }
    delete[] head; // limpa todos os vértices
  };
};

/**
 * @brief Mostra as arestas no terminal - só para debug
 *
 * @param ponteiro - aponta para a raiz do grafo
 */
void displayAresta(Vertice* ponteiro) {
  while (ponteiro != nullptr) {
    cout << " -> " << ponteiro->val << " ";
    ponteiro = ponteiro->next;
  }
  cout << endl;
}

/**
 * @brief Mostra os vértices no terminal - só para debug
 *
 * @param teste
 * @param comprimento
 */
void display(int teste[], int comprimento) {
  for (int i = 0; i < comprimento; i++) {
    cout << teste[i] << "\t";
  }
  cout << endl;
};

#define TOTALVERTICES 100


int main() {

  int vertices = TOTALVERTICES, totalArestas;
  int conectados = 80; //percentual de vértices conectados.
  int maxArestasVertice = 4;

  /**
  * @brief precisa ser multiplicado pelo total de arestas possíveis,
  * não ueremos mais de uma aresta
  */
  int totalVertices = vertices * maxArestasVertice;
  int arrayVertices[vertices];
  int totalArrayVertices[totalVertices];
  //calcula o número de arestas 
  totalArestas = vertices * conectados / 100;

  for (int i = 0; i <= totalVertices; i++) {
    mt19937 mt((unsigned)clock());
    uniform_int_distribution<int> dist(1, vertices);
    totalArrayVertices[i] = dist(mt);
  }

  //para criar o conjunto de vertices, 
  Aresta Arestas[(int)totalArestas];

  int percorre = 0;
  for (int i = 0; i < totalArestas; i++) {

    mt19937 mt((unsigned)clock());
    uniform_int_distribution<int> dist(1, 100);
    int numero = dist(mt);

    uniform_int_distribution<int> xdist(0, maxArestasVertice);

    int arestasLocais = xdist(mt) % maxArestasVertice;

    if ((arestasLocais > 0) && !((numero > 1) && (numero <= (100 - conectados)))) {
      for (int j = 0; j < arestasLocais; j++) {
        Arestas[i].src = totalArrayVertices[i];
        Arestas[i].dest = totalArrayVertices[i + j];
      }
      //i+=arestasLocais; 
    }    
else {

      Arestas[i].src = i;
      Arestas[i].dest = totalArrayVertices[totalVertices - i];
    }
  }

  //cria o objeto da classe grafo 
  Grafo grafo(Arestas, totalArestas, vertices);

  //imprimir o grafo.
  for (int i = 0; i < vertices; i++) {
    cout << i << " ";
    displayAresta(grafo.head[i]);
  }
  return 0;
}//fim do main