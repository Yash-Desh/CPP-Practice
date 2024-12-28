// Author : Yash Deshpande
// Date : 24-01-2022

#include <iostream>
using namespace std;

int main()
{
    
  // A reference variable is an alias, that is, another name for an already existing variable.

  float p = 455;
  float & q = p;
  cout<<p<<endl;
  cout<<q<<endl<<endl;

  // Any changes made to p will be applied in q as well
  p+= 10;
  cout<<p<<endl;
  cout<<q<<endl<<endl;

  // Similarly any changes made to q will be applied in p as well
  q -=20;
  cout<<p<<endl;
  cout<<q<<endl;

  // Note 
  int x = 35;
  p = x ;
  cout<<"p = "<<p<<endl<<"q = "<<q<<endl;

    return 0;
}
/*

##############################################Extra Notes#####################################################

1. Reference is a nickname / alias given to a variable.

2. Reference variables can be defined as another name for an already existing variable. These are also called an alias

3. Used in parameter passing





*/