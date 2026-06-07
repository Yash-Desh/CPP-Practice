// Author: Yash Deshpande
// Date  : 05-04-2026

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public: 
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected 
        // direction = 1 -> directed

        adjList[u].push_back(v);
        if(!direction) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for(auto i: adjList) {
            cout << i.first << "-> ";
            for(auto j: i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;                             // 5
    
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;                             // 6

    cout<<"Enter 1 for directed graph & 0 for undirected graph : ";
    int direction;
    cin>>direction;                     // 0

    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"Specify SOurce & Destination :";
        cin>>u>>v;                      // 0 1 1 2 2 3 3 1 3 4 0 4  

        g.addEdge(u, v, direction);
    }
    g.printAdjList();
    return 0;
}