// Author : Yash Deshpande
// Date : 31-01-2022

#include<iostream>
using namespace std;


class BankDeposit{
    int principal;
    int years;
    float interestRate;
    float returnValue;

    public:
        BankDeposit(){}                         // --> Program won't run without a default constructor 
        BankDeposit(int p, int y, float r);     // r can be a value like 0.04
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
    BankDeposit bd1, bd2, bd3;   // These objects are created using the default constructor & will generate an error if default constructor not found
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

*/