// Author: Yash Deshpande
// Date  : 26-04-2026
// Tutor : NeetCode
// Link to Question: https://leetcode.com/problems/redundant-connection

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Brute-Force Solution
// Take out an edge each time & check whether you have a loop with no disconnected component
class Solution1 {

    void createAdjList(vector<vector<int>>& edges, unordered_map<int, list<int>> &adjList) {
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    // Instead of returning bool, return the cycle edges via a reference parameter
    bool isCyclicDFS(int src, int parent,
                    unordered_map<int, bool> &visited,
                    unordered_map<int, list<int>> &adjList,
                    unordered_map<int, int> &parentMap,        // NEW: track parent of each node
                    vector<vector<int>> &cycleEdges) {       // NEW: output edges
        visited[src] = true;
        parentMap[src] = parent;

        for(auto neighbor : adjList[src]) {
            if(!visited[neighbor]) {
                bool cycleDetected = isCyclicDFS(neighbor, src, visited, adjList, parentMap, cycleEdges);
                if(cycleDetected) return true;
            }
            else if(neighbor != parent) {
                // Cycle found! Trace back from src to neighbor using parentMap
                cycleEdges.push_back({src, neighbor});  // the closing edge
                int cur = src;
                while(cur != neighbor) {
                    int p = parentMap[cur];
                    cycleEdges.push_back({cur, p});
                    cur = p;
                }
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        // create Adjacency list
        unordered_map<int, list<int>> adjList;
        createAdjList(edges, adjList);

        unordered_map<int, int> parentMap;
        vector<vector<int>> cycleEdges;

        unordered_map<int, bool> visited;
        bool hasCycle = isCyclicDFS(1, -1, visited, adjList, parentMap, cycleEdges);

        for(int i = edges.size(); i >= 0; i--) {
            vector<int> edge = edges[i];
            auto it = find(cycleEdges.begin(), cycleEdges.end(), edge);

            if(it != cycleEdges.end()) {
                return edge;
            }

            reverse(edge.begin(), edge.end());
            it = find(cycleEdges.begin(), cycleEdges.end(), edge);
            if(it != cycleEdges.end()) {
                return edges[i];
            }
        }
        return ans;
    }
};


class Solution {
    void makeSet(int n, vector<int> &parent) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(vector<int> &parent, int node) {
        // Base Case
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v]) { parent[u] = v; }
        else if(rank[u] > rank[v]) { parent[v] = u; }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 0);

        makeSet(n, parent);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int u = findParent(parent, edges[i][0]);
            int v = findParent(parent, edges[i][1]);

            if(u != v) {
                unionSet(u, v, parent, rank);
            }
            else {
                return ans = edges[i];
            }
        }
        return ans;
    }
};