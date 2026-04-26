// Author: Yash Deshpande
// Date  : 20-04-2026
// Tutor : Love Babbar (https://youtu.be/P_bfy0LOU5g?si=BfbMAgSKqMkbGWCq)
// Link to Question: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include<iostream>
#include<unordered_map>
#include<utility>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;


// User function Template for C++
class Solution {
    
    void createAdjList(vector<vector<int>>& edges, unordered_map<int, list<pair<int, int>>> &adjList) {
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            // Directed Graph with weights
            pair<int, int> p = make_pair(v, w);
            adjList[u].push_back(p);
        }
    }
    
    void topologicalSort(int src, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<pair<int, int>>> &adjList) {
        visited[src] = true;
        
        for(auto neighbor : adjList[src]) {
            if(!visited[neighbor.first]) {
                topologicalSort(neighbor.first, visited, st, adjList);
            }
        }
        st.push(src);
    }
    
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // create adjList
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjList(edges, adjList);
        
        // Topological Sort using DFS
        unordered_map<int, bool> visited;
        stack<int> st;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                topologicalSort(i, visited, st, adjList);
            }
        }
        
        // Calculate distances
        vector<int> distance(V);
        
        int src = 0;
        
        // Set default distance to infinity
        for(int i=0; i<V; i++) {
            distance[i] = INT_MAX;
        }
        
        distance[src] = 0;
        
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            
            if(distance[top] != INT_MAX) {
                for(auto neighbor: adjList[top]) {
                    distance[neighbor.first] = min(distance[neighbor.first], distance[top] + neighbor.second);
                }
            }
        }
        
        for(int &num : distance) {
            if(num == INT_MAX) { num = -1; }
        }
        
        return distance;
    }
};




class Graph {
    unordered_map<int, list<pair<int, int>>> adjList;
    public: 
    void addEdge(int u, int v, int w) {
        pair<int, int> p = make_pair(v, w);
        adjList[u].push_back(p);
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << "-> ";
            for(auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    
};

int main() {
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    return 0;
}