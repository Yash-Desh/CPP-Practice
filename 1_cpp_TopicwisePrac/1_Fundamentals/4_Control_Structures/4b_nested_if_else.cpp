// Author : Yash Deshpande
// Date : 08-01-2022

#include <iostream>
using namespace std;

int main()
{
    int savings;
    cout<<"Enter savings: ";
    cin>>savings;

    if (savings>5000)  // Girlfriend No.1 if savings exceed Rs.5000 
    {
        if (savings>10000)
        {
            cout<<"Roadtrip with Neha\n";
        }
        else
        {
            cout<<"Shopping with Neha\n";
        }
    }
    else if (savings > 2000)    // Girlfriend No.2 if savings exceed Rs.2000 but not Rs.5000
    {
        cout<<"Date with Raashi\n";
    }
    else           // Friends if savings are lesser than Rs.2000
    {
        cout<<"Party with Friends\n";
    }
    return 0;
}