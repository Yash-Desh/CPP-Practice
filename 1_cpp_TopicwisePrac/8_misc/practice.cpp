/*

I tried with brute force , faced TLE & partially solved the problem

Efficient solution
(a[i] + x) % m = (a[i]%m + x%m) % m
find remainders of all a[i] & sort the list 
find remainder of x
compare final remainder for the following 2 cases
1. largest possible remainder in a[i]
2. largest possible remainder in a[i] such that its sum with x is just less than m

*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;
int fact (int n)
    {
        int facto = 1;
        for(int i=1; i<=n; i++)
        {
            facto *= i;
        }
        return facto;
    }

int main()
{
	int x=6;
    cout<<fact(x);
}
