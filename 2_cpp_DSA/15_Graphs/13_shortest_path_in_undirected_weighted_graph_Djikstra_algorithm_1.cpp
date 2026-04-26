// Author: Yash Deshpande
// Date  : 25-04-2026
// Tutor : Love Babbar (https://youtu.be/dVUR3Rm6biE?si=OTlhaDdKaa352-Nr)
// Link to Question: https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469

// Dijkstra's Algorithm can be solved using 2 different data structures
// 1. set       --> THIS file
// 2. min heap  --> next file

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<climits>
#include<list>
#include<utility>
using namespace std;

void createAdjList(int edges, vector<vector<int>> &vec, unordered_map<int, list<pair<int, int>>> &adjList) {
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // Undirected Graph
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    createAdjList(edges, vec, adjList);

    // <<nodeDistance, topNode>>
    set<pair<int, int>> s;
    s.insert(make_pair(0, source));

    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    while(!s.empty()) {
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        s.erase(top);

        for(auto neighbor : adjList[topNode]) {
            int newDistance = nodeDistance + neighbor.second;
            if(newDistance < distance[neighbor.first]) {
                if(s.find(make_pair(distance[neighbor.first], neighbor.first)) != s.end()) {
                    s.erase(make_pair(distance[neighbor.first], neighbor.first));
                }
                s.insert(make_pair(newDistance, neighbor.first));
                distance[neighbor.first] = newDistance;
            }
        }
    }
    return distance;
}

int main() {

    return 0;
}
