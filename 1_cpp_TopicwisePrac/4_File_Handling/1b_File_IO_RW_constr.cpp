// Author : Yash Deshpande 
// Date : 17-03-2022

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string st1 = "Harry Bhai is great !!!";  // String1 to write to a file 
    string st2;  // String2 to read from a file

    // Opening Files using constructor

    // 1. Write to file Operation
    ofstream out("SampleText_A.txt");   // Creating object named 'out' of the class named 'ofstream'
    out<<st1;


    // 2. Read from file Operation
    ifstream in("SampleText_B.txt");   // Creating object named 'in' of the class named 'ifstream'
    
    // Method - 1 
    in>>st2;
    cout<<st2;  // Note : Characters coming after spaces & new lines are not read

    // Method - 2 
    getline(in, st2);  // Reads one full line of characters 
    cout<<st2<<endl;    // Note : Characters coming after new lines are not read
    getline(in, st2);
    cout<<st2<<endl;

    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. These are some useful classes for working with files in C++
        * fstreambase
        * ifstream --> derived from fstreambase
        * ofstream --> derived from fstreambase
        
2. In order to work with files in C++, you will have to open it. Primarily, there are 2 ways to open a file:
        * Using the constructor
        * Using the member function open() of the class
        
3. The name of the variables given here "in"  & "out" are NOT predefined keywords and can be any as per user preference 

4. An open file is automatically closed on completion of the program execution. But use close() to do it as good practice.


*/