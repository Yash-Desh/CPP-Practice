// Author: Yash Deshpande
// Date  : 20-04-2026
// Tutor : Love Babbar (https://youtu.be/abIEXKFpLNE?si=SGD6ARQg5rIsVj_K)
// Link to Question: https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297

#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void createAdjList(int m, vector<pair<int,int>> &edges, unordered_map<int, list<int>> &adjList) {
	for(int i=0; i<m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		// Undirected Graph
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Create adjacency list
	unordered_map<int, list<int>> adjList;
	createAdjList(m, edges, adjList);

	// vector<int> parent(n);
    unordered_map<int, int> parent;
	unordered_map<int, bool> visited;
	
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		auto front = q.front();
		q.pop();

		for(auto neighbor: adjList[front]) {
			if(!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
				parent[neighbor] = front;
			}
		}
	}

	vector<int> ans;
	int temp = t;
	ans.push_back(t);
	while(temp != s) {
		temp = parent[temp];
		ans.push_back(temp);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}
