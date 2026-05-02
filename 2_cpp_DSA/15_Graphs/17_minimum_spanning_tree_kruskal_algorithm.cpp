// Author: Yash Deshpande
// Date  : 28-04-2026
// Tutor : Love Babbar (https://youtu.be/KxLtIrCyXwE?si=6QYIhH5Sf3U-Iwvs)
// Link to Question: https://www.naukri.com/code360/problems/minimum-spanning-tree_631769

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include<algorithm>
bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(int n, vector<int> &parent) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Recursive Function to find the parent & also Path Compression
int findParent(int node, vector<int> &parent) {
    // Base Case
    if(parent[node] == node) {
        return node;
    }

    // Path Compression
    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    // Find the parents of both nodes.
    u = findParent(u, parent);
    v = findParent(v, parent);

    // Compare ranks of the parent.
    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[u] < rank[v]){
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    makeSet(n, parent);
    int minWt = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);
        int w = edges[i][2];

        if(u != v) {
            minWt += w;
            unionSet(u, v, parent, rank);
        }
    }
    return minWt;
}