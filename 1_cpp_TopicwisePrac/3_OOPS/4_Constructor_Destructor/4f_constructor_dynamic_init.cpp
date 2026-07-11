// Author : Yash Deshpande
// Date : 31-01-2022

// ################################################################################
// Compound Interest formula   [Note added by Claude Opus 4.8, 10-07-2026]
//
//     A = P * (1 + r)^t
//
//     A = final amount (return value)
//     P = principal
//     r = interest rate per period, as a fraction (e.g. 0.05 for 5%)
//     t = number of periods (years here)
//
//     The loop below computes (1 + r)^t by multiplying `returnValue` by
//     (1 + interestRate) once per year, which is the iterative form of the
//     formula above. Interest earned = A - P.
// ################################################################################

#include<iostream>
using namespace std;

// ################################################################################
// Note the different datatypes of arguments provided to the overloaded constructors.
// ################################################################################

class BankDeposit{
    int principal;
    int years;
    float interestRate;
    float returnValue;

    public:
        BankDeposit(){}                         // --> Program won't run without a default constructor

        // Example: BankDeposit(1000, 5, 0.04)  --> rate given as a fraction (0.04 = 4%)
        BankDeposit(int p, int y, float r);     // r can be a value like 0.04

        // Example: BankDeposit(1000, 5, 14)    --> rate given as a whole percent (14 = 14%)
        BankDeposit(int p, int y, int r);       // r can be a value like 14
        void show();
};

BankDeposit :: BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1+interestRate);
    }
}

BankDeposit :: BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    interestRate = float(r)/100;
    returnValue = principal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1+interestRate);
    }
}

void BankDeposit :: show(){
    cout<<endl<<"Principal amount was "<<principal
        << ". Return value after "<<years
        << " years is "<<returnValue<<endl;
}

int main(){
    // These objects are created using the default constructor & will generate 
    // an error if default constructor not found
    BankDeposit bd1, bd2, bd3;   
    int p, y;
    float r;
    int R;
    
    /* 

    bd3.show();  // shows the garbage values assigned to all the variables when the 
                    1st constructr was called without any parameters

    */
    cout<<"Enter the value of p y and r"<<endl;
    cin>>p>>y>>r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout<<"Enter the value of p y and R"<<endl;
    cin>>p>>y>>R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();


    return 0;
}

/*

##############################################Extra Notes#####################################################s

1. The dynamic initialization of the object means that the object is initialized at the runtime.

2. Dynamic initialization of the object using a constructor is beneficial when the data is of different formats.

3. What "dynamic init" means in this file
   [Note added by Claude Opus 4.8, 10-07-2026]

    "Dynamic" here refers to WHEN the object gets its values, not HOW.

    - In main(), objects are first created with the default constructor:
          BankDeposit bd1, bd2, bd3;   // values not known yet
      then initialized later from runtime data:
          cin >> p >> y >> r;
          bd1 = BankDeposit(p, y, r);  // initialized AT RUNTIME

    - So "dynamic" = the initializing values are supplied while the program
      runs (here via cin / user input), as opposed to STATIC / compile-time
      initialization where values are hard-coded:
          BankDeposit bd(1000, 5, 0.04);   // values baked in at compile time

    - The overloaded constructors (float r vs int r) let the same runtime
      data arrive in different formats and still be handled correctly, which
      is what point 2 above is getting at.

    NUANCE: In formal C++, "dynamic initialization" specifically means
    initializing with non-constant expressions (vs constant/zero init). This
    teaching file uses the term more loosely to mean "initialized from runtime
    input via a constructor". It has NOTHING to do with new/heap allocation,
    even though "dynamic" implies that in other contexts.

*/