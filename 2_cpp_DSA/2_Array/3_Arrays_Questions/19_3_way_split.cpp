// Author : Yash Deshpande
// Date : 02-07-2023
// Tutor : Love Babbar Weekly contest - 1

#include <bits/stdc++.h>
using namespace std;

/*
    Brute Force
    Time Complexity : O(N^2)
    Space Complexity : O(1)

    Where 'N' is the size of the array 'ARR'.
*/

long long threeWaySplit(int n, vector<int> arr)
{
    // Initialize a variable 'ans' with 0.
    long long ans = 0;

    // Initialize a temporary variable 'currSum' with 0.
    long long currSum = 0;

    // Run a loop for checking all the possible pairs.
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        long long tempSum = 0;

        // Adding all the elements from last.
        for (int j = n - 1; j > i; j--)
        {
            tempSum += arr[j];

            if (tempSum >= currSum)
            {
                break;
            }
        }

        if (tempSum == currSum)
        {
            ans = currSum;
        }
    }

    return ans;
}

// My Approach : 2-pointer
// TC : O(N)
// SC : O(1)

#include <bits/stdc++.h>
long long threeWaySplit(int n, vector<int> arr)
{
    // Write your code here.

    // no split is possible if vector has only 1 element
    // return 0 if n=1
    if (n == 1)
        return 0;

    // variable to store max split S1 value
    long long maxSplit = 0;

    // 2-pointers declared & initialized
    int low, high;
    low = 0;
    high = n - 1;

    // S1 & S3 initialized to the 1st value
    long long S1 = arr[0], S3 = arr[n - 1];
    while (low <= high)
    {
        // if the sum S1 & S3 are equal
        if (S1 == S3)
        {
            // Store the newest possible S1 as max Split
            maxSplit = S1;

            // Modify pointers first
            high--;
            low++;

            // Check if the pointers follow conditions
            // if Yes , only then modify S1 & S3
            if (low <= high & high != low)
            {
                S3 += arr[high];
                S1 += arr[low];
            }
        }

        else if (S1 > S3)
        {
            // Modify pointers first
            high--;
            // Check if the pointers follow conditions
            // if Yes , only then modify S1
            if (low <= high)
                S3 += arr[high];
        }

        else
        {
            // Modify pointers first
            low++;
            // Check if the pointers follow conditions
            // if Yes , only then modify S3
            if (low <= high)
                S1 += arr[low];
        }
    }
    return maxSplit;
}

// Same Approch as above : Better written code
/*
    2-Pointer approach
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the size of the array 'ARR'.
*/

long long threeWaySplit(int n, vector<int> arr)
{

    // If only single element is there then we will return 0.
    if (n == 1)
    {
        return 0;
    }

    // Initially assign 0 to 'ans'.
    long long ans = 0;

    // Two pointers which points to our next locations.
    int i = 0;
    int j = n - 1;

    // Sum from ahead.
    long long front = arr[i];
    i++;

    // Sum from back.
    long long last = arr[j];
    j--;

    // Initial Checking if first and last elements are same.
    if (front == last)
    {
        ans = front;
    }

    // Run a loop until 'i' crosses 'j' or vice versa.
    while (i <= j)
    {

        if (front < last)
        {
            front += arr[i];
            i++;
        }
        else
        {
            last += arr[j];
            j--;
        }

        // If a subsegment is found which has same sum.
        if (front == last)
        {
            ans = front;
        }
    }

    return ans;
}

int main()
{

    return 0;
}