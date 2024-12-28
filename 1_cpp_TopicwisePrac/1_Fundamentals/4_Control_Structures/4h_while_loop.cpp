// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;
int main()
{
   //**** While loop in C++ ****
    /* Syntax:
    
    while(condition)
    {
        C++ statements;
    }

    */

    //  Printing 1 to 10 using while loop
    int i=1;
    while(i<=10)
    {
        cout<<i<<endl;
        i++;
    }

     
    // Here since i is initialized outside of the loop it can be accessed anywhere within the program
    cout<<endl<<"Value of i after the loop outside it is "<<i; // i = 11

    return 0;
}

/*
##############################################Extra Notes#####################################################

1. Loop is not executed even once if the initial condition is false

2. increment happens only after initial execution
    
3. if the given condition is always true then it results into an infinite loop ; which btw is undesirable 
          for example : while(true)
                        {
                            // infinite loop 
                        }

*/