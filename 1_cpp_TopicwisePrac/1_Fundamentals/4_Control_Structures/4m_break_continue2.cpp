// Author : Yash Deshpande
// Date : 24-01-2022

// Q. Program to implement a girl's monthly plan

#include <iostream>
using namespace std;

int main()
{
    int pocketMoney = 3000;  // Total pocket money of Rs.3000
    for(int date =1;date<=30;date++)
    {
        if(date%2 == 0)
        {
            continue;
        }
        
        if(pocketMoney==0)
        {
            break;
        }

        cout<<"Date : "<<date<<" Go out today !!"<<endl;  // Go out only on odd dates
        pocketMoney -= 300;  // Spend Rs.300 from pocket money for every outing 
    }
    return 0;
}