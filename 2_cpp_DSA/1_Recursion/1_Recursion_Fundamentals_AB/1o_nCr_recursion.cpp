// Author : Yash Deshpande 
// Date : 11-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;



// M1 : Using nCr formula and fact function defined earlier
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
}


int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n-r);
    return num/den;
}



// M2 : Using pascal triangle &  nCr = (n-1)C(r-1) + (n-1)Cr 
int NCR (int n, int r)
{
    if (r ==0 || r == n)
    {
        return 1;
    }
    else
    {
        return NCR(n-1,r-1) + NCR(n-1,r);
    }
}

int main()
{
    cout<<nCr(3,2)<<endl;

    cout<<NCR(7,6)<<endl;
    return 0;
}