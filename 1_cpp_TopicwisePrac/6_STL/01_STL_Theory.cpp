// Author : Yash Deshpande
// Date : 29-03-2022
// Tutor : Code with Harry

/*

##############################################Extra Notes#####################################################

COMPONENTS OF STL :   We have three components in STL:

    1. Containers
    2. Algorithm
    3. Iterators
    4. Functors

Containers:

Container is an object which stores data. We have different containers having their own benefits. 
These are the implemented "template classes" for our use, which can be used just by including this library. 
You can even customise these template classes.


Algorithms:

Algorithms are a set of instructions which manipulates the input data to arrive at some desired result. 
In STL, we have already written algorithms, for example, to sort some data structure, or search some element in 
an array. 
These algorithms use "template functions". 

Iterators:

Iterators are objects which refer to an element in a container. 
And we handle them very much similarly to a pointer. 
Their basic job is to connect algorithms to the container and play a vital role in manipulation of the data.


1. Containers, objects which store data, Algorithms, set of procedures to process data, and Iterators, objects 
   which point to some element in a container. 

2. Types of Containers : 
    1. Sequence Containers
    2. Associative Containers
    3. Derived Containers

Sequence Containers
A sequence container stores that data in a linear fashion. 
Sequence containers include Vector, List, Dequeue etc. 

Associative Containers
An associative container is designed in such a way that enhances the accessing of some element in that container. 
It is very much used when the user wants to fastly reach some element. 
Some of these containers are, Set, Multiset, Map, Multimap etc.  
They store their data in a tree-like structure.

Derived Containers 
 As the name suggests, these containers are derived from either the sequence or the associative containers. 
 They often provide you with some better methods to deal with your data. 
 They deal with real life modelling. 
 Some examples of derived containers are Stack, Queue, Priority Queue, etc.


3. When to use which

In sequence containers, we have Vectors, which has following properties:
    1. Faster random access to elements in comparison to array
    2. Slower insertion and deletion at some random position, except at the end.
    3. Faster insertion at the end.
    

In Lists, we have,

Random accessing elements is too slow, because every element is traversed using pointers.
Insertion and deletion at any position is relatively faster, because they only use pointers, which can easily be 
manipulated.
In associative containers, every operation except random access is faster in comparison to any other containers, 
be it inserting or deleting any element.

In associative containers, we cannot specifically tell which operation is faster or slower, we’ll have to 
inspect every data structure separately


*/