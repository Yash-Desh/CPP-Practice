#include <iostream>
using namespace std;

class Heap {
    int size;
    int arr[100];

    public:
    Heap() {
        size = 0;
        arr[0] = -1;
    }

    void insert(int value);
    void remove();
    void print();
};

void Heap::print() {
    for(int i=1; i<=size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Heap::insert(int value) {
    // Check size 
    if(size == 100) {
        cout<<"heap is full\n";
        return;
    }

    // New element placed at the last index
    size++;
    int index = size;
    arr[index] = value;

    while(index > 1) {
        int parent = index/2;
        if(arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else break;
    }
}

void Heap::remove() {
    // Check if heap is empty
    if(size == 0) {
        return;
    }

    // Place last element at top;
    arr[1] = arr[size];
    size--;

    // Move this element to its correct spot
    int index = 1;
    while(index < size) {
        int left = 2*index;
        int right = 2*index+1;

        if(left < size && (arr[left] > arr[index])) {
            swap(arr[left], arr[index]);
            index = left;
        }
        else if(right < size && (arr[right] > arr[index])) {
            swap(arr[right], arr[index]);
            index = right;
        }
        else break;
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

    h.remove();
    h.print();          // 54 52 53 50
    /*
         54
        /  \
      52    53
     /  
    50  
    */
    return 0;
}