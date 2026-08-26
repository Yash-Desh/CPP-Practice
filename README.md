# CPP-Practice
Repository for all the Fundamentals of C++ & DSA practice questions

## C++ Resources
- [Code with Harry](https://youtube.com/playlist?list=PLu0W_9lII9agpFUAlPFe_VNSlXW5uE0YL&si=GdQGto0GKgBFb-CU)
- [The Cherno] (https://youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&si=cpSDSYJaNNzLZBJU)
- [Mike Shah] (https://www.youtube.com/playlist?list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L)
- [Jacob Sorber](https://www.youtube.com/@JacobSorber)

## DSA Tip Sheet
1. Always check for NULL pointers before pointer dereferencing. 
2. Don't Modify input data unless explicitly told to in the question.
3. MinHeap Declaration: 
```priority_queue<int, vector<int>, greater<int>> minHeap;```
4. Sorted Input -> Binary Search
5. Directed Acyclic Graph -> Topological Sort
6. [Graphs] Any linear graph which doesn't have a cycle is bipertite
7. [Graphs] Any graph with an even cycle length can be bipertite. 
8. [Graphs] 4 Axes -> directed, connect, weighted, cyclic
9. [Graphs] Qs mostly never explicitly mention disconnected components so always check for them.
10. [BST] Inorder traversal of BST gives sorted order of input elements. 
11. [Tree] Whenever asked to make a tree, always ask if you can make it manually by creating & attaching nodes.  

## Open Questions
1. [Graphs] Is Dijkstra's Algorithm the same as BFS with unequal weights ? NO
2. [Graphs] Do we need an unordered_map<> to create adjacency list when nodes of a graph
    are number from 0 - n-1 ? 
3. [Graphs] Why does Dijkstra's Algo fail on negative weights ? 
4. [Graphs] Can I use Dijkstra's Algo for DAGs ? Yes if weights are non-negative
5. [Graphs] M-coloring problem vs bipartite graph vs find the min n for an n-partite graph
6. [Graphs] Why is the time/space complexity of BFS/DFS O(n+e)
7. [C++] Some things generate compiler errors, some things just give garbage values like buffer overflow
8. [C++] Pass by reference vs pass by address
9. [x] [C++] Explain why derived data members are inaccessible via a base class pointer ?  
10. [C++] Difference between lambda functions & inline functions

