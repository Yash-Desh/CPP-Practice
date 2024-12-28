// Author : Yash Deshpande
// Date : 18-06-2022
// Tutor : Abdul Bari

// Q. To validate a string with only alphabets & numbers

#include <iostream>
using namespace std;

int validate (char *name)
{
    for(int i=0; name[i] != '\0'; i++)
    {
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char my_name[] = "Ani?321";  // char *my_name = "Ani?321"; --> Invalid in C++

    if(validate(my_name))
    {
        cout<<"Valid String"<<endl;
    }
    else{
        cout<<"Invalid String"<<endl;
    }

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. There is some issue regarding the line " char *my_name = "Ani?321"; " . It is valid in C but invalid in C++

2. Better stick to char my_name[] = "Ani?321";


*/
