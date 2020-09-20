#include <iostream>
using namespace std;

// Data structure to store Adjacency list Nos
struct No {
    int val;
    No* next;
};

// Data structure to store Grafo Arestas
struct Aresta {
    int src, dest;
};

class Grafo
{
    // Function to allocate new No of Adjacency List
    No* getAdjListNo(int dest, No* head)
    {
        No* newNo = new No;
        newNo->val = dest;

        // point new No to current head
        newNo->next = head;

        return newNo;
    }

    int N;  // number of Nos in the Grafo

public:

    // An array of pointers to No to represent
    // adjacency list
    No** head;

    // Constructor
    Grafo(Aresta Arestas[], int n, int N)
    {
        // allocate memory
        head = new No * [N]();
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; i++)
            head[i] = nullptr;

        // add Arestas to the directed Grafo
        for (unsigned i = 0; i < n; i++)
        {
            int src = Arestas[i].src;
            int dest = Arestas[i].dest;

            // insert in the beginning
            No* newNo = getAdjListNo(dest, head[src]);

            // point head pointer to new No
            head[src] = newNo;

            // Uncomment below lines for undirected Grafo

            /*
            newNo = getAdjListNo(src, head[dest]);

            // change head pointer to point to the new No
            head[dest] = newNo;
            */
        }
    }

    // Destructor
    ~Grafo() {
        for (int i = 0; i < N; i++)
            delete[] head[i];

        delete[] head;
    }
};

// print all neighboring vertices of given vertex
void printList(No* ptr)
{
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Grafo Implementation in C++ without using STL
int main()
{
    // array of Grafo Arestas as per above diagram.
    Aresta Arestas[] = {
        // pair (x, y) represents Aresta from x to y
        { 0, 1 }, { 0, 4 }, { 1, 2 }, { 2, 3 },
        { 3, 4 }
    };

    // Number of vertices in the Grafo
    int N = 6;

    // calculate number of Arestas
    int n = sizeof(Arestas) / sizeof(Arestas[0]);

    // construct Grafo
    Grafo Grafo(Arestas, n, N);

    // print adjacency list representation of Grafo
    for (int i = 0; i < N; i++)
    {
        // print given vertex
        cout << i << " ";

        // print all its neighboring vertices
        printList(Grafo.head[i]);
    }

    return 0;
}