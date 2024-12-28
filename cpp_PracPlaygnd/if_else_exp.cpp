#include <iostream>
using namespace std ;
int main ()
{
    char my_char;
    cout<<"Enter any character :";
    cin>>my_char;
    cout<<endl<<my_char*6;
    cout<<"You have entered "<<my_char<<endl; 
    if (my_char>=0 && my_char<=9)
    {
        cout<<"It is an integer";
    }
    else
    {
       cout<<"It is an alphabet";
    }

    return 0;
}