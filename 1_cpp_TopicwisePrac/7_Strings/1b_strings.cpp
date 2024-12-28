// Author : Yash Deshpande
// Date : 08-08-2022
// Tutor : Love Babbar , Apni Kaksha

#include <bits/stdc++.h> // --> includes all header files 
// #include <string>        --> necessary header file for string class
// #include <algorithm>     --> necessary header file for sort() function
using namespace std;

// C++ STRINGS ARE A PART OF STL

int main()
{
    // NOTE : String is a type of class in C++
    //        C++ string stores its data in the form of 
    //        null-terminated c-style string
    //        but in normal usage doesn't allow you to 
    //        access the null terminator


    // Different types of string declarations
    
    // // Taking input from cin , spaces not allowed
    // string str;
    // cin>>str;                // hello world
    // cout<<str<<endl;         // hello

    // // declaration & initializing at same time using double quotes ("") 
    // string str1 = "Love Babbar";
    // cout<<str1<<endl;        // Love Babbar

    // // same character repeats n times 
    // string str2(5,'n');      // syntax : string str2 (size, char in single quotes'')
    // cout<<str2<<endl;        // nnnnn

    // // Taking input using getline, allows spaces
    // string str3;
    // getline(cin, str3);         // hi ! how are you ?
    // cout<<str3<<endl;           // hi ! how are you ?

    // // empty string
    // string str4 = ""; 

    // Using construnctor
    // string str5 ("mkbhd videos");   // mkbhd videos
    // cout<<str5<<endl;

    // // creating a new string from an existing one
    // string str6 = "airbus A380";
    // string str7 (str6);
    // cout<<str6<<endl;


    // // OTHER FUNCTIONS

    // // Appending 1 string to another

    // // using append() function
    // string s1 = "fam";
    // string s2 = "ily";
    // s1.append(s2);              // s2 is added to the end of s1
    // cout<<s1<<endl;             // family


    // // We can apply the standard operator to the string variables.
    // // using '+' operator
    // string s3 = "hel";
    // string s4 = "lo";
    // cout<< s3 + s4 <<endl;      // hello

    // // NOTE : Using append() function s1 is modified
    // //        But using '+' neither of the string is modified
    // //        if we write s1 = s1 + s2;    -> this modifies s1


    // // insert in a string
    // string str = "geeksgeeks";
    // str.insert(5, "for");           // 5 is the index at which "for" is entered
    // cout<<str<<endl;                // geeksforgeeks


    // // Accessing individual character

    // // using array type indices, follows zero-based indexing
    // string st1 = "modern";          
    // cout<<st1[3]<<endl;             // e

    // Modifying a string
    // Notice the difference when you insert a \0 in the middle of
    // a string in a character array & std::string
    string str = "Babbar";
    str[4] = '\0';
    cout<<str<<endl;             // Babbr


    // // length of a string
    // string str = "coding"; 
    // int len = str.length();      // 6
    // int len2 = str.size();       // 6

    // NOTE  : Both functions size() & length() give the same answer


    // // Traversing a string using for loop 
    // string str = "caramellatte";
    // for(int i=0; i<str.length(); i++)
    // {
    //     cout<<str[i]<<endl;
    // }


    // // appending a string
    // string str = "Babbar"; 
    // str.push_back('L');     
    // cout<<str<<endl;        // BabbarL


    // // finding substring in strings
    // string str = "codechefxyzchefschelss";      // "chef" occurs 2 times in given string
    // cout<<str.find("chef");                     // 4

    // // NOTE : find() returns the 1st index of the substring at 1st occurance of the entire substring
    // //        find() returns string::npos if substring not found 


    // // Deletion in strings

    // // deleting the entire string
    // string str5 = "sashfdopsds sadfsaopdfa adopfoasdf";
    // str5.clear();
    // cout<<str5<<endl;           // ""


    // // deleting last character
    // str.pop_back();
    // cout<<str<<endl;         // Babbar

    // // deleting specific characters using erase()
    // string str = "geeksforgeeks";
    // str.erase(5 , 3);            // syntax : str.erase(index, size)
    // cout<<str<<endl;             // geeksgeeks

    
    
    // // HW check out the difference between char arr & string in cpp
    // //    check out the prominent functions of strings

    // // copy 1 string into another
    // string st1 = "mama";
    // string st2 = "papa";
    // st1 = st2;     // st1 = papa

    // // compare 2 strings lexicographically
    // string st3 = "mumbai";
    // string st4 = "sunnywale";
    // // cout<<"value of comparison between strings is "<<st3.compare(st4)<<endl; 
    // cout<<(st3 == st4 ? 1 : 0)<<endl;

    // // NOTE : returns 0 if both strings are identical
    // //        returns positive number if, 1st parameter has greater ascii value at 1st point of difference
    // //        returns negative number if, 2nd parameter has greater ascii value at 1st point of difference
    // //        compare() can be used to easily compare substrings 

    
    // // To check whether the given string is empty or not
    // string str5 = "ahdf";
    // if(str5.empty())                            // empty() returns 1 if string is empty
    // {                                           // empty() returns 0 if string is NOT empty
    //     cout<<"string is empty"<<endl;
    // }
    // else
    // {
    //     cout<<str5<<" is the string"<<endl;     // ahdf is the string
    // }


    // // Extracting a substring from a string
    // string str = "elcaminoreal";
    // string sub = str.substr(2,6);                   // syntax : str.substr(index , size)
    // cout<<sub<<endl;


    // // convert string to int
    // string str = "153";
    // int num = stoi(str);                // 
    // cout<<num*2<<endl;                  // 306


    // // convert int to string 
    // int n= 125;
    // string num = to_string(n);          // use the to_string() function
    // cout<<num+'8'<<endl;                // using single quotes only one number of characters can be appended
    // cout<<num+"7"<<endl;                // using double quotes any number of characters can be appended


    // // sort a string
    // string str = "zgasdofgdjfp";
    // sort(str.begin(), str.end());          // syntax : sort(starting iterator, ending iterator)
    // cout<<str<<endl;                       // addffggjopsz

    // // cin & getline if used together may creates some error
    // int n;
    // cin>>n;
    // // cin.ignore();                        // Notice that without cin.ignore() getline will take '\n' as its very 1st line of input 
    // while(n--)                              // This will print empty space up top
    // {
    //     string st;
    //     getline(cin, st);
    //     cout<<st<<endl;
    // }

    // // Dealing with large numbers using string 
    // // these larger numbers are larger than even the range of long long i. greater than 10^18
    // string st ;
    // cin>>st;

    // // print the last digit of a larger number stored as string
    // int index = st.size() - 1;
    // cout<<st[index]-'0'<<endl;
    return 0;
}