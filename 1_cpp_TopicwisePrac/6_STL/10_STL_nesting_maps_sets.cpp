// Author : Yash Deshpande
// Data : 9-8-2022
// Tutor : Luv , Striver

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // nesting of maps

    // map of pairs as keys
    map <pair<int,int>, int> m;
    
    // map will be in sorted order of pairs & follows these rules to compare 2 pairs
    // Comparison between pairs 
    pair <int ,int > pr1 , pr2;
    pr1 = {1,7};
    pr2 = {3,4};
    cout<<(pr1<pr2)<<endl;      // 1

    // NOTE : comparison b/w 2 pairs with comparison operator
    //        compares the "first" of both pairs
    //        returns 1 if true , 0 if false
    //        if "first" of both pairs same , then compares the "second" of both pairs


    // map of sets as keys
    map <set<int>, int> s;

    // map will be in sorted order of sets & follows these rules to compare 2 sets
    // Comparison between pairs 
    set <int> s1 , s2;
    s1 = {1,7,5,6};
    s2 = {3,4,1};
    cout<<(s1<s2)<<endl;      // 1

    // NOTE : comparison b/w 2  sets with comparison operator
    //        compares the 1st element of both pairs
    //        returns 1 if true , 0 if false
    //        if 1st element of both sets same , then compares the 2nd of both sets 
    //        and so on until the 1st point of difference 

    // NOTE : Even for a map of vectors , the vectors will be compared element-wise 
    //        and at the 1st point of difference b/w the 2 vectors , the comparison will be made



    // Q. Take input & store the first name, last name  & marks of students
    map <pair<string , string>, vector<int>> mp;
    
    int T;
    cout<<"Enter number of students : ";
    cin>>T;
    for(int i=0; i<T; i++)
    {
        string fn, ln;          // fn = 1st name , ln = last name
        int n;                  // n = number of marks to be stored for that student
        cin>>fn>>ln>>n;
        for(int j=0; j<n; j++)
        {
            int num;
            cin>>num;
            mp[{fn,ln}].push_back(num);
        }
    }

    for(auto & pr : mp)
    {
        auto &fullname = pr.first;
        auto &list = pr.second;

        cout<<fullname.first<<" "<<fullname.second<<endl;
        cout<<"marks : ";
        for(int item : list)
        {
            cout<<item<<" ";
        }
        cout<<endl;
    }
    return 0;
}