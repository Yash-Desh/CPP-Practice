// Author : Yash Deshpande
// Date : 31-10-2022
// Tutor : Love Babbar

#include <iostream>
using namespace std;

// Approach - 1, AC
// Brute Force
class twoStacks {
    int* ar;
    int size;
    int top1, top2;
  
public:
    twoStacks(int n)
    {
        size = n;
        ar = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }

    void push1(int x)
    {
        if (top1 > 0) {
            top1--;
            ar[top1] = x;
        }
        else {
            cout << "Stack Overflow"
                << " By element :" << x << endl;
            return;
        }
    }
  
    void push2(int x)
    {
        if (top2 < size - 1) {
            top2++;
            ar[top2] = x;
        }
        else {
            cout << "Stack Overflow"
                << " By element :" << x << endl;
            return;
        }
    }
  
    int pop1()
    {
        if (top1 <= size / 2) {
            int x = ar[top1];
            top1++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }

    int pop2()
    {
        if (top2 >= size / 2 + 1) {
            int x = ar[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }
};


// Approach - 2, AC
// Optimal Approach : Space Optimized
class TwoStack
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        this->size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
            return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
            return -1;
    }
};

int main()
{

    return 0;
}