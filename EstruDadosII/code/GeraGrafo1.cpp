#include <iostream>
#include <random>
#include <chrono>
using namespace std;

//estrutura de dados para vertices
struct Vertice{
  int val;
  Vertice *next; //aponta para o próximo vértice.
};

//estrura de dados para arestas
struct Aresta{
  int src, dest;
};

//classe para a criação da lista
class Grafo{
    //vê o nó da lista
    Vertice* getNestVertice(int dest, Vertice *head){
        Vertice* newVertice = new Vertice; //onteiro temporário 
        newVertice->val = dest;
        newVertice->next=head;
        return newVertice;       
    };
    int vertices; //tamanho do grafo, número de vértices
public: 
  
  Vertice **head; //cria o ponteiro para a lista

  Grafo(Aresta Arestas[], int ares, int vertices){
    //alocando a memória necessária para linked list
    head = new Vertice *[vertices](); //cria a lista
    this->vertices = vertices; //valor de vertices em vertices

    for(int i =0; i < vertices; i++)  //limpo a lista preenchendo todos os vertices com nullptr
      head[i] = nullptr;

    //preenche as arestas para cada vértice
    for(int i=0; i< ares ; i++) {
      int src = Arestas[i].src;
      int dest = Arestas[i].dest;
      //inserir o próximo nó Vertice começo da lista
      Vertice * newVertice = getNestVertice(dest, head[src]);
      head[src]=newVertice;
   } 
  }; //termina o contructor

  //apenas para limpara a memória quando o objeto é desturido  
  ~Grafo(){
    for(int i =0; i< vertices; i++){
        delete[] head[i]; //limpa todas as arestas
    }

    delete[] head; // limpa todos os vértices
  };
};

//para imprimir os vértices indicados nas arestas
void displayAresta(Vertice * ponteiro){
    while(ponteiro != nullptr){
      cout<<" -> "<< ponteiro->val << " ";
      ponteiro = ponteiro->next;
    }
    cout<<endl;
}

//só para debug
void display(int teste [], int comprimento){
  for (int i=0; i<comprimento; i++){
    cout << teste[i] << "\t";
  }
  cout<<endl;
};

int main() {

  int vertices = 100, totalArestas; 
  int conectados= 80; //percentual de vértices conectados.
  int maxArestasVertice = 4;

  //precisa ser multiplicado pelo total de arestas possíveis  por que não
  //queremos mais de uma aresta 
  int totalVertices = vertices * maxArestasVertice;
  int arrayVertices[vertices];
  int totalArrayVertices[totalVertices];
  //calcula o número de arestas 
  totalArestas = vertices * conectados / 100;

  //random_device dev;
  //mt19937_64 mt(dev());
  //uniform_int_distribution<int> dist(0,vertices);

  for(int i = 0; i <= totalVertices; i++){
    mt19937 mt((unsigned) clock());
    uniform_int_distribution<int> dist(1, vertices);
    totalArrayVertices[i]=dist(mt);
  }

  
//para criar o conjunto de vertices, 
Aresta Arestas[(int)totalArestas];
int percorre=0;
  for(int i = 0; i < totalArestas; i++){
    mt19937 mt((unsigned) clock());
    uniform_int_distribution<int> dist(1, 100);
    int numero = dist(mt); 
   

    uniform_int_distribution<int> xdist(0, maxArestasVertice);

    int arestasLocais = xdist(mt) % maxArestasVertice;
    
    if ((arestasLocais > 0) && !((numero > 1) && (numero <= (100 - conectados)))){
      for(int j= 0; j < arestasLocais; j++){
        Arestas[i].src = totalArrayVertices[i];
        Arestas[i].dest = totalArrayVertices[i+j];
      }
      //i+=arestasLocais; 
    }else{
      Arestas[i].src = i;
      Arestas[i].dest = totalArrayVertices[totalVertices-i];
    }
  }

   //cria o grafo 
  Grafo grafo(Arestas, totalArestas, vertices);

  //imprimir o grafo.
  for(int i =0; i < vertices; i++){
    cout << i << " ";
    displayAresta( grafo.head[i]);
  }

  return 0;

}//fim do main