// Author : Yash Deshpande
// Date : 07-01-2022

/*
Topics covered :  1. Variable declaration & initialization
                  2. Rules for naming a variable
*/


#include <iostream>
using namespace std;



int main ()
{

  // **** Declaring & initializing a variable****

  
  int a;      //variable declaration 
  a = 43;     //variable initialization

  int b = 34;      // variable declaration & initialization in 1 line 

  int c = 45 , d = 12 , e, f ;  // declaring / initializing multiple variables of same type at a time
  
 
 
   
  
  
  int g = 54;
  g = 78;
  cout<< g <<endl;

  /* After declaring a variable it can be modified as many times as you like & the variable
  will contain the latest value 
  */


  /*  2. Rules for variable declaration 
  
  Variable names in C++ language can range from 1 to 255
  Variable names must start with a letter of the alphabet or an underscore
  After the first letter, variable names can contain letters and numbers
  Variable names are case sensitive
  No spaces and special characters are allowed
  We cannot use reserved keywords as a variable name
  
  */

  return 0;
}

/*
##############################################Extra Notes#####################################################

Once a variable is declared do not mention its datatype every time you assign it a new value  
  for example : 
  int c ;
  int c = 32 ; --> this will give an error!!!


*/