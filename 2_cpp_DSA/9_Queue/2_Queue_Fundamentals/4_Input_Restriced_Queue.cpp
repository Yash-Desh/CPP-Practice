#include <iostream>
using namespace std;

int main()
{
    int* arr  = new int [10];
    arr[0] = 0;
    int position = 0;
    if(arr[position] == 0 || arr[position-1]==0)
        cout<<"works"<<endl;
    return 0;
}