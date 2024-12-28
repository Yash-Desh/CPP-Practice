// Author : Yash Deshpande
// Date : 16-06-2022
// Tutor : Abdul Bari

#include <iostream>
using namespace std;

void display(char *arr)
{
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // Declaring character variables
    char x = 'a';

    // Declaring character arrays
    char x1[5] ;

    char x2[5] = {'a','b','c','d','e'};
    display(x2);

    char x3[] = {'a','b','c','d','e'};

    char x4[5] = {'A','B'};
    display(x4);

    char x5[5] = {65,66,67,68,69};
    display(x5);

    // Declaring strings

    char name1[10] = {'J','O','H','N','\0'};

    char name2[] = {'J','O','H','N','\0'};

    char name3[] = "JOHN";

    // Taking String input & output
    // char name4[10];
    // cout<<"Enter name : ";
    // cin>>name4;
    // cout<<name4<<endl;

    // Taking string input using gets()
    char name5[10];
    cout<<"Enter another name : ";
    gets(name5);
    cout<<name5;

    

    return 0;
}
/*

##############################################Extra Notes#####################################################

1. There is a problem when both cin & gets() are used together so when i run the code i make sure to comment out 
one of the two.

2. Please make sure to find out what the issue is .

*/