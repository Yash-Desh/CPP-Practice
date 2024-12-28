// Author : Yash Deshpande
// Date : 12-8-22
// Solved : Luv STL series : 3rd CP contest
// My Approach : null


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;

    vector <pair<int , int>> pts(N);   // storing all points
    set <pair<int,int>> points_pr;     // for faster searching of points in time O(log n)
    for(int i=0; i<N; i++)
    {
        cin>>pts[i].first>>pts[i].second;
        points_pr.insert(pts[i]);
    }
    
    // loop to find all possible rectangles & their areas
    int min_ar = INT_MAX;       // min area
    int max_ar = INT_MIN;       // max area
    for(int i=0; i<N; i++)
    {
        auto p1 = pts[i];           // select a point
        for(int j=0; j<N; j++)
        {
            auto p2 = pts[j];        // select 2nd point diagonal to 1st pt
            if(p1.first != p2.first && p1.second != p2.second)
            {
                int x1 = p1.first;    // remaining 2 points
                int y1 = p2.second;
                int x2 = p2.first;
                int y2 = p1.second;
                if(points_pr.count({x1,y1}) && points_pr.count({x2,y2}))   // find if such points exist
                {
                    int area = abs(x1-x2)*abs(y1-y2);
                    max_ar = max(max_ar, area);
                    min_ar = min(min_ar,area);
                }
            }
        }
    }
    if(min_ar == INT_MAX)    // if no possible rectangles exist
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<max_ar - min_ar<<endl;
    }
    return 0;
}

/*

The set was only created for faster searching , than searching in a vector

*/