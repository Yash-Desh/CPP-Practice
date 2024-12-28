// Author : Yash Deshpande
// Date : 06-09-2022
// Topic : Strings
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Babbar Approach
// TC = O(N)
// SC = O(N)
string replaceSpaces(string &str)
{
    // Write your code here.
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

// Other Approach : using built-in functions
// TC : O(N)
// SC : O(1)
string replaceSpaces(string &str)
{
    // Write your code here.
    string temp = "@40";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
            str.insert(i, temp);
        }
    }
    return str;
}

// Better Approach
// TC = O(N)
// SC = O(1)

string replaceSpaces(string &str)
{
    int spaceCount = 0;

    // Count Number of Spaces.
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            spaceCount = spaceCount + 1;
        }
    }

    // Store thr current length of the string in a variable.
    int len = str.size();

    // Find the new length.
    int newLength;
    newLength = len + (spaceCount * 2);

    // Resize the current string.
    str.resize(newLength);

    // Index to end of string.
    int index = newLength - 1;

    // Fill string from end.
    for (int k = len - 1; k >= 0; k--)
    {
        if (str[k] == ' ')
        {
            str[index] = '0';
            str[index - 1] = '4';
            str[index - 2] = '@';
            index = index - 3;
        }
        else
        {
            str[index] = str[k];
            index = index - 1;
        }
    }
    // Return string.
    return str;
}

int main()
{

    return 0;
}