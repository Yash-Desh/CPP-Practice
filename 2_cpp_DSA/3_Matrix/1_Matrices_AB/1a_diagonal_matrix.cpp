// Author : Yash Deshpande 
// Date : 20-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Matrix 
{
    int A[10];  // fixed sized array , although the size should be decided by the dimension "n"
    int n;  // dimension of the matrix = n*n
};

void set(struct Matrix *m, int i, int j, int x)  // struct Matrix is passed address since we make a change to it 
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int get(struct Matrix m, int i, int j)
{
    if(i == j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
}

void display(struct Matrix m)
{
    for(int i=0; i<m.n; i++)
    {
        for(int j=0; j<m.n; j++)
        {
            if(i == j)
            {
                cout<<m.A[i]<<" ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    struct Matrix m1;
    m1.n = 4;

    set(&m1,1,1,5);
    set(&m1,2,2,8);
    set(&m1,3,3,9);
    set(&m1,4,4,12);

    display(m1);

    cout<<"\nValue at 2,2 is "<<get(m1,2,2)<<endl;

    return 0;
}