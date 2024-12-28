// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;

int main()
{
    // A simple for loop program to print 10 numbers 
    for (int i = 0; i < 10; i++)
    {
        /* code */
        
        if(i==5)
        {
            break;   // when the value of i = 5 , the execution comes out of the loop
        }   
        cout<<i<<endl;  
    }
    cout<<"\nThe loop has ended !!!";
    cout<<endl<<endl;

    // A simple for loop program to print 10 numbers 
    for (int i = 0; i < 10; i++)
    {
        /* code */
        if(i==2)
        {
            continue;  // when the value of i = 2 ,the execution skips the following code & reruns the loop
        }
        cout<<i<<endl;
    }
    cout<<"\nThe number 2 has been skipped !!!";
    return 0;
}