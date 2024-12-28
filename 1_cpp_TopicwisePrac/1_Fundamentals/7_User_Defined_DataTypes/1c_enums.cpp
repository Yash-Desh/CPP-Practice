// Author : Yash Deshpande
// Date : 27-01-2022

// Program to demonstrate the use of enums

#include <iostream>
using namespace std;

//Enums are user-defined types which consist of named constants.

int main()
{
    enum Meal
    {
        breakfast,
        lunch,
        dinner
    };
    Meal m1 = lunch;
    cout << m1<<endl;
    cout<<dinner;

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Enums are used to make the program more readable.

2. (breakfast, lunch, dinner) are constants.
   The value for “breakfast” is “0”, the value for “lunch” is “1” and the value for “dinner” is “2”.
   
*/