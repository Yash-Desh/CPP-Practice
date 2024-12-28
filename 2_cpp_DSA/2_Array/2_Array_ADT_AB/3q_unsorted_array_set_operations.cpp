// Author : Yash Deshpande 
// Date : 15-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

struct Array 
{
    int A[20];
    int size;     // Total elements in the array
    int length;   // Total values initialized in the array
};


void display (struct Array a)
{
    cout<<"Displaying array elements : ";
    for(int j=0; j<a.length; j++)
    {
        cout<<a.A[j]<<" ";
    }
    cout<<endl;
}

// Union
struct Array* union2 (struct Array * a, struct Array* b)
{
    struct Array *c = new struct Array;

    int i,j,k;
    for(i=0; i<a->length; i++)
    {
        c->A[i] = a->A[i];
    }

    for(j=0; j<b->length; j++)
    {
        for(k=0; k<a->length; k++)
        {
            if(b->A[j] == a->A[k])
            {
                break;
            }
        }
        if(k == a->length)
        {
            c->A[i++] = b->A[j];
        }
    }
    c->length = i;
    c->size = 20;
    return c;
}

// Intersection
struct Array* intersection2 (struct Array *a, struct Array *b)
{
    int i,j,k;
    k = 0 ;
    struct Array *c = new struct Array;
    for(i=0; i<a->length; i++)
    {
        for(j=0; j<b->length; j++)
        {
            if(a->A[i] == b->A[j])
            {
                c->A[k++] = a->A[i];
                break;
            }
        }
    }
    c->length = k;
    c->size =20;
    return c;
}

// Difference

struct Array* difference2 (struct Array *a, struct Array *b)
{
    int i,j,k;
    k = 0 ;
    struct Array *c = new struct Array;
    for(i=0; i<a->length; i++)
    {
        for(j=0; j<b->length; j++)
        {
            if(a->A[i] == b->A[j])
            {
                break;
            }
        }
        if(j == b->length)
        {
            c->A[k++] = a->A[i];
        }
    }
    c->length = k;
    c->size =20;
    return c;
}


int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 20, 5};
    struct Array arr2 = {{3, 6, 7, 15, 20}, 20, 5};

    struct Array *arr3;
    arr3 = difference2(&arr1, &arr2);
    display(*arr3);   // // Dereferencing the pointer arr3 for call by value  
    return 0;
}