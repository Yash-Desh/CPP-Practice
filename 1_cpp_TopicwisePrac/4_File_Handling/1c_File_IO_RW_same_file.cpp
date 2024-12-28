// Author : Yash Deshpande 
// Date : 17-03-2022

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Creating a name string variable and initializing it with the string entered by the user
    string name;
    cout<<"Enter your name : ";
    cin>>name;  // Note : Only content before the space or new line is taken as input i.e only Sachin if input is Sachin Tendulkar

    // Connect our file to the 'out' stream
    ofstream out("SampleText_A.txt");   
    out<<name + " is my name.";  // Writing string to the file
    out.close();  // Closing the file


    ifstream in("SampleText_A.txt");
    string content;
    getline(in, content);
    cout<<"The contents of the read file are : "+content;
    in.close();  // Closing the file


    return 0;
}
/*

##############################################Extra Notes#####################################################s



*/