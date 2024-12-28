// Author : Yash Deshpande
// Date : 02-08-2023
// Topic : Arrays

#include <bits/stdc++.h>
using namespace std;


// My Approach : Kadane's Algorithm
// AC 
// TC : O(|w| * n)  |w| = length of string W & n = length of char array x
// SC : O(|w|)
string maxSum(string w, char x[], int b[], int n)
{
    // code here
    int sum = 0;
    int ans = INT_MIN;
    string ansStr = "";
    string currentStr = "";
    for (int i = 0; i < w.size(); i++)
    {
        bool flag = false;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (x[j] == w[i])
            {
                flag = true;
                index = j;
            }
        }
        if (flag)
        {
            sum += b[index];
            currentStr += w[i];
        }

        else
        {
            sum += char(w[i]);
            currentStr += w[i];
        }

        if (sum > ans)
        {
            ans = sum;
            ansStr = currentStr;
        }

        if (sum < 0)
        {
            sum = 0;
            currentStr = "";
        }
    }
    return ansStr;
}

int main()
{

    return 0;
}