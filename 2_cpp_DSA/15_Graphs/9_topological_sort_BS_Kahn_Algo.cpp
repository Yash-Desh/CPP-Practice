// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/6XmzL04mlgQ?si=2dbYNKgivx5KXItI)
// Link to Question: https://www.naukri.com/code360/problems/topological-sort_982938


#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

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