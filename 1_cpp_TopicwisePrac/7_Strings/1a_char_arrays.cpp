// Author : Yash Deshpande
// Date : 07-08-2022
// Tutor : Love Babbar

#include <bits/stdc++.h>
// #include <cstring>      --> necessary to header file for functions like strlen , strcmp , strcpy
using namespace std;



// function to give length of a string (char array)
int getLength (char arr[])       
{
    int cnt = 0;
    for(int i=0; arr[i] != '\0'; i++)
    {
        cnt++;
    }
    return cnt;
}

// NOTE : when passing arrays to function , by general practice 
//        the size of the arrays is also passed as a parameter
//        In char arrays however, it is not necessary since 
//        loop control is done using null character '\0'


// function to reverse a string (char array)
void reverse(char arr[], int n)            // n = length of string
{
    int s = 0;      // ptr to start of array
    int r = n-1;    // ptr to end of array
    while(s<r)
    {
        // swap
        swap(arr[s++],arr[r--]);        // swap() is a built-in function of std library
    }
}


// function to check for palindrome , case-sensitive  'N' != 'n'
bool checkPalindrome1 (char arr[], int n)
{
    int s = 0;      // ptr to start of array
    int r = n-1;    // ptr to end of array
    while(s<r)
    {
        // if any character is not same then return 0
        if (arr[s] != arr[r])     
        {
            return 0;
        }
        s++;
        r--;
    }
    return 1;
}


// function to convert uppercase alphabet to lowercase alphabet
// NOTE : this function does not work for numbers or any other characters 
//        apart from alphabets
char toLowerCase (char ch)
{
    // if input character is lowercase, return the same unchanged
    if(ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else // if input character is uppercase, return its lowercase version
    {
        return ch-'A'+'a';
    }
}


// function to check for palindrome , NOT case-sensitive  'N' == 'n'
bool checkPalindrome2 (char arr[], int n)
{
    int s = 0;      // ptr to start of array
    int r = n-1;    // ptr to end of array
    while(s<r)
    {
        // if any character is not same, then return 0
        if (toLowerCase(arr[s]) != toLowerCase(arr[r]))      
        {
            return 0;
        }
        s++;
        r--;
    }
    return 1;
}




int main()
{
    // char arrays

    // declaration
    
    // Using double quotes  
    char greeting[25] ="how are you?";              // how are you?

    // array type declaration
    char word[ ]={'A', 'j', 'a', 'y', '\0'};        // Ajay

    // Taking input
    char name [20];   // char array of size 20
    cout<<"Enter name : ";

    // Taking input in char array
    cin>>name;                                       // Siddhesh Pisal  

    // NOTE : While taking input using cin ,Any character after a "space" / "tab" / "new line" will not be stored 
    //        compiler will automatically add the null character '\0' at the end
    
    // //  To solve this problem we use the cin.getline() function
    // cin.getline(name,20);     // takes 2 parameters , name of char array & length of array
    // cout<<name<<endl;     


    // Printing char array
    cout<<"Name : "<<name<<endl;    // Siddhesh

    // // NOTE : No loop is required , to take input or give output for a char array

    // // Accessing individual elements of char array : using index
    // cout<<"2nd Letter of name is "<<name[1]<<endl;    // i

    // // Modifying char array 
    // name[2] = 'P';        // SiPdhesh
    // name[3] = '\0';       // Sip

    // // Any characters after the null character will not be processed by the compiler
    // // Null character is the string terminator


    // // Counting length of a string (in char array)  : Refer to function
    // cout<<"length of string is "<<getLength(name)<<endl;

    // // Reversing a string
    // reverse(name,getLength(name));
    // cout<<"Reverse of string is "<<name<<endl;

    // // check for palindrome in string
    // cout<<"Palindrome or not "<<checkPalindrome2(name,getLength(name))<<endl;
    
    // // In-built functions of c-strings

    // // length of a c-string 
    // char str1[] = "hello";
    // int len = strlen(str1);   // 5
    // cout<<"size = "<<len<<endl;

    // // compare 2 strings lexicographically
    // char str2[] = "abds";
    // char str3[] = "hasadfj";
    // cout<<"Strings are same or not "<<strcmp(str2, str3)<<endl;

    // // NOTE : returns 0 if both strings are identical
    // //        returns positive number if, 1st parameter has greater ascii value at 1st point of difference
    // //        returns negative number if, 2nd parameter has greater ascii value at 1st point of difference


    // // copy one string into another
    // char str4 [] = "howre";
    // char str5[] = "dndhsd";
    // strcpy(str4, str5);     // 1st parameter is destination , 2nd parameter is the source 
    // cout<<str4<<endl;       // copies str5 into str4

    

    return 0;
}