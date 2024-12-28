// Author : Yash Deshpande
// Date : 27-01-2022

#include <iostream>
using namespace std;

// to demonstrate the use of structures to combine different types of datatypes

struct employee // Defining a structure
{
    /* data */
    int eId;
    char favChar;
    float salary;
};

// Global struct variables

struct Rectangle 
{
    int length;
    int breadth;
}r1, r2, r3;

struct Rectangle r4; 

// NOTE : Here r1,r2,r3,r4 are all global struct variables which are accessible to all functions

// to demonstrate the use of typedef in structure

/* The "typedef" is a keyword that is used to provide existing data types with a new name. 
   It is used to redefine the name of already existing data types.
*/
typedef struct department
{
    /* data */
    int floor;    // 4 bytes
    char symbol;  // 1 bytes
    float salary; // 4 bytes
    // Total size of struct department = 9 bytes
} dp;

 

int main()
{
    // -> Implementing structure employee

    struct employee harry;          // Creating an instance of the structure of the type employee
    struct employee shubham ;       // Mutltiple instances of the same type can be created
    struct employee ramesh ;
    

    // Method - 1 : Initializing each data element individually
    harry.eId = 1;
    harry.favChar = 'c';
    harry.salary = 1200;
    cout << "The value is " << harry.eId << endl;
    cout << "The value is " << harry.favChar << endl;
    cout << "The value is " << harry.salary << endl<<endl;

    
    // Method - 2 : declaring and initializing a  struct in the same line
    struct employee mohan = {100,'a',1500.55};  
    cout << "The value is " << mohan.eId << endl;
    cout << "The value is " << mohan.favChar << endl;
    cout << "The value is " << mohan.salary << endl<<endl;

    
    
    // -> Implementing structure department

    // structure innovations of the type department can be defined just 
    // by using the keyword 'dp' since we used typedef
    dp innovations; 
    innovations.floor = 3;
    innovations.symbol = 'i';
    innovations.salary = 1000;
    cout << "The value is " << innovations.floor << endl;
    cout << "The value is " << innovations.symbol << endl;
    cout << "The value is " << innovations.salary << endl;


    // size of a structure & concept of padding
    cout<<"Size of innovations structure is "<<sizeof(mohan)<<endl;
    // output : 12 although the expected answer is 9
    // This is due to padding where the system finds it easy to read 4 bytes at the same time rather than 1 single byte

    return 0;
}

/*

##############################################Extra Notes#####################################################

1. The structure is a user-defined data type available in C++. 

2. Structures are used to combine related data members of different kinds of data types, just like an array is used 
   to combine the same type of data types. 

3. typedef keyword : Use a keyword “typedef” before struct and after the closing bracket of structure, we have written 
   “dp”. Now we can create structure variables without using the keyword “struct” and name of the struct.

   typedef keyword in C++ is used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name. 
   Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code. 
   Mostly typedefs are used for aliasing, only if the predefined name is too long or complex to write again and again.  
   The unnecessary use of typedef is generally not a good practice.

4. Size of a structure is equal to the total amount of memory consumed by all its members.

5. A structure is stored inside the "stack memory".

6. Members of a struct are accessed using the dot operator(.)

7. Concept of padding for specific cases in sizeof() a struct 

8. Structures are mutable & their values can be changed

*/