// Author : Yash Deshpande 
// Date : 22-06-2022
// Tutor : Abdul Bari


/*

NOTE 

This code has some error : whenever i give the dimensions 5*5 and set number of non-zero elements as 4
the 4th non-zero element doesn't get printed when the display() function is called


*/

#include <iostream>
using namespace std;

// struct for each non-zero element
struct Element 
{
    int i;  // i-index
    int j;  // j-index
    int x;  // value of the element
};

// struct for the sparse matrix
struct Sparse 
{
    int m;  // dimensions m*n
    int n;
    int num;  // number of non-zero elements in the matrix
    struct Element *ele;  // struct type pointer to create a dynamic array of "Element" type 
};

// Dynamic array is preferred to a fixed sized array since , the size of the array is unknown before runtime

// function to create the sparse matrix in the 3-column representation
void create(struct Sparse *s)   // "Sparse" type struct passed by address since we make modifications
{
    cout<<"Enter Dimensions m*n : "<<endl;
    cin>>s->m>>s->n;

    cout<<"Enter number of non-zero elements : ";
    cin>>s->num;

    // Array of structs with the size of s->num
    s->ele = new struct Element [s->num];  

    for(int i=0; i<s->num; i++)
    {
        cout<<"Enter non-zero elment : i j x "<<endl;
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }

}


// function to display all the elements of the sparse matrix
void display(struct Sparse s)
{
    int k=0; // Pointer that iterates over the dynamic array pointed by "ele"

    // Nested loop to print the sparse matrix
    for(int i=0; i<s.m; i++)       // Note that the loop runs from 0 to s.m
    {
        for(int j=0; j<s.n; j++)   // Note that the loop runs from 0 to s.n
        {
            if(i==s.ele[k].i && j == s.ele[k].j)
            {
                cout<<s.ele[k++].x<<" ";
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
    struct Sparse s1;
    create(&s1);
    display(s1);

    return 0;
}