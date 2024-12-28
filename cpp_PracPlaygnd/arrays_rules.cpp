#include <iostream>
using namespace std;

int main()
{
    int i,k;
    int arr[i][k];
    cout<<"Enter i & k ";
    cin>>i>>k;
    for (int j = 0; j < i; j++)
    {
        for (int p = 0; p < k; p++)
        {
           cin>>arr[j][p]; 
        }
    }
    // for (int j = 0; j < i; j++)
    // {
    //     cout<<arr[j];
    // }
    
    return 0;
}