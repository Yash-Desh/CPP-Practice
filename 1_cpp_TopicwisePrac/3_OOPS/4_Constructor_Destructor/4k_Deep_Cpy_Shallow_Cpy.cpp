// Author : Yash Deshpande
// Date : 15-10-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
using namespace std;

class Hero
{
    private:
    int health;

    public : 
    char level;
    char *name;

    
    // default constructor
    Hero()
    {
        cout<<"Default Constructor called"<<endl;
        health = 100;
        level = 'A';
        name = new char [10];
    }

    // Parameterized Constructor
    Hero (int health, char lvl)
    {
        cout<<"Parameterized Constructor called"<<endl;
        this->health = health;
        this->level = lvl;
    }


    // Copy Constructor
    // Hero(Hero &temp)
    // {
    //     cout<<"Copy Constructor called"<<endl;
    //     this->health = temp.health;
    //     this->level = temp.level;

    //     char *ch = new char [strlen(temp.name) + 1];
    //     strcpy(ch, temp.name);
    //     this->name = ch;
    // }

    // Comment out the copy constructor to analyze shallow copy
    // IF no copy constructor is definded
    // hence the compiler will supply its 
    // default copy constructor
    

    void setHealth (int health)
    {
        this->health = health;
    }

    void setName (char charName[])
    {
        name = new char [10];
        strcpy(name, charName);
    }

    void print()
    {
        cout<<"Hero : ";
        cout<<"health = "<<this->health<<" , ";
        cout<<"Level = "<<this->level<<" , ";
        cout<<"Name = "<<this->name<<endl;
        cout<<endl;
    }

};

int main()
{
    // Creating an Object h1
    Hero h1(150, 'Z') ;
    char heroName [7] = "Babbar";
    h1.setName(heroName);
    cout<<"Printing h1"<<endl;
    h1.print();

    Hero h2(h1);
    cout<<"Printing h2"<<endl;
    h2.print();


    // Modifications made to h2
    cout<<endl<<"After modifying h2"<<endl;
    h2.setHealth(175);
    h2.name[0] = 'G';
    h2.level = 'Y';
    cout<<"Printing h2"<<endl;
    h2.print();


    cout<<"Printing h1"<<endl;
    h1.print();

    return 0;
}