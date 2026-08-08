// Author : Yash Deshpande 
// Date : 01-07-2023
// Tutor : Love Babbar

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // creating a max-heap
    priority_queue <int> maxi;

    // creating a min-heap
    priority_queue <int, vector<int>, greater<int>> mini;

    // ############## Operations on a max-heap ##############

    // inserting elements in a max-heap
    maxi.push(14);
    maxi.push(7);
    maxi.push(98);
    maxi.push(-5);
    maxi.push(1);
    maxi.push(10);

    // size of the priority queue
    int maxSize = maxi.size();

    // Displaying priority queue elements
    // Elements are always in sorted array, in priority queue
    // since it is a max-heap, elements are in descending order
    
    for(int i=0; i<maxSize; i++)
    {
        // printing the top-most element
        cout<<maxi.top()<<" ";                // 98 14 10 7 1 -5

        // removing top element
        maxi.pop();
    }
    cout<<endl;


    // check if priority queue is empty
    cout<<"Is the priority queue empty ? "<<maxi.empty()<<endl;



    // ############## Operations on a min-heap ##############

    // inserting elements in a min-heap
    mini.push(14);
    mini.push(7);
    mini.push(98);
    mini.push(-5);
    mini.push(1);
    mini.push(10);

    // size of the priority queue
    int minSize = mini.size();

    // Displaying priority queue elements
    // Elements are always in sorted array, in priority queue
    // since it is a min-heap, elements are in ascending order
    
    for(int i=0; i<minSize; i++)
    {
        // printing the top-most element
        cout<<mini.top()<<" ";                // -5 1 7 10 14 98

        // removing top element
        mini.pop();
    }
    cout<<endl;

    


    return 0;
}