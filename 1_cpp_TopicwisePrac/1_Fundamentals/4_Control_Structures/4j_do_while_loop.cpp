// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;
int main()
{
    // **** do - while loops in C++ ****
    /* Syntax:
        
        do
        {
            C++ statements;
        
        }while(condition);
    
    */
    
    //  Printing 1 to 10 using while loop
    int i=1;
    do
    {
        cout<<i<<endl;
        i++;
    }       
    while(i<=10); // Notice the semicolon 
    return 0;
}

/*
##############################################Extra Notes#####################################################

1. Loop runs atleast once even if the initial condition is false
             for example : do
                           {

                           }while(false)  --> is also evaluated once



*/