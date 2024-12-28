// Author : Yash Deshpande 
// Date : 21-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

class LowerTri  // Row Major
{
    private :
        int n;  // Dimension of the matrix
        int *A;  // Pointer to create a dynamic array

    public:
        LowerTri()   // Default constructor
        {
            int n=2;
            A = new int [2*(2+1)/2];
        }

        LowerTri(int n)
        {
            this->n = n;
            A = new int [n*(n+1)/2];
        }

        ~LowerTri()
        {
            delete []A;
        }

        void set(int i, int j, int x);
        int get (int i, int j);
        void display();
        int getDimension()   // Function to return the dimension of the matrix
        {
            return n;
        }
};

void LowerTri :: set(int i, int j, int x)
{
    if(i >= j)
    {
        A[(n * (j-1) - (((j-2) * (j-1))/2)) + (i-j)] = x;
    }
}

int LowerTri :: get( int i, int j)
{
    if(i >= j)
    {
        return A[(n * (j-1) - (((j-2) * (j-1))/2)) + (i-j)];
    }
    else
    {
        return 0;
    }
}

void LowerTri :: display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i >= j)
            {
                cout<<A[(n * (j-1) - (((j-2) * (j-1))/2)) + (i-j)]<<" ";
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
    int d ;
    cout<<"Enter number of dimensions : ";
    cin>>d;

    LowerTri lm(d);
    
    int x;
    cout<<"\nEnter all elements"<<endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            lm.set(i,j,x);
        }
    }
    cout<<endl<<endl;
    lm.display();
    return 0;
}