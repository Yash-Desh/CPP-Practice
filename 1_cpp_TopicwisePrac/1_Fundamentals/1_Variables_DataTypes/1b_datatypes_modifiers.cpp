// Author : Yash Deshpande
// Date : 07-01-2022

#include <iostream>
using namespace std;

int main()
{
  // **** (Built-in) Variables with different datatypes & sizes  ****

  int a = 23;      // integer values
  cout<<"size of int "<<sizeof(a)<<endl;                    // 4

  float b = 3.14 ;  // decimal numbers                      // 4
  cout<<"size of float "<<sizeof(b)<<endl;

  char c = 'y'; // can hold ONLY single character 
  cout<<"size of char "<<sizeof(c)<<endl;                   // 1

  bool d = true ; // can hold only 2 values ['true' OR 'any number except 0'] OR ['false' OR '0']
  cout<<"d = "<<d<<endl;  // will print 1 if true & 0 if false 
  cout<<"size of bool "<<sizeof(d)<<endl;                     // 1

  
  
  //****Type Modifiers****

  short int si;
  cout<<"size of short int "<<sizeof(si)<<endl;               // 2

  long int li;
  cout<<"size of long int "<<sizeof(li)<<endl;                // 8

  long double ld;
  cout<<"size of long double "<<sizeof(ld)<<endl;             // 16



  // **** Float, double and long double Literals ****
  float e=34.4F;
  long double f = 34.4L; 
    
  cout<<"The size of 34 is " << sizeof(34)<<endl;             // 4

  //  Special Case: By default a decimal value is taken to be a double
  cout<<"The size of 34.4 is "<<sizeof(34.4)<<endl;           // 8
  cout<<"The size of 34.4f is "<<sizeof(34.4f)<<endl;         // 4
  cout<<"The size of 34.4F is "<<sizeof(34.4F)<<endl;         // 4
  cout<<"The size of 34.4l is "<<sizeof(34.4l)<<endl;         // 16       --> long double is 16B
  cout<<"The size of 34.4L is "<<sizeof(34.4L)<<endl;         // 16       --> long double is 16B
  cout<<"The value of e is "<<e<<endl<<"The value of f is "<<f;   
  
 
  return 0;
}

/*
##############################################Extra Notes#####################################################

int ascii = 'a';
cout<<ascii;    --> prints 97 to console i.e the ASCII value of 'a'



*/