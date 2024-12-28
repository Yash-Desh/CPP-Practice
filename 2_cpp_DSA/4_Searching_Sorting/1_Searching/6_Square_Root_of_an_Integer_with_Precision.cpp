// Author : Yash Deshpande
// Date : 28-08-2022
// Tutor : Love Babbar
// Platform : Leetcode / Coding Ninjas

// Q. Find square root of an integer using O(log n) up till given precision
//    Find square root of an integer using Binary Search

// Part-1 : Only the integer part of the square root

// My Approach
// Used built-in sqrt() function
// Limitation : Can only be used on small integers
long long int floorSqrt(long long int x)
{
    // Your code goes here
    long long int ans;

    ans = sqrt(x);
    return ans;
}

// Brute Force Approach
// Loop from 1 till the given number n
// find the square of each value &
// compare it with the given n
// whenever the square exceeds the given n
// thats your square root
// Limitation : TLE

long long int floorSqrt(long long int x)
{
    // Your code goes here
    long long int cnt = 0;
    long long int square = 0;

    while (square <= x)
    {
        cnt++;
        square = cnt * cnt;
    }
    return cnt - 1;
}

int mySqrt(int x)
{
    long long int ans = 0;
    for (long long int i = ans; i * i <= x; i++)
    {
        ans = i;
    }
    return ans;
}

// Optimal Solution
// Using Binary Search
// TC : O(logn)
// SC : O(1)

int SqrtInt(int x)
{
    int l = 0;
    int h = x;
    long long mid, ans;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (mid * mid == x)
        {
            return mid;
        }

        else if (mid * mid < x)
        {
            // when we find a value which is less than given number
            // it could be a possible solution in case of numbers
            // which are not perfect squares
            ans = mid;
            l = mid + 1;
        }

        else if (mid * mid > x)
        {
            h = mid - 1;
        }
    }
    return ans;
}

// Part-2: To find the precision

// Brute force Approach
double addPrecision(int x, int precision, int tempSol)
{
    double ans = tempSol;
    double factor = 1;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < x; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    cout << "Square root of " << num << " uptil 3rd precision is " << addPrecision(num, 3, SqrtInt(num)) << endl;
    return 0;
}
