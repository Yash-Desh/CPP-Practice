#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #############################
// TC : O(N) -> time for the entire array to be heapified.
// TC' : O(logN) -> time for each element to reach its correct destination.
// #############################
void heapify(int index, int heapSize, int arr[]) {
    int largest = index;
    int left = 2*index;
    int right = 2*index +1;

    if(left <= heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right <= heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify(largest, heapSize, arr);
    }
    
}

void buildHeap(int heapSize, int arr[]) {

    // for(int i=heapSize/2-1; i>=0; i--) {     --> 0-based indexing 
    for(int i=heapSize/2; i>=1; i--) {      //  --> 1-based indexing 
        heapify(i, heapSize, arr);
    }
}

void printHeap(int heapSize, int arr[]);

int main() {
    // ##########################################
    // Heapify -> convert an array into a maxheap
    // ##########################################
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int heapSize = 5;

    cout<<"Before : ";
    printHeap(heapSize, arr);

    buildHeap(heapSize, arr);       // 54 53 55 52 50

    cout<<"After : ";
    printHeap(heapSize, arr);       // 55 53 54 52 50 

    return 0;
}

void printHeap(int heapSize, int arr[]) {
    for(int i=1; i<=heapSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}