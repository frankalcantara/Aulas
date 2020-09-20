#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void displayAdjList(list<int> adj_list[], int v) {
    for (int i = 0; i < v; i++) {
        cout << i << "--->";
        list<int> ::iterator it;
        for (it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}
void add_edge(list<int> adj_list[], int origem, int destino) {    //add v into the list u, and u into list v
    adj_list[u].push_back(origem);
    adj_list[v].push_back(destino);
}
int main(int argc, char* argv[]) {
    int v = 6;    //there are 6 vertices in the graph
    //create an array of lists whose size is 6
    list<int> adj_list[v];
    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 3);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 2, 3);
    add_edge(adj_list, 3, 4);

    displayAdjList(adj_list, v);
}