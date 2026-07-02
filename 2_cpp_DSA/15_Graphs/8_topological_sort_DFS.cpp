// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/T_boOrr0rvk?si=3zxHv7s7yxFVeBqF)
// Link to Question: https://www.naukri.com/code360/problems/topological-sort_982938

/* -------------------------------------------------------------------------
 * NOTE: What is Topological Sort? (added by Claude Opus 4.8, 02-07-2026)
 * -------------------------------------------------------------------------
 * A topological sort is a LINEAR ORDERING of the vertices of a Directed
 * Acyclic Graph (DAG) such that for every directed edge u -> v, vertex u
 * appears BEFORE vertex v in the ordering.
 *
 * In plain English: it arranges things so that every dependency comes
 * before the thing that depends on it (e.g. course prerequisites, build
 * order, task scheduling).
 *
 * Key properties:
 *   - Only defined for a DAG (Directed + Acyclic). A cycle => no valid order.
 *   - The ordering is NOT unique; many valid orderings can exist.
 *
 * This file: DFS + Stack approach.
 *   A node is pushed onto the stack ONLY after all of its descendants are
 *   processed. Popping the stack then yields dependencies first.
 *   Time: O(V + E), Space: O(V + E).
 * ------------------------------------------------------------------------- */

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
using namespace std;

void createAdjList(int e, vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList){
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // Directed Graph
        adjList[u].push_back(v);
    }
}

void solve(int node, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, stack<int> &st) {
    visited[node] = true;
    for(auto neighbor : adjList[node]) {
        if(!visited[neighbor]) {
            solve(neighbor, adjList, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // Create Adjacency List
    unordered_map<int, list<int>> adjList;
    createAdjList(e, edges, adjList);

    unordered_map<int, bool> visited;
    stack<int> st;

    // Solve for all disconnected components. 
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            solve(i, adjList, visited, st);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {

    return 0;
}