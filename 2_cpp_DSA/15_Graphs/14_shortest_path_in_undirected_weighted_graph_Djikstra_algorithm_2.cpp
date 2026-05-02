// Author: Yash Deshpande
// Date  : 28-04-2026
// Tutor : Love Babbar (https://youtu.be/dVUR3Rm6biE?si=OTlhaDdKaa352-Nr)
// Link to Question: 

#include <bits/stdc++.h> 

void createAdjList(int edges, vector<vector<int>> &vec, unordered_map<int, list<pair<int, int>>> &adjList) {
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // Undirected Graph
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
}


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create Adjacency List
    unordered_map<int, list<pair<int, int>>> adjList;
    createAdjList(edges, vec, adjList);

    // <nodeDistance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    minHeap.push({0, source});

    while(!minHeap.empty()) {
        auto front = minHeap.top();
        minHeap.pop();

        int nodeDistance = front.first;
        int topNode = front.second;


        for(auto neighbor : adjList[topNode]) {
            int newDistance = distance[topNode] + neighbor.second;
            if(newDistance < distance[neighbor.first]) {
                distance[neighbor.first] = newDistance;
                minHeap.push({newDistance, neighbor.first});
            }
        }
    }
    return distance;

}
