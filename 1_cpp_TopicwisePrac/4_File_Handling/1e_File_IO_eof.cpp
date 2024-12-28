// Author : Yash Deshpande 
// Date : 17-03-2022

#include <iostream>
#include <fstream>
// #include <string>  --> NOT compulsory to include as program works perfectly without it 
using namespace std;

int main()
{
    // Writing to the file
    ofstream out;
    out.open("SampleText_A.txt");
    out <<"This is me\n";
    out <<"This is also me";
    out.close();


    // Use of eof()

    // declaring an object of the type ifstream
    ifstream in;
    //declaring string variable st
    string st;
    //opening the text file into in
    in.open("SampleText_A.txt");
 
    // Reading from a file 

    // Method - 1 : One word at a time
    //              -> in.st; 

    // Method - 2 : One line at a time
    //              ->getline(in,st)

    
    // Method - 3 : giving output the string lines by storing in st until the file reaches the end of it
    
    while (in.eof()==0) 
    {
        // using getline to fill the whole line in st
        getline(in,st);
        cout<<st<<endl;
    }

    return 0;
}

/*

##############################################Extra Notes#####################################################s

Using the member function eof() :

1. The member function eof(End-of-file) returns a boolean true if the file reaches the end of it and false if not. 

2. Understanding the snippet below:
    1. We’ll first declare an object in(any name you wish) of the type ifstream and use its open method similar to what we did above, 
       to open the text file in the program.
    2. And now, we’ll declare the string variable st to store the content we’ll receive from the text file SampleText_A.txt.
    3. Now since we not only want the first or some two or three strings present in the text file, but the whole of it, and we have 
       no idea of what the length of the file is, we’ll use a while loop.
    4. We’ll run the while loop until the file reaches the end of it, and that gets checked by using eof() , which 
       returns 1 or true if the file reaches the end. Till then a 0 or false.
    5. We’ll use getline to store the whole line in the string variable st. Don’t forget to include the header file <string>.
    6. This program now successfully prints the whole content of the text file.


*/ 