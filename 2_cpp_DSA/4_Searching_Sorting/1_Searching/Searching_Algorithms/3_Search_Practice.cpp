// Author : Yash Deshpande
// Date : 18-06-2023

#include <iostream>
using namespace std;

bool linearSearch (int arr[], int target, int index)
{
    if(index == 0)
    {
        return false;
    }

    if (arr[index-1] == target)
    {
        return true;
    }

    
    return linearSearch(arr, target,index-1);
        
    
        
}


int main()
{
    int a[] = {12,45,32,67,-9,25};
    cout<<linearSearch(a,25,6);
    return 0;
}