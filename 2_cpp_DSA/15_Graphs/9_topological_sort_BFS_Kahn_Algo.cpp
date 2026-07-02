// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/6XmzL04mlgQ?si=2dbYNKgivx5KXItI)
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
 * This file: BFS / Kahn's Algorithm approach.
 *   Repeatedly output nodes with in-degree 0 (no remaining dependencies),
 *   then decrement their neighbors' in-degrees. Bonus: if the result has
 *   fewer than V nodes, the graph contains a cycle (cycle detection).
 *   Time: O(V + E), Space: O(V + E).
 * ------------------------------------------------------------------------- */


#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

// --------- COMPLEXITY ----------- // 
// TC : O(N + E)
// SC : O(N + E)
// N = number of vertices
// E = number of edges in the graph
// -------------------------------- // 

void createAdjList(int e, vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList) {
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Directed Graph
        adjList[u].push_back(v);
    }
}

void getIndegree(int v, unordered_map<int, list<int>> &adjList, vector<int> &inDegree) {
    for(auto i: adjList) {
        for(auto j: i.second) {
            inDegree[j]++;
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    // Create Adjacency List
    unordered_map<int, list<int>> adjList;
    createAdjList(e, edges, adjList);


    // Determine indegree of each node. 
    vector<int> inDegree(v);
    getIndegree(v, adjList, inDegree);

    // Vector to store ans
    vector<int> ans;

    // Put all elements with 0-indegree into the queue.
    queue<int> q;
    for(int i=0; i<v; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbor : adjList[front]) {
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return ans;
}

int main() {

    return 0;
}