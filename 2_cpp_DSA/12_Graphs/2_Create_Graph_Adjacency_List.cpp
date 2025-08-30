// Author : Yash Deshpande
// Date   : 27-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph 
{
    unordered_map<T, list<T>> adj;
    // NOTE
    // unordered_map<int, set<int>> adjList;
    // Use 'set' instead of a 'list' if you want to traverse in a sorted order.
    public:
    
    // u = source
    // v = destination
    // direction = 0 -> undirected 
    // direction = 1 -> directed
    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i : adj)
        {
            cout<<i.first<<" -> ";
            for(auto j : i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }


};

int main()
{
    graph<int> g;

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

    /*
    Given Edges
    0 1 
    1 2 
    2 3 
    3 1 
    3 4 
    0 4  

    Expected Output
    4 -> 3, 0, 
    3 -> 2, 1, 4, 
    2 -> 1, 3, 
    1 -> 0, 2, 3, 
    0 -> 1, 4, 
    
    */

    return 0;
}