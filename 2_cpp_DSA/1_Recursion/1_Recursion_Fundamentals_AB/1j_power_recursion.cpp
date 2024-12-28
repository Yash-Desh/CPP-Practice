// Author : Yash Deshpande
// Date : 11-04-2022
// Tutor : Abdul Bari , Love Babbar

#include <iostream>
using namespace std;

// Power Function

// M1 : Naive Approach
int pow1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return pow1(m, n - 1) * m;
    }
}

// M2 : Efficient Method
// Tail Recursion
int pow2(int m, int n)
{
    // Base Case
    if (n == 0)
        return 1;

    // Recurance Relation

    // when the exponent is even
    if (n % 2 == 0)
        return pow2(m * m, n / 2);

    // when the exponent is odd
    else
        return m * pow2(m * m, (n - 1) / 2);
}



// M3 : Another way to code M2
// Love Babbar official method
// Note : I like M2 better
// Head Recursion
int power(int a, int b)
{
    // base case
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    // RECURSIVE CALL
    int ans = power(a, b / 2);

    // if b is even
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        // if b is odd
        return a * ans * ans;
    }
}

int main()
{
    // cout<<pow1(2,9)<<endl;

    cout << pow2(2, 7) << endl;

    return 0;
}