// Author: Yash Deshpande
// Date  : 28-04-2026
// Tutor : Love Babbar (https://youtu.be/rnYBi9N_vw4?si=WmXS7CEUZV_heRrS)
// Link to Question: https://www.naukri.com/code360/problems/prim-s-mst_1095633

// Prim's Algorithm for Minimum Spanning Tree
// Method-1: Using Arrays O(n^2)     --> Previous file
// Method-2: Using min heap O(nlogn) --> This file

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void createAdjList(int m, vector<pair<pair<int, int>, int>> &g, unordered_map<int, list<pair<int, int>>> &adjList) {
    for(int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        // Undirected Graph
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create Adjacency List
    unordered_map<int, list<pair<int, int>>> adjList;
    createAdjList(m, g, adjList);

    // Create data structures required for prim's method.
    // Why n+1 ? Because the nodes are the indices into these vectors
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // Min heap of {key, node} pairs.
    // Default priority_queue is max-heap, so greater<> makes it a min-heap.
    // Pair's first element is the key (weight) so heap is ordered by it.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Algorithm
    // Node-1 is considered the source node
    key[1] = 0;
    parent[1] = -1;
    pq.push({0, 1});

    // Why no fixed iteration count like before?
    // We pop until the heap is empty; stale entries are skipped via the mst check.
    while(!pq.empty()) {
        // Find the node with the least key value in O(logn)
        int u = pq.top().second;
        pq.pop();

        // Skip stale entries (a smaller key for u was processed earlier)
        if(mst[u] == true) continue;

        // Mark this minNode true in the mst vector
        mst[u] = true;

        // Traverse all its adjacent nodes
        for(auto neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
                // Push the updated (key, node) pair; old entry becomes stale
                pq.push({w, v});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    // Why loop starts from 2 ? Because nodes start from 1 but 1st node's parent is -1
    for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}


int main() {

    return 0;
}
