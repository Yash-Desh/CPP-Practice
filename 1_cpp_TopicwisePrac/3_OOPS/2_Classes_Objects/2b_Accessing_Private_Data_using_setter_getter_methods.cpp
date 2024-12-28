// Author : Yash Deshpande
// Date : 13-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

class Hero
{
    // Private data members
    int health;
    char level;

    // Accessing & Modifying pvt 
    public:

    int getHealth()
    {
        return health;
    }

    char getLevel()
    {
        return level;
    }


    void setLevel(char l)
    {
        level = l;
    }

    void setHealth(int h)
    {
        health = h;
    }
};


int main()
{
    Hero h1;

    h1.setHealth(15);
    h1.setLevel('C');

    cout<<"Health is "<<h1.getHealth()<<endl;
    cout<<"Level is "<<h1.getLevel()<<endl;

    return 0;
}
