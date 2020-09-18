#include <iostream> 
#include <list> 
using namespace std;
//graph class for DFS travesal  

class grafoDFS {
    int V;    // No. of vertices 
    list<int>* adjLista;    // adjacency list 
    void DFS_util(int v, bool visitado[]);  // A function used by DFS 
public:
    // class Constructor
    grafoDFS(int V) {
        this->V = V;
        adjLista = new list<int>[V];
    }
    // function to add an edge to graph 
    void addEdge(int v, int w) {
        adjLista[v].push_back(w); // Add w to v’s list.
    }
    void DFS();    // DFS traversal function 
};
void grafoDFS::DFS_util(int v, bool visitado[])
{
    // current node v is visitado 
    visitado[v] = true;
    cout << v << " ";
    // recursively process all the adjacent vertices of the node 
    list<int>::iterator i;
    for (i = adjLista[v].begin(); i != adjLista[v].end(); ++i)
        if (!visitado[*i])
            DFS_util(*i, visitado);
}

// DFS traversal 
void grafoDFS::DFS()
{
    // initially none of the vertices are visitado 
    bool* visitado = new bool[V];
    for (int i = 0; i < V; i++)
        visitado[i] = false;

    // explore the vertices one by one by recursively calling  DFS_util
    for (int i = 0; i < V; i++)
        if (visitado[i] == false)
            DFS_util(i, visitado);
}

int main()
{
    // Create a graph
    grafoDFS grafoteste(5);
    grafoteste.addEdge(0, 1);
    grafoteste.addEdge(0, 3);
    grafoteste.addEdge(1, 2);
    grafoteste.addEdge(2, 3);
    grafoteste.addEdge(3, 4);


    cout << "Depth-first traversal for the given graph:" << endl;
    grafoteste.DFS();

    return 0;
}