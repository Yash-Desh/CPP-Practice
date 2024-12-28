// Author : Yash Deshpande
// Date : 3-09-2022
// Tutor : Love Babbar
// Platform : SPOJ

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, int cookRank[], int P, int L)
{
    int pratasMade = 0;
    for (int i = 0; i < L; i++)
    {
        int time = mid;
        int j = 1;
        while (time && cookRank[i]*j <= time)
        {
            time = time - cookRank[i]*j++;
            pratasMade++;
        }
    }
    if (pratasMade >= P)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minCookTime(int cookRank[], int P, int L)
{
    // minimize search space for time to cook all pratas
    int lb = 0;
    int ub = 0;
    for (int i = 0; i < L; i++)
    {
        lb = min(lb, cookRank[i]);
        ub = max(ub, cookRank[i]);
    }
    lb *= P*(P+1)/2;
    ub *= P*(P+1)/2;
    int ans = 0;

    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (isPossible(mid, cookRank, P, L))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int T, P, L;
    cin >> T;

    while (T--)
    {
        cin >> P >> L;

        int cookRank[L];
        for (int i = 0; i < L; i++)
        {
            cin >> cookRank[i];
        }
        cout << minCookTime(cookRank, P, L) << endl;
    }
    return 0;
}