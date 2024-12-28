// Author : Yash Deshpande
// Date : 08-07-2023
// Tutor : Love Babbar
// Website : LeetCode



// ######################## Sieve of Eratosthenes Algorithm to Count Primes ########################



#include <bits/stdc++.h>
using namespace std;

// My Approach : Brute Force
// TLE
// TC : O(N^3/2)
// SC : O(1)
int countPrimes(int n)
{
    int cntOfPrimes = 0;
    for (int i = 2; i < n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cntOfPrimes++;
        }
    }
    return cntOfPrimes;
}




// Optimal Approach
// Sieve of Eratosthenes
// Babbar Approach
// TC : O(N * log(log(N)))
int countPrimes(int n)
{
    int cnt = 0;
    // consider all numbers prime
    vector<bool> prime(n + 1, true);

    // set 0 & 1 as false
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;

            // set all multiples of that number as false
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
    return cnt;
}

int main()
{

    return 0;
}