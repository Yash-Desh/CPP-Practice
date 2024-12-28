// Author : Yash Deshpande
// Date : 4-08-2022
// Tutor : CodeWithHarry , Luv , Striver

/*

STACKS  :  LIFO DS 
           some operations are push , pop , top(peek)
           data known regarding stack : stack top & size of stack
           All operations are performed in O(1) i.e constant time on this DS
           size(), swap(), empty() same as queue

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    // declaring 
    stack <int> s;

    // push
    s.push(2);
    s.push(3);
    s.push(4);
    s.emplace(67);
    s.push(12);                  // stack top

    // stack size
    cout<<s.size()<<endl;       // 5

    // clearing a stack
    while( !s.empty())
    {
        cout<<s.top()<<endl;        // top() returns stack top
        s.pop();                    // pop() deletes the stack top
    }

    return 0;
}