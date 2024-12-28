// Author : Yash Deshpande 
// Date : 15-08-2022
// Tutor : Striver

// Q. Print the numbers 1 to N linearly using Recursion

#include <iostream>
using namespace std;


// Head Recursion
void print1ToN (int n)
{
    // Base Case
    if(n == 0){
        return;
    }

    print1ToN(n-1);

    cout<<n<<" ";
}





// my solution <==> striver's solution
void LinPrint (int i, int N)
{
    if(i > N)
        return;
    cout<<i<<endl;
    LinPrint(i+1, N);
}


// Using backtracking 

// My solution
void LinPrintBT1 (int N)
{
    if(N<1)
        return;
    LinPrintBT1(N-1);
    cout<<N<<endl;
}

// striver's solution
// notice that its the same as my method but n is an unused variable
void LinPrintBT(int i, int n)
{
    if(i < 1)
        return;
    
    LinPrintBT(i-1, n);
    cout<<i<<endl;
}



int main()
{
    int x = 15;
    LinPrintBT1( x);
    return 0;
}