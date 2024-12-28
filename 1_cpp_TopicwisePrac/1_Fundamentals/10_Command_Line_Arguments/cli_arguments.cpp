// Author : Yash Deshpande
// Date : 25-09-2024
// Tutor : GeeksforGeeks
// Link : https://www.geeksforgeeks.org/command-line-arguments-in-cpp/

// C++ program to demonstrate the use of command line
// arguments

// ########################### IMPORTANT ##############################
// DO NOT RUN THIS ON CodeRunner
// Compile on terminal using "g++ cli_arguments.cpp -o cli_arguments"
// Run the code using ./cli_arguments <word1> <word2>
// replace word1 & word2 with any words of your choice
// ####################################################################

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "You have entered " << argc
         << " arguments:" << endl;

    // Using a while loop to iterate through arguments
    int i = 0;
    while (i < argc) {
        cout << "Argument " << i + 1 << ": " << argv[i]
             << endl;
        i++;
    }

    return 0;
}