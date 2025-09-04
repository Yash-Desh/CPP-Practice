// Author : Yash Deshpande
// Date   : 27-08-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, int direction, vector<vector<int>> &adjMat){
    adjMat[u][v] = 1;
    if(direction == 0)
    {
        adjMat[v][u] = 1;
    }
}

void displayAdjMat(vector<vector<int>> &adjMat)
{
    int rows = adjMat.size();
    int cols = adjMat[0].size();

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;                             // 5
    
    cout<<"Enter the number of edges : ";
    int m;
    cin>>m;                             // 6

    cout<<"Enter 1 for directed graph & 0 for undirected graph : ";
    int direction;
    cin>>direction;

    vector<vector<int>>adjMat (n, vector<int>(n, 0));


    for(int i=0; i<m; i++)
    {
        int u,v;
        cout<<"Specify SOurce & Destination :";
        cin>>u>>v;                      // 0 1 1 2 2 3 3 1 3 4 0 4  

        addEdge(u, v, direction, adjMat);
    }

    displayAdjMat(adjMat);


    return 0;
}