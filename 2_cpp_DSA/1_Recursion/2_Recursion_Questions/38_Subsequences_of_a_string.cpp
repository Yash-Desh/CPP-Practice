// Author : Yash Deshpande
// Date : 17-07-2023
// Tutor : Striver , Love Babbar

#include <bits/stdc++.h>
using namespace std;

// The number of subsequences of any string of size n = 2^n
// string = "abc"
// ['' a b c ab ac bc abc] are the 8 subsequences

void solve(string str, int index, string temp, vector<string> &ans)
{
    // base case
    if (index == str.size())
    {
        if (temp != "")
        {
            ans.push_back(temp);
        }
        return;
    }

    // pick
    solve(str, index + 1, temp + str[index], ans);

    // not pick
    solve(str, index + 1, temp, ans);
}

vector<string> subsequences(string str)
{
    // Write your code here
    string temp = "";
    int index = 0;
    vector<string> ans;
    solve(str, index, temp, ans);
    return ans;
}




// ################
// Bit Manipulation
// ################

vector<string> subsequences(string str)
{

    // Write your code here
    // Initialize the size of the array
    int size = str.size();
    // Initialize the number of subsets that can be formed
    // = 2^size
    int subsets = 1 << size;

    // vector to store ans
    vector<string> ans;

    // for loop to run for all the numbers
    // 0 to substets-1
    for (int i = 0; i < subsets; i++)
    {
        // temp vector to store current combination
        string temp = "";

        // loop to run for each element in the input array
        for (int j = 0; j < size; j++)
        {
            // Check each bit
            // if set then add that integer to temp
            if ((1 << j) & i)
            {
                temp.push_back(str[j]);
            }
        }
        // store the combination in ans
        if (temp != "")
        {
            ans.push_back(temp);
        }
    }
    // return ans
    return ans;
}

int main()
{

    return 0;
}