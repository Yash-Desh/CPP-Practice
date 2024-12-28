// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;
int main()
{
    
    /* 
    **** Syntax for for loop ****
    
    for(initialization; condition; updation)
    {
        // loop body(C++ code);
    }
     
    */


    // Simple for loop to print numbers from 1 to 10
    
    for (int i = 1; i <= 10; i++)
    {
    cout<<i<<endl;
    }

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. Loop is not executed even once if the initial condition is false

2. Variable defined within the for loop  are local & hence are accessible only within the for loop
        for example : counter variable 'i' cannot be accessed outside of my for loop   

3. increment happens only after initial execution

4. if the given condition is always true then it results into an infinite loop ; which btw is undesirable  
         for example : for(int i = 0; 34<40 ; i++)   -->is an infinite loop
         {                             
                                     
         }
         Here 34<40 is an always true condition
*/