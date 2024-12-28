// Author : Yash Deshpande
// Date : 12-04-2023
// Tutor : Love Babbar

// ################################################### IMPORTANT #########################################################

// The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};

// ########################
// Approach - 1 : Brute Force, TLE
// My Approach
// TC : O(N^2)
// SC : O(1)
// ########################

// Function to find starting point where the truck can start to get through
// the complete circle without exhausting its petrol in between.
int tour(petrolPump p[], int n)
{
    // Your code here

    // Loop to check each petrol pump as a starting point.
    for (int i = 0; i < n; i++)
    {
        int petrolLeft = 0;
        // Loop from starting point till the end of the array
        for (int j = i; j < n; j++)
        {
            petrolLeft += p[j].petrol;
            petrolLeft -= p[j].distance;
            if (petrolLeft < 0)
            {
                break;
            }
        }
        if (petrolLeft >= 0)
        {
            // Loop from the start up to starting point
            for (int j = 0; j < i; j++)
            {
                petrolLeft += p[j].petrol;
                petrolLeft -= p[j].distance;
                if (petrolLeft < 0)
                {
                    break;
                }
            }
        }

        if (petrolLeft >= 0)
            return i;
    }
    return -1;
}


// ########################
// Approach - 2 : Better Approach
// Babbar Approach
// TC : 
// SC : 
// ########################


















// ########################
// Approach - 3 : Optimal Approach
// Babbar Approach
// TC : O(N)
// SC : O(1)
// ########################
// Function to find starting point where the truck can start to get through
// the complete circle without exhausting its petrol in between.
int tour(petrolPump p[], int n)
{
    // Your code here
    int deficit = 0;
    int start = 0;
    int petrolLeft = 0;

    for (int i = 0; i < n; i++)
    {
        petrolLeft += p[i].petrol - p[i].distance;
        if (petrolLeft < 0)
        {
            deficit += petrolLeft;
            petrolLeft = 0;
            start = i + 1;
        }
    }
    if (petrolLeft + deficit >= 0)
        return start;
    else
        return -1;
}




#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}