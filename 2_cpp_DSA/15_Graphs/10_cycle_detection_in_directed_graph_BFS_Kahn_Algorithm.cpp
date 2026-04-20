// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/X2_tYUuthH8?si=Q-nmU7UA9BydMCbx)
// Link to Question: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

void createAdjList(vector < pair < int, int >> & edges, unordered_map<int, list<int>>& adjList) {
  for(int i=0; i<edges.size(); i++) {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    // Directed Graph
    adjList[u].push_back(v);
  }
}

void countIndegree(unordered_map<int, list<int>> &adjList, vector<int> &inDegree) {
  for(auto i : adjList) {
    for(auto j: i.second) {
      inDegree[j]++;
    }
  }
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  // Create Adjacency List
  unordered_map<int, list<int>> adjList;
  createAdjList(edges, adjList);

  // Count indegree
  vector<int> inDegree(n);
  countIndegree(adjList, inDegree);

  // Insert nodes with indegree = 0 in the queue
  queue<int> q;
  for(int i=0; i<n; i++) {
    if(inDegree[i] == 0) {
      q.push(i);
    }
  }

  int nodeCnt = 0;
  while(!q.empty()) {
    auto front = q.front();
    q.pop();
    nodeCnt++;

    for(auto neighbor : adjList[front]) {
      inDegree[neighbor]--;
      if(inDegree[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  return !(nodeCnt == n);
}

int main() {

    return 0;
}