// Author : Yash Deshpande
// Date : 5-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Approach - 1, Brute Force-Method:1 , AC
// My Approach
// TC : O(N^2)
// SC : O(N)

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    int arr[n] = {0};

    // loop to store the count of number of
    // persons who know a particular person
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                arr[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == n - 1)
        {
            // if all persons know this person
            bool celebrity = true;
            for (int j = 0; j < n; j++)
            {
                // check if this person knows
                // no other persons
                if (M[i][j] == 1)
                {
                    celebrity = false;
                }
            }
            if (celebrity)
                return i;
        }
    }
    return -1;
}

// Approach - 1, Brute Force-Method:2 , AC
// Love Babbar Approach
// TC : O(N^2)
// SC : O(1)
// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    // code here

    // Condition-1 : All persons know Celebrity
    //               (Celebrity col -> All 1s except diagonal element)
    // Condition-2 : Celebrity knows no one
    //               (Celebrity row -> All 0s)

    // loop to check each person
    for (int i = 0; i < n; i++)
    {
        // loop to check  row
        bool celebRow = true;
        bool celebCol = true;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                celebRow = false;
                break;
            }
        }

        // loop to check col
        if (celebRow)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && M[j][i] == 0)
                {
                    celebCol = false;
                    break;
                }
            }
        }

        if (celebRow && celebCol)
            return i;
    }
    return -1;
}

// Better Approach , Stack
// TC : O(N)
// TC : O(N)
bool knows(int a, int b, vector<vector<int>> &M)
{
    // if a knows b
    if (M[a][b] == 1)
        return true;
    else
        return false;
}

// Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int>> &M, int n)
{
    // code here

    // Put all elements in stack
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Compare 2 elements at a time till
    // stack contains atmost 1 element
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (knows(a, b, M))
            st.push(b);
        else
            st.push(a);
    }

    // Last element of the stack is
    // a potential candidatate to be a
    // celebrity
    // verify it
    int candidate = st.top();

    // celeb row -> all zeros
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 1)
        {
            return -1;
        }
    }

    // celeb col -> All ones except diagonal elements
    for (int i = 0; i < n; i++)
    {
        if (i != candidate && M[i][candidate] == 0)
        {
            return -1;
        }
    }
    return candidate;
}

int main()
{

    return 0;
}