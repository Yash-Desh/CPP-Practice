// Author : Yash Deshpande
// Date : 03-07-2023
// Tutor : Love Babbar Weekly contest - 2

#include <bits/stdc++.h>
using namespace std;

// My Approach : Brute Force
// TC : O(N*Q)
// SC : O(1)
// where N is the length of all the array arr and Q is the number of queries.
vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    // Write your code here.

    // create a vector to store answer
    vector<int> ans;

    // Iterate through each query
    for (int i = 0; i < q; i++)
    {
        // Store each query in variable X
        int X = queries[i];

        // Variable to store & of consecutive elements
        int temp = arr[0];

        // Variable to store index value
        int IND = 0;

        // Check if 1st element is >= X
        if (arr[0] >= X)
            IND = 1;

        // Check for rest of elements sequentially
        for (int j = 1; j < n; j++)
        {
            temp &= arr[j];
            if (temp >= X)
                IND = j + 1;
        }

        // push the index to ans vector
        ans.push_back(IND);
    }
    return ans;
}

// Binary Search

/*
   Time Complexity: O(n+q*logn))
   Space Complexity: O(n)

   where n is the length of all the array arr and q is the number of queries.
*/

vector<int> bitwiseAnd(int n, int q, vector<int> arr, vector<int> queries)
{
    vector<int> answer;
    vector<int> prefix(n, 0);
    prefix[0] = arr[0];

    // Constructing the prefix bitwise and array.
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] & arr[i];
    }

    for (int i = 0; i < q; i++)
    {
        int x = queries[i];
        int st = 0;
        int end = n - 1;
        int count = 0;

        // Binary Searching the largest index IND
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (prefix[mid] >= x)
            {
                count = mid + 1;
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        answer.push_back(count);
    }

    return answer;
}

int main()
{

    return 0;
}