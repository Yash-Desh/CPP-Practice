// Author : Yash Deshpande
// Date : 25-01-2022

#include <iostream>
using namespace std;

// ****Function to demonstrate default parameters ****

float moneyReceived(int currentMoney, float factor = 1.04)
{
    return currentMoney * factor;
}

// **** Funtion to demonstrate constant arguments commonly used with call by reference ****
int strlen(const char *p)
{
    // Function statements
    return 0;
}


int main()
{
     int money = 100000;
    cout <<"If you have "<<money<<" Rs in your bank account, you will recive " << moneyReceived(money)<<"Rs after 1 year"<<endl;
    cout <<"For VIP: If you have "<<money<<" Rs in your bank account, you will recive "<<moneyReceived(money, 1.1)<<" Rs after 1 year";
    return 0;
}
/*
##############################################Extra Notes#####################################################

1. Default parameters should always be written to the rightmost of all parameters
            for example : int func(int param1 = 10 , int param2, int param3)  --> is not a correct practice and will generate an error

2. 

*/