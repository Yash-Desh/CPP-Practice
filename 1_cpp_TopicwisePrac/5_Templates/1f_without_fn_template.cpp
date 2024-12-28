// Author : Yash Deshpande
// Date : 29-03-2022

#include <iostream>
using namespace std;

float funcAverage1 (int a , int b)
{
    float avg = (a+b)/2;
    return avg;
}

float funcAverage2 (int a , float b)
{
    float avg = (a+b)/2;
    return avg;
}

int main()
{
    float num1, num2;
    
    num1 = funcAverage1(5,7);
    cout<<"Average of 2 integers = "<<num1<<endl<<endl;

    num2 = funcAverage2(5,7.67);
    cout<<"Average of integer & float = "<<num2<<endl<<endl;
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. The effort we made here defining a single function for two integers increases several folds when we demand 
   for a similar function for two floats, or one float and one integer or many more data type combinations. 
 
2. We just cannot repeat the procedure and violate our DRY rule. 

3. We’ll use function templates very similar to what we did when we had to avoid defining more classes.


*/