// take input as array & addd and check if sum is 2000
#include <iostream>
using  namespace std;
int main()
{
    int i,sum,N;
    cin>>N;
    cout<<endl;
    int arr[N];
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }

    cout<<endl;

    int flag = 0;
    for (int index =0;index<N-1;index++)
    {
        sum = arr[index];
        for(i=N-1-index;i>0;i--)
        {
        sum = sum + arr[i];
        if (i>0)
        {
            if(sum==2000)
            flag+=1;
        }
        sum= arr[index];
       
    }
    }
    if (flag>=1)
        cout<<"Accepted";
    else
        cout<<"Rejected";
    
    
    
    return 0;
}
