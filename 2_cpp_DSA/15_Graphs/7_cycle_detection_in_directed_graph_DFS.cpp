// Author: Yash Deshpande
// Date  : 19-04-2026
// Tutor : Love Babbar (https://youtu.be/Tl5qbEmEQyY?si=OxwfPDPT-9bkWkcY)
// Link to Question: https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void createAdjList(vector < pair < int, int >> & edges, unordered_map<int, list<int>> &adjList) {
  for(int i=0; i<edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    // Directed Graph
    adjList[u].push_back(v);
  }
}

bool checkCycleDFS(int src, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
  visited[src] = true;
  dfsVisited[src] = true;

  for(auto neighbor : adjList[src]) {
    if(!visited[neighbor]) {
      bool cycleDetected = checkCycleDFS(neighbor, adjList, visited, dfsVisited);
      if(cycleDetected) {
        return true;
      }
    }
    else if(dfsVisited[neighbor]) {
      return true;
    }
  }
  dfsVisited[src] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  // Create adjacency list. 
  unordered_map<int, list<int>> adjList;
  createAdjList(edges, adjList);

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;
  for(int i=1; i<=n; i++) {
    if(!visited[i]) {
      bool cycleFound = checkCycleDFS(i, adjList, visited, dfsVisited);
      if(cycleFound) {
        return 1;
      }
    }
  } 
  return 0;
}

int main() {
    return 0;
}