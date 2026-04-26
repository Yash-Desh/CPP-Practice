// Author : Yash Deshpande
// Date   : 27-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges

*/


void createAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList) {
    for(int i = 0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Undirected
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &temp) {
    visited[node] = true;
    temp.push_back(node);

    for(auto neighbor : adjList[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adjList, visited, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    createAdjList(edges, adjList);

    // Disconnected
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> temp;
            dfs(i, adjList, visited, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{

}