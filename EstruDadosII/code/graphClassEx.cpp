#include <iostream>
using namespace std;
// stores adjacency list items
struct vertice {
    int valor, custo;
    vertice* proximo;
};
// structure to store arestas
struct aresta {
    int inicia_aresta, termina_aresta, peso;
};
class Digrafo {
    // insert new verticedes into adjacency list from given graph
    vertice* getAdjListverticede(int valorue, int peso, vertice* head) {
        vertice* new_vertice_aresta = new vertice;
        new_vertice_aresta->valor = valorue;
        new_vertice_aresta->custo = peso;

        new_vertice_aresta->proximo = head;   // point new verticede to current head
        return new_vertice_aresta;
    }
    int N;  // number of verticedes in the graph
public:
    vertice** head;                //adjacency list as array of pointers
    // Constructor
    Digrafo(aresta arestas[], int n, int N) {
        // allocate new verticede
        head = new vertice * [N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // construct directed graph by adding arestas to it
        for (unsigned i = 0; i < n; i++) {
            int inicia_aresta = arestas[i].inicia_aresta;
            int termina_aresta = arestas[i].termina_aresta;
            int peso = arestas[i].peso;
            // insert in the beginning
            vertice* new_vertice_aresta = getAdjListverticede(termina_aresta, peso, head[inicia_aresta]);

            // point head pointer to new verticede
            head[inicia_aresta] = new_vertice_aresta;
        }
    }
    // Destructor
    ~Digrafo() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
};
// print all adjacent vertices of given vertex
void display_AdjList(vertice* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "(" << i << ", " << ptr->valor
            << ", " << ptr->custo << ") ";
        ptr = ptr->proximo;
    }
    cout << endl;
}
// graph implementation
int main()
{
    // graph arestas array.
    aresta arestas[] = {
        // (x, y, w) -> edge from x to y with peso w
        {0,1,2},{0,3,4},{1,2,3},{2,3,2},{3,1,4},{3,4,3}
    };
    int N = 5;      // Number of vertices in the graph
    // calculate number of arestas
    int n = sizeof(arestas) / sizeof(arestas[0]);
    // construct graph
    Digrafo Digrafo(arestas, n, N);
    // print adjacency list representation of graph
    cout << "Graph adjacency list " << endl << "(inicia_arestatex, termina_arestatex, peso):" << endl;
    for (int i = 0; i < N; i++)
    {
        // display adjacent vertices of vertex i
        display_AdjList(Digrafo.head[i], i);
    }
    return 0;
}