// Author : Yash Deshpande
// Date : 5-11-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// utility function to find the next smaller element
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

// utility function to find the previous smaller element
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

// utility function to find max area rectangle of a histogram
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

int maxArea(int M[MAX][MAX], int n, int m)
{   // MAX = 1000
    // Your code here
    vector<int> histogram(m);
    for (int i = 0; i < m; i++)
    {
        histogram[i] = M[0][i];
    }
    int maxArea = largestRectangleArea(histogram);
    for (int i = 1; i < n; i++)
    {
        // create new histogram
        for (int j = 0; j < m; j++)
        {
            histogram[j] = M[i][j] == 0 ? 0 : histogram[j] + M[i][j];
        }
        int area = largestRectangleArea(histogram);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{

    return 0;
}