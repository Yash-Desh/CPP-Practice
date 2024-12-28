// Author : Yash Deshpande
// Date : 3-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// My Appproach : Brute Force
// TLE
// TC : O(N^3)
// SC : O(1)
int largestRectangleArea(vector<int> &heights)
{
    int ans = 0;
    // for each tower
    for (int i = 0; i < heights.size(); i++)
    {
        // for each unit of height of the current tower
        for (int j = 1; j <= heights[i]; j++)
        {
            int rectangle = 0;
            // for all the towers which are greater than or equal
            // to the current unit of height
            for (int k = i; k < heights.size(); k++)
            {
                if (heights[k] >= j)
                {
                    rectangle += j;
                    ans = max(rectangle, ans);
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ans;
}

// Approach-2 : Better Brute Force
// Babbar Approach
// TLE
// TC : O(N^2)
// SC : O(1)
int largestRectangleArea(vector<int> &heights)
{
    int maximum = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int current = heights[i];
        int j = i - 1;
        while (j >= 0 && heights[j] >= heights[i])
        {
            current += heights[i];
            j--;
        }

        j = i + 1;
        while (j < heights.size() && heights[j] >= heights[i])
        {
            current += heights[i];
            j++;
        }

        if (current > maximum)
            maximum = current;
    }
    return maximum;
}

// Approach - 3 : Optimal Solution
// AC
vector<int> nextSmallerElement(vector<int> &heights, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int num = heights[i];
        while (st.top() != -1 && heights[st.top()] >= num)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> previousSmallerElement(vector<int> &heights, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int num = heights[i];
        while (st.top() != -1 && heights[st.top()] >= num)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next;
    next = nextSmallerElement(heights, n);

    vector<int> prev;
    prev = previousSmallerElement(heights, n);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        int h;
        if (next[i] == -1)
            next[i] = n;
        h = next[i] - prev[i] - 1; // Formula from observation
        int area = l * h;
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{

    return 0;
}