// Author : Yash Deshpande
// Date : 22-03-2022

/*

##############################################Extra Notes#####################################################

1. Function is a piece of code that performs a specific task. Also known as "modules" or "procedures".

2. A functions can be called from inside the main() function or any other function. The main() function is called 
   automatically on execution of the program.

3. Only names of the variables are passed and not their types while calling a function.

4. Concept of "Parameter Passing"   :  
   We pass the values to the function not the variables themselves. Local variables are created inside the function 
   which get destroyed on returning from the function.   

5. concept of "Call Stack"  :  
   When a function is called,the system allocates a chunk of memory(for function data) to it in the stack and this 
   chunk is called the stack frame.
   These stack frames have only 2 operations in the stack i.e. push & pop which can be done only from the top.
   When the function is called they(stack frames) are pushed to the stack & popped when the function returns value.
   The stack frame at the top of the stack is known as the active stack frame.

6. This style of programming is known as "Modular" / "Procedural" programming.

7. The main benefit of functions is that each function will have its own stack frame / activation record , its own seperate
   set of variables which are destroyed after function execution

8. One function cannot access the variables of another function directly but it can access them indirectly using pointers.

*/