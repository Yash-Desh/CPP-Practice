// Author : Yash Deshpande
// Date : 19-03-2022

#include <iostream>
using namespace std;
 
// Q. We have two integer vectors and we want to calculate their Dot Product

class vector
{
    public:
        int *arr;
        int size;  // Size of the vector
        vector(int m)
        {
            size = m;
            arr = new int[size];
        }
    int dotProduct(vector &v)   // -> I don't know why Harry used &v
    {
        int d=0;   // variable to store the value of dot product between 2 vectors
        for (int i = 0; i < size; i++)
        {
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};
 
int main()
{
    vector v1(3); //vector 1
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;
    
    
    vector v2(3); //vector 2
    v2.arr[0]=1;
    v2.arr[1]=0;
    v2.arr[2]=1;
    int a = v1.dotProduct(v2);
    cout<<a<<endl;
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. A template does the same thing to a class, what a class does to the objects. 

2. It parametrizes the data type hence making it easy for us to use different classes without having to write 
   the whole thing again and again, violating the DRY rule. 

3. Templates furthermore give our program a generic view, where declaring one template suffices the task.

4. This program was all about creating a class and an embedded function to calculate the dot product of two "integer" 
   vectors.
   This program would obviously fail to calculate the dot products for some different data types. It would 
   demand an entirely different class. 
   But we’ll save ourselves the effort and the time by declaring a template.
   
*/