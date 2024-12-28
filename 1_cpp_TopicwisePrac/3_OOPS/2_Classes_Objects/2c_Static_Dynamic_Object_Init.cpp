// Author : Yash Deshpande
// Date : 13-10-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

class Hero
{
    int health;
    char level;

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
    // Static Initialization
    Hero a;
    a.setHealth(15);
    a.setLevel('C');

    cout<<"Health is "<<a.getHealth()<<endl;
    cout<<"Level is "<<a.getLevel()<<endl;

    // Dynamic Initialization
    Hero *b = new Hero;

    b->setHealth(45);
    b->setLevel('B');

    cout<<"Health is "<<(*b).getHealth()<<endl;
    cout<<"Level is "<<(*b).getLevel()<<endl;

    cout<<"Health is "<<b->getHealth()<<endl;
    cout<<"Level is "<<b->getLevel()<<endl;

    return 0;
}