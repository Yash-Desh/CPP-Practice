// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/1cSzxlhxOw8?si=9h2i1oR2it446w_h)
// Link to Question: https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670


#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void createAdjList(int m, vector<vector<int>>& edges, unordered_map<int, list<int>> &adjList) {
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        // Unordered Map
        adjList[v].push_back(u);
    }
}

bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList) {
    // Parent DS for this component
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(auto neighbor : adjList[front]) {
            if(visited[neighbor] == true && parent[front] != neighbor) {
                return true;
            }
            else if(!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    // Create Adjacency List
    unordered_map<int, list<int>> adjList;
    createAdjList(m, edges, adjList);

    unordered_map<int, bool> visited;
    

    // For disconnected components
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            bool ans = isCyclicBFS(i, visited, adjList);
            if(ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    return 0;
}