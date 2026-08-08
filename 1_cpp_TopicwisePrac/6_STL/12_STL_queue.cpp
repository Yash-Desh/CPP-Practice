// Author : Yash Deshpande
// Date : 10-08-2022
// Tutor : CodeWithHarry , Luv , Striver

/*

QUEUE  :  FIFO DS
          operations on queue are push , pop , front
          All operations are performed in O(1) i.e constant time on this DS
          size(), swap(), empty() same as stack


*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declaration
    queue <string> q;
    q.push("abd");
    q.push("srt");
    q.push("msd");
    q.emplace("gdp");
    q.push("srp");

    // size() 
    cout<<"Size of queue : "<<q.size()<<endl;

    // back()
    cout<<q.back()<<endl<<endl;          // srp

    // empty()
    while(!q.empty())
    {
        // front() access the 1st element of the queue
        cout<<q.front()<<endl; 
        // pop() deletes the front element   
        q.pop();                  
    }

    return 0;
}