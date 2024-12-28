/*
Given T testcases and an array of size of N
Print the sum of array in each test case.

Constraints : 
1 <= T <= 100000
1 <= N <= 100000
1 <= a[i] <= 1000
Sum of N over all test cases is < 10^7

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for(int i=0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
    }
    
    return 0;
}