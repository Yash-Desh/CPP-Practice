// Author : Yash Deshpande
// Date : 11-08-2022
// Tutor : CodeWithHarry , Luv , Striver

/*

all_of(), any_of(), none_of() , these functions return bool values
they make use of lambda functions
Although lambda functions is not a requirement for these functions

*/

bool isPositive (int x)
{
    return x>0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Lambda functions
    cout<<[](int x){return x+2;}(25)<<endl;   // lambda function to add 2 to the given number

    // how to reuse lambda functions ?
    // assingn it to a variable , that becomes the name of the function
    // auto keyword is very important
    auto sum = [](int x , int y){return x+y;}; // lambda function to return the sum of 2 integers
    cout<<sum(99,100)<<endl;


    // // all_of()
    // All the cases should return true , so function wil return a true
    // vector <int> v = {2,3,5};

    // // using lambda functions
    // cout<<all_of(v.begin(), v.end(), [](int x){return x>0;})<<endl;

    // // without using lambda functions
    // cout<<all_of(v.begin(), v.end(), isPositive)<<endl;


    // // any_of()
    // // any of the cases if returns a true , the function returns a true
    // vector <int> v = {-2,9,-14};
    // cout<<any_of(v.begin(),v.end(), [](int x){return x>0;})<<endl;


    // none_of()
    // none of the cases if returns a true , the function returns a true
    vector <int> v = {-2,9,-14};
    cout<<none_of(v.begin(),v.end(), [](int x){return x>0;})<<endl;


    return 0;
}