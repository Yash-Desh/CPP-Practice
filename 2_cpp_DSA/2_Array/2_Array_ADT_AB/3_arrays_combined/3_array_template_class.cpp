// Author : Yash Deshpande
// Date : 15-06-2022
// Tutor : Abdul Bari

// Q. Write a template class to perform operations on arrays from scratch

#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *A; // Dynamic array
    int size;
    int length;

public:
    Array() // Default Constructor
    {
        size = 10;  // fixed size of 10 is initialized
        length = 0; // no elements inside  the array
        A = new T[size];
    }

    Array(int sz) // Parameterized Constructor
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void display();
    void insert(int index, T x);
    T Delete(int index);
};

template <class T>
void Array<T> ::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T> ::insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T> :: Delete(int index)
{
    T del = 0;
    if(index>=0 && index<length)
    {
        del = A[index];
        for(int i = index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
        length--;
    }
    return del;
}

int main()
{
    Array<char> arr(10);
    arr.insert(0,'c');
    arr.insert(1,'a');
    arr.insert(2,'t');
    arr.display();

    cout<<arr.Delete(0)<<endl;
    arr.display();

    return 0;
}