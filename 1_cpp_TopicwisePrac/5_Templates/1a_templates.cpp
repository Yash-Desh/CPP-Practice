// Author : Yash Deshpande
// Date : 19-03-2022

#include <iostream>
using namespace std;
 
// Syntax for defining a template 
template <class T>
class vector {
    T *arr;
    int size;
    public:
        vector(T* arr)
        {
            //code

        }
        
        //and many other methods
    
};
 
int main() 
{
    // Creating objects using the defined template "vector"
    vector<int> myVec1();
    vector<float> myVec2();
    return 0;
}

/*

##############################################Extra Notes#####################################################

1. What is a template in C++ programming?
   -> 1. A template is believed to escalate the potential of C++ several fold by giving it the ability to define 
         data types as parameters making it useful to reduce repetitions of the same declaration of classes for 
         different data types. 
      2. Declaring classes for every other data type(which if counted is way too much) in the very first place 
         violates the DRY( Don’t Repeat Yourself) rule of programming and on the other doesn't completely utilise 
         the potential of C++.
      3. It is very analogous to when we said classes are the templates for objects, here templates itself are the 
         templates of the classes. 
      4. That is, what classes are for objects, templates are for classes.


2. Why templates?
   -> 1. DRY Rule:
         To understand the reason behind using templates, we will have to understand the effort behind declaring 
         classes for different data types. 
         Suppose we want to have a vector for each of the three(can be more) data types, int, float and char. 
         Then we’ll obviously write the whole thing again and again making it awfully difficult. 
         This is where the saviour comes, the templates. 
         It helps parametrizing the data type and declaring it once in the source code suffice. 
         Very similar to what we do in functions. 
         It is because of this, also called, ‘parameterized classes’.

   -> 2. Generic Programming:
         It is called generic, because it is sufficient to declare a template once, it becomes general and it works 
         all along for all the data types.
        
3. Understanding the syntax :
    -> 1. First, we declare a template of class and pass a variable T as its parameter.
       2. Define the class of vector and keep the data type of *arr as T only. 
       3. Now, the array becomes of the type we supply in the template.
       4. Now we can easily use this template to declare umpteen number of classes in our main scope. 
          Be it int, float, or arr vector.


*/