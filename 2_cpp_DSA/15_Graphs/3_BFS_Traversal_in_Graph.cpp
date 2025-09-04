// Author : Yash Deshpande
// Date   : 27-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
You are given an undirected & disconnected graph G(V,E) having V vertices 
numbered from 0 to V-1 & E edges. Your task is to print its BFS Traversal
starting from the 0th vertex
*/

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[v].second;

        // Undirected Graph.
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;

    // Push the Node into Queue
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        // Traverse the front node
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int i : adjList[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>>edges)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adjList;

    // NOTE
    // unordered_map<int, set<int>> adjList;
    // Use 'set' instead of a 'list' if you want to traverse in a sorted order.

    // Create Adjacency List.   
    prepareAdjList(adjList, edges);

    // Disconnect Graph: Traverse all components of a graph
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

}