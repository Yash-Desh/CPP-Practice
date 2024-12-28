// Author : Yash Deshpande 
// Date : 12-04-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

int main()
{
    // p points to the small array
    int *p, *q;
    p = new int [5];
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    // q points to the larger array
    q = new int [10];
    
    // copying elements of p into q
    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    // making p point to larger array ,  deleting smaller array , q points to NULL
    delete []p;
    p = q;
    q = NULL;

    // Displayig elements of array pointed at by p
    for(int i= 0; i <10; i++)
    {
        cout<<p[i]<<endl;
    }
    return 0;
}

/*

##############################################Extra Notes#####################################################

The last time I ran this code i was getting some errors in the values printed at the very end




*/