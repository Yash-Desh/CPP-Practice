// Author : Yash Deshpande
// Date : 10-02-2023
// Tutor : Striver, Love Babbar

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declaring a deque
    deque <int> dq;

    dq.push_back(1);
    dq.emplace_back(2);
    
    dq.push_front(3);
    dq.emplace_front(4);

    // Before popping elements
    cout<<"front element : "<<dq.front()<<endl;
    cout<<"back element : "<<dq.back()<<endl;

    dq.pop_back();
    dq.pop_front();

    // After popping elements
    cout<<"front element : "<<dq.front()<<endl;
    cout<<"back element : "<<dq.back()<<endl;

    if(dq.empty())
        cout<<"Deque is empty"<<endl;

    else
        cout<<"Deque is not empty"<<endl;


    cout<<"Size before erase "<<dq.size()<<endl;

    // erasing the first element of the deque only
    dq.erase(dq.begin(), dq.begin()+1);

    cout<<"Size after erase "<<dq.size()<<endl;


    // // All the rest of the functions are same as vector
    return 0;
}
