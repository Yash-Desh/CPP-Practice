// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// Q. To print numbers from N to 1 recursively

#include <iostream>
using namespace std;



// Tail Recursion
void printNto1 (int n)
{
    // Base Case 
    if(n == 0){
        return;
    }
        
    cout<<n<<" ";

    printNto1(n-1);
}


// ########################### Other Ways ###########################

// my solution
void LinPrintRev (int N)
{
    if(N>0)
    {
        cout<<N<<endl;
        LinPrintRev(N-1);
    }
}


// striver's solution

void f (int i, int N)
{
    if(i <1)
        return;
    cout<<i<<endl;
    f(i-1, N);
}


// Using Backtracking
void LinPrintRevBT (int i, int N)
{
    if(i>N)
        return;
    LinPrintRevBT(i+1,N);
    cout<<i<<endl;
}


// ########################### Main ###########################

int main()
{
    int x = 5;
    LinPrintRevBT(1,x);

    



    return 0;
}