/**
 * @file 3dfsExemplo.cpp
 * @author desconhecido
 * @brief  Classe para criar um grafo e demonstrar o dfs
 * @version 0.1
 * @date 2020-10-12
 * @mod Frank de Alcantara - 2020-10-20
 */
#include <iostream> 
#include <list> 
using namespace std;

class Grafo {
    int Vertices;           // Número de Vértices
    list<int>* adjLista;    // lista de adjacências para o grafo 
    void DFS_util(int vertice, bool visitado[]);  //o DFS
public:
    /**
     * @brief Constructor para um Objeto da classe Grafo
     *
     * @param Vertices  - inteiro, quantidade de vértices
     */
    Grafo(int Vertices) {
        this->Vertices = Vertices;
        adjLista = new list<int>[Vertices];
    }
    /**
     * @brief Adiciona uma aresta a um vértice
     *
     * @param vertice
     * @param w
     */
    void addAresta(int vertice, int destino) {
        adjLista[vertice].push_back(destino); // cria a aresta entre vertice e destino
    }

    void DFS();    //função para pesquisa transversal no grafo
};
void Grafo::DFS_util(int vertice, bool visitado[]){
    // o vertice corrente vai para a lista de visitados
    visitado[vertice] = true;
    cout << vertice << " ";
    /**
    * @brief De forma recursiva percorremos todos os vértices adjantes a vertice
    * sempre que encontramos um vértice acrescentamos este vértice a lista de visitados
    */
    list<int>::iterator i;
    for (i = adjLista[vertice].begin(); i != adjLista[vertice].end(); ++i)
        if (!visitado[*i])
            DFS_util(*i, visitado);
}

/**
 * @brief Pesquisa transversal em profundidade em Grafo
 *
 */
void Grafo::DFS(){
    //no começo nenhum vértice foi visitado
    bool* visitado = new bool[Vertices];
    for (int i = 0; i < Vertices; i++)
        visitado[i] = false;

    // percorre todos os vertices recursivamente
    for (int i = 0; i < Vertices; i++)
        if (visitado[i] == false)
            DFS_util(i, visitado);
}

#define QUANTOS_VERTICES 5

int main() {
    //Cria um objeto grafoteste com vertices da classe Grafo
    Grafo grafoteste(QUANTOS_VERTICES);
    //preenche o grafo criando arestas para os vértices
    grafoteste.addAresta(0, 1);
    grafoteste.addAresta(0, 3);
    grafoteste.addAresta(1, 2);
    grafoteste.addAresta(2, 3);
    grafoteste.addAresta(3, 4);

    cout << "Lista de vértices percorridos com o DFS:" << endl;
    grafoteste.DFS();

    return 0;
}

/**
 * @brief Modifique este código para gerar um número muito maior de vértices, e arestas, 
 * depois teste o dfs para ver se ele percorre todos os vértices. Lembre-se de contar o tempo
 * necessário para percorrer todo o gráfico.
 * 
 */