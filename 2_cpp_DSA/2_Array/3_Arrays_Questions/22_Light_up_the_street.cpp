#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(M) Just Iterating over checkpoints.
    Space Complexity: O(1)
    where 'M' is the number of ChecKkpoints.
*/

int LightUptheStreet(int n, int m, int k, vector<int> Checkpoints)
{

    // Two variable stores the longest range covers,
    // First checks maximum of all ranges including non selected.
    // Where as last_range stores range of last selected range
    int max_till_now = 0, last_range = 0;

    // Stores answer
    int ans = 0;
    for (int i : Checkpoints)
    {

        // If our last selected range cannot cover the range of
        // our current checkpoint.
        if (i - k - 1 > last_range)
        {

            // If our last all ranges cannot fill our current checkpoint
            // range we know the parts remain without light and its impossible.
            if (i - k - 1 > max_till_now)
            {
                ans = -1;
                break;
            }

            // Now we need to select atleast one previous range to fill the
            // missing non-lighted areas so, answer is incremented and range is Updated.
            ans++;
            last_range = max_till_now;
        }

        // Updating our current maximum range to new.
        max_till_now = i + k;
    }

    // After selecting all ranges accordingly we need to 
    // check if we covered till Nth point
    if (last_range < n)
    {

        // If our both last range and maximum range failed to 
        // do so its impossible. Else we need 1 more light.
        if (max_till_now < n)
        {
            ans = -1;
        }
        else
        {
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}