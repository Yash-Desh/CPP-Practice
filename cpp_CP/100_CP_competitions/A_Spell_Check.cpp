#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name = "Timur";
    set <char> nameSet;
    for(auto item : name)
    {
        nameSet.insert(item);
    }
    int T;
    cin>>T;
    string test;
    int testLen;
    while(T--)
    {
        cin>>testLen;
        cin>>test;
        if(testLen != name.size())
        {
            cout<<"NO"<<endl;
        }
        else
        {
            set <char> testSet;
            for(auto item : test)
            {
                testSet.insert(item);
            }

            auto it1 = nameSet.begin();
            auto it2 = testSet.begin();
            int i;
            for( i=0; i<testLen; i++)
            {
                if(*it1 != *it2)
                {
                    cout<<"NO"<<endl;
                    break;
                }
                it1++;
                it2++;
            }
            if(i == testLen)
                cout<<"YES"<<endl;
        }

    }
    return 0;
}