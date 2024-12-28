// Author : Yash Deshpande 
// Date : 25-02-2022

/*

##############################################Extra Notes#####################################################s

Poly” means several and “morphism” means form. So we can say that polymorphism is something that has one name and multiple forms. 

There are two types of polymorphism in C++:
    1. Compile-time polymorphism
    2. Run time polymorphism

1. Compile-time polymorphism
Compile time polymorphism can be achieved in C++ using :
    1.1 - Function Overloading
    1.2 - Operator Overloading


2. Run time polymorphism
Run time polymorphism can be achieved in C++ using :
    2.1 - Virtual Functions




Compile Time Polymorphism

1. In compile-time polymorphism, it is already known which function will run. 
2. Compile-time polymorphism is also called early binding, which means that you are already bound to the function call 
and you know that this function is going to run. 
3. There are two types of compile-time polymorphism:

3.1 Function Overloading
    i. This is a feature that lets us create more than one function and the functions have the same names but their parameters 
    need to be different. 
    ii. If function overloading is done in the program and function calls are made the compiler already knows that which functions 
    to execute.

Operator Overloading
    i. This is a feature that lets us define operators working for some specific tasks. 
    ii. For example, we can overload the operator “+” and define its functionality to add two strings.
    iii. Operator loading is also an example of compile-time polymorphism because the compiler already knows at the compile time 
    which operator has to perform the task.



Run Time Polymorphism

1. In the run-time polymorphism, the compiler doesn’t know already what will happen at run time. 
2. Run time polymorphism is also called late binding. 
3. The run time polymorphism is considered slow because function calls are decided at run time. 
4. Run time polymorphism can be achieved from the virtual function.

4.1 Virtual Function
    i. A function that is in the parent class but redefined in the child class is called a virtual function. 
    ii. “virtual” keyword is used to declare a virtual function.

*/