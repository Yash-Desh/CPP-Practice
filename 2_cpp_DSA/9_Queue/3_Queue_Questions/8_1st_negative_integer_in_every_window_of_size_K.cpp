// Author : Yash Deshpande
// Date : 16-02-2023
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach-1 : Brute Force, TLE
// TC : O(N*K)
// TLE
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;

    for (long long i = 0; i <= N - K; i++)
    {
        long long value = 0;
        for (long long j = i; j < i + K; j++)
        {
            if (A[j] < 0)
            {
                value = A[j];
                break;
            }
        }
        ans.push_back(value);
    }
    return ans;
}

// Approach - 2 : Queue
// Babbar Approach , AC
// TC : O(N)
// SC : O(K)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    vector<long long> ans;

    deque<long long> dq;

    // Process 1st window of size K
    // Store index of all the negative elements
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }

    // Store answer of 1st K sized window
    if (dq.empty())
        ans.push_back(0);

    else
        ans.push_back(A[dq.front()]);

    // Process for remaining windows
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && (i - dq.front() >= K))
            dq.pop_front();

        // Addition
        if (A[i] < 0)
            dq.push_back(i);

        // Store answer
        if (dq.empty())
            ans.push_back(0);

        else
            ans.push_back(A[dq.front()]);
    }
    return ans;
}

// Approach - 3 : Optimal Approach
// GFG, AC
// TC : O(N)
// SC : O(1)
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    long long firstNegativeIndex = 0;
    long long firstNegativeNumber;
    vector<long long> ans;

    for (int i = K - 1; i < N; i++)
    {
        // slide through the current window till you get a negative element
        while ((firstNegativeIndex < i) && ((firstNegativeIndex <= i - K) || A[firstNegativeIndex] >= 0))
        {
            firstNegativeIndex++;
        }

        if (A[firstNegativeIndex] < 0)
            firstNegativeNumber = A[firstNegativeIndex];

        else
            firstNegativeNumber = 0;

        ans.push_back(firstNegativeNumber);
    }

    return ans;
}

int main()
{

    return 0;
}