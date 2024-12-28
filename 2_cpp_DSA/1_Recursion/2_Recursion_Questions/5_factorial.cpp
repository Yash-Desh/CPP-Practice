// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

#include <iostream>
using namespace std;

// Recursive Approach
// TC : O(N)

int fact (int N)
{
    if(N == 0)
        return 1;
    return N*fact(N-1);
}

int main()
{
    cout<<fact(6)<<endl;
    return 0;
}