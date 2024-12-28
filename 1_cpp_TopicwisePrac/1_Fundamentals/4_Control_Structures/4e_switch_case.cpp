// Author : Yash Deshpande
// Date : 08-01-2022

#include <iostream>
using namespace std;
int main()
{
     // 2. Selection control structure: Switch Case statements


    /* 
    *******************************RULES TO REMEMBER WHILE USING SWITCH CASE********************************

    1. The expression provided in the switch should result in a constant value otherwise it would not be valid
    
    2. Duplicate case values are not allowed.

    3. The default statement is optional.Even if the switch case statement do not have a default statement, 
       it would run without any problem.

    4. The break statement is used inside the switch to terminate a statement sequence. 
    When a break statement is reached, the switch terminates, and the flow of control jumps to the next line 
    following the switch statement.

    5. The break statement is optional. If omitted, execution will continue on into the next case. 
    The flow of control will fall through to subsequent cases until a break is reached.

    6. Nesting of switch statements are allowed, which means you can have switch statements inside another switch.
     However nested switch statements should be avoided as it makes program more complex and less readable. 
    */

    int age;
    cout<< "Enter your age in years :"<<endl;
    cin>>age;
 
    switch (age)
    {
    case 3 : 
        cout<<"You are a toddler"<<endl;
        break;   // break statements are a must in switch case otherwise all cases will be executed
    case 12: 
        cout<<"You are a school aged kid"<<endl;
        break;
    case 18: 
        cout<<"You are a teenager"<<endl;
        break;

    default:
    cout<<"You are an adult "<<endl;
        break;
    }

    cout<<"\nDone with switch case";
    
    return 0;
}