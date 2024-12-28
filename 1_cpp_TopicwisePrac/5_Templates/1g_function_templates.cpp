// Author : Yash Deshpande
// Date : 28-03-2022

#include <iostream>
using namespace std;

template<class T1, class T2>  // -> Template definition
float average(T1 a , T2 b)
{
    float avg;
    avg = (a+b)/2;
    return avg;
}
int main()
{
    float result ;
    result = average(5,2.3);
    cout<<"Average = "<<result<<endl;
    
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. We’ll first declare a template with two data type parameters T1 and T2. And replace the data types we mentioned in
   the function with them. 

2. And that’s it. Our function has become general for all sorts of data types.

*/