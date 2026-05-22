// Author : Yash Deshpande
// Date   : 27-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// --------- COMPLEXITY ----------- // 
// TC : O(N + E)
// SC : O(N + E)
// N = number of vertices
// E = number of edges in the graph
// -------------------------------- // 

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


/*

---------------------- COMPLEXITY EXPLAINED ---------------------- 

Striver's Explanation: https://youtu.be/-tgVpUgsQ5k?si=I6ds4qnalkGwopmv

TC = O(N + E)
1. Each node gets pushed into the queue once. hence the queue iterates through N   elements. 
2. For each node, the inner for-loop will run on all its neighbors i.e. it runs on all its degrees(degree = no. of neighbor nodes)
Total degrees in a graph = 2*E (proved by striver in graph series video-1)
thus TC = O(N) + O(2*E)


SC = O(N + E)
Space required for queue (N elements), visited array (N elements), Array storing BFS order (N), adjacency list(N+E)
i.e. N + N + N + N + E = 4*N + E

*/ 

