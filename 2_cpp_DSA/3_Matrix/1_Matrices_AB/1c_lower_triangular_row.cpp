// Author : Yash Deshpande 
// Date : 20-06-2022
// Tutor : Abdul Bari

// Q. Implement a Lower Triangular matrix using Row Major Mapping

#include <iostream>
using namespace std;

struct Matrix 
{
    int *A;  // Pointer to declare a dynamic array since size is unknown until runtime  
    int n;  // dimension of the matrix = n*n
};

// Note : Check for validity of the indices entered by the user

void set(struct Matrix *m, int i, int j, int x)  // struct Matrix is passed address to make changes to it 
{
    // Note : Check for validity of the indices entered by the user
    if(i>=j)
    {
        m->A[i*(i-1)/2 +j-1] = x;
    }
}

int get(struct Matrix m, int i, int j)
{
    // Note : Check for validity of the indices entered by the user
    if(i >= j)
    {
        return m.A[i*(i-1)/2 +j-1];
    }
    else
    {
        return 0;
    }
}

void display(struct Matrix m)
{
    for(int i=1; i<=m.n; i++)  // Notice that the loop starts from i=1 & ends at i <= n
    {
        for(int j=1; j<=m.n; j++)  // Notice that the loop starts from j=1  & ends at j <= n
        {
            if(i >= j)
            {
                cout<<m.A[i*(i-1)/2 +j-1]<<" ";
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

    cout<<"Enter the dimension : ";
    cin>>m1.n;
    m1.A = new int [(m1.n)*(m1.n+1)/2];


    // Loop to create a LT matrix using user input
    int x;  // variable used to take input
    cout<<"Enter all elements"<<endl;    
    for(int i=1; i<=m1.n; i++)      // Notice that the loop starts from i=1 & ends at i <= n
    {
        for(int j=1; j<=m1.n; j++)  // Notice that the loop starts from j=1 & ends at j <= n
        {
            cin>>x;
            set(&m1,i,j,x);
        }
    }

    cout<<endl<<endl;
    display(m1);

    set(&m1, 4,4, 56);
    display(m1);



    return 0;
}