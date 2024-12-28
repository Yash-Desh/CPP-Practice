// Author : Yash Deshpande 
// Date : 31-07-2022
// Tutor : Striver

// Write a function to "RECURSIVELY" print your name N number of times
#include <iostream>
using namespace std;


void printNtimes (string st, int n)
{
    if(n == 0){
        return;
    }

    cout<<st<<endl;

    printNtimes(st, n-1);
}





// my solution
// This function prints the given string n times
void nameN(string name, int n)
{
    if(n>0)
    {
        cout<<name<<endl;
        nameN(name, n-1);
    }
}



// striver's solution
// This function prints only the hard-coded value "Raj" n times
void f (int i, int n)
{
    if(i>n)
        return;
    cout<<"Raj"<<endl;
    f(i+1, n);

}

int main()
{
    // string my_name = "harsh";
    // nameN(my_name,3);
    // f(1,5);
    printNtimes("Lewis Hamilton", 7);
    return 0;
}
