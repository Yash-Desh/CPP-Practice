// Author : Yash Deshpande
// Date   : 04-09-2025
// Tutor  : Love Babbar

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Heaps are represented as arrays.
// We are following a 1-based indexing.
// The 0th element in the array is not used.

// #############################
// MAX HEAP
// #############################
class Heap {
    public:
    int arr[100];
    int size; 

    Heap() {
        // 1-based indexing
        arr[0] = -1;
        size = 0;
    }

    // #############################
    // TC : O(logN) -> Each element is compared with its parent
    // #############################
    void insert(int val) {
        // Every new element is inserted 
        // at the end of the array.
        size += 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            // Get the index of the parent node.
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // #############################
    // This function can delete the root of the heap
    // Remember we don't store anything at the 0th index of the arr
    // The root of the heap is present at the 1st index.
    // TC : O(logN) -> Each element is compared with its children
    // #############################
    void deleteFromHeap() {
        // Base Case.
        if(size == 0) {
            cout<<"Heap is empty, nothing to delete\n";
            return;
        }

        // Replace the last element into the deleted position.
        arr[1] = arr[size];
        size--;

        // Place the reordered element at the correct location.
        int i = 1;
        while(i < size) {
            // Get the index of the left & right child nodes.
            int left_index = 2*i;
            int right_index = 2*i+1;

            if(left_index < size && arr[left_index] > arr[i]) {
                swap(arr[left_index], arr[i]);
                i = left_index;
            }
            else if(right_index < size && arr[right_index] > arr[i]) {
                swap(arr[right_index], arr[i]);
                i = right_index;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
};

// #############################
// TC : O(N) -> time for the entire array to be heapified.
// TC' : O(logN) -> time for each element to reach its correct destination.
// #############################
void heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// #############################
// TC : O(N*logN) -> time for the entire array to be heapified.
// #############################
void heapSort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        // Swap the last & first element.
        swap(arr[1], arr[size]);
        size--;

        // Place the first element at its correct location.
        heapify(arr, size, 1);
    }
}



int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();          // 55 54 53 50 52

    /*
         55
        /  \
      54    53
     /  \
    50  52
    */

    h.deleteFromHeap();
    h.print();          // 54 52 53 50
    /*
         54
        /  \
      52    53
     /  
    50  
    */

    // ##########################################
    // Heapify -> convert an array into a maxheap
    // ##########################################
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Leaf nodes are already present in the correct heap order.
    // Leaf nodes will not be processed in the heapify algorithm.
    // Array indices from n/2 to n-1 are all leaf nodes.
    for(int i = n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    // Displaying the heapified array
    cout<<"\nPrinting the heapified array now\n";
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;         // 55 53 54 52 50 
    /*
         55
        /  \
      53   54
     /  \
    52   50
    */

    // ###########
    // Heap Sort
    // ###########
    heapSort(arr, n);
    cout<<"\nPrinting the sorted array now\n";
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl; 


    // ###################################
    // Using Priority Queue to create Heap
    // ###################################

    // Max Heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"\nRoot of the Max Heap "<<pq.top()<<endl;

    cout<<"Size of heap is "<<pq.size()<<endl;

    if(pq.empty()) {
        cout<<"Heap is empty\n";
    }
    else {
        cout<<"Max Heap is NOT empty\n";
    }

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"\nRoot of the Min Heap "<<minHeap.top()<<endl;

    cout<<"Size of heap is "<<minHeap.size()<<endl;

    if(minHeap.empty()) {
        cout<<"Heap is empty\n";
    }
    else {
        cout<<"Min Heap is NOT empty\n";
    }

    return 0;
}