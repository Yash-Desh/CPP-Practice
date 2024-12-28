// Author : Yash Deshpande
// Date : 08-01-2022

#include <iostream>
using namespace std;
int main()
{
    int age;
    cout<< "Enter your age in years :"<<endl;
    cin>>age;

    // 1. Selection control structure: If else-if else ladder

    if(age < 3)
    {
        cout<<"You are a toddler!!!"<<endl;
    }
    else if(age<12)
    {
        cout<<"You are a school aged kid !!!"<<endl;
    }
    else if((age>=13) && (age<=18))
    {
        cout<<"You are a teenager !!!"<<endl;
    }
    else
    {
        cout<<"You are an adult !!!"<<endl;
    }

    return 0;
}