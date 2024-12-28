// Author : Yash Deshpande 
// Date : 17-03-2022

#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    // Opening Files using open() function

    
    ofstream out;   // declaring an object of the type ofstream
    //connecting the object out to the text file using the member function open()
    out.open("SampleText_A.txt");    
    
    //writing to the file
    out<<"Hello World.\n";
    out<<"German is an easy language.";
    
    //closing the file connection
    out.close();


    ifstream in;
    string str;
    in.open("SampleText_A.txt");
    in>>str;  // Reading the 1st word ONLY
    cout<<str<<endl;

    in>>str;  // Reading the 2nd word ONLY
    cout<<str<<endl;
    

    return 0;
}

/*

##############################################Extra Notes#####################################################s

Using the member function open():

1. The member function open is used to connect the text file to the C++ program when passed into it.

2. Understanding the snippet above:
    1. Unlike what we did earlier passing the text file in the object while creating it, we’ll first just declare an 
    object out(any name you wish) of the type ofstream and use its open method to open the text file in the program.
    
    2. We’ll pass some string lines to the text file using the out operation.
    
    3. We’ll now close the file using the close function. Now closing is explicitly used to make the system know that we are 
       done with the file. It is always good to use this.



*/