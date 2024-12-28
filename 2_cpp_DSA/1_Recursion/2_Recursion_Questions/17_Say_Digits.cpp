// Author : Yash Deshpande 
// Date : 10-09-2022
// Tutor : Love Babbar

// Q. Convert numbers into english words digit-by-digit
//    Ex. 123 -> one two three
//    Ex. 456 -> four five six

#include <bits/stdc++.h>
using namespace std;

// Babbar Approach
// function that converts numbers into
// english words digit-by-digit
// Problem with this question : what if the input is 0 ?
void sayDigit (int number , string map[])
{
    // Base Case
    if(number == 0)
        return; 

    // Recursive Relation
    int digit = number % 10;
    sayDigit(number/10, map);
    cout<<map[digit]<<" ";
}

int main()
{
    string map [] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int number = 786;
    sayDigit(number, map);
    return 0;
}