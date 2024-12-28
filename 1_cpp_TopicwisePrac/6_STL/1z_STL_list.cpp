// Author : Yash Deshpande
// Date : 30-03-2022
// Tutor : Love Babbar

#include <iostream>
#include <list>   // -> necessary header file to be included
using namespace std;

void display (list<int> &lst)    // pass the list to a display function via reference.
{
    list<int> :: iterator it;  // declaring an iterator named "it" 
    for(it = lst.begin(); it != lst.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    list<int> list1;    // List of length zero
    list<int> list2(3);   // Empty list of size 3 elements

    // copy list
    list <int> list3 (list1);

    // list of predefined elements
    list <int> list4(5,100);     // {100,100,100,100,100}

    list1.push_back(7);
    list1.push_back(9);
    list1.push_back(11);
    list1.push_front(2);
    list1.push_back(11);
    list1.push_front(1);
    display(list1);


    // Reversing a list 
    list1.reverse();
    display(list1);

    // Sorting a list 
    list1.sort();
    display(list1);



    // Deleting elements from a list 
    
    // #1 from the back
    list1.pop_back();
    display(list1);

    // #2 from the front
    list1.pop_front();
    display(list1);

    // #3 All instances of a particular element value
    list1.remove(9);   // Note : If 9 is repeated inside the list all its  instances will be deleted
    display(list1);


    // #4 erase using iterator
    list1.erase(list1.begin());
    display(list1);


    // Size of a list
    cout<<"Size of the list is "<<list1.size()<<endl;
    
    
    
   //  // Entering elements into list2
   //  list<int>  :: iterator iter;
   //  iter = list2.begin();
   //  *iter = 44;
   //  iter++;
   //  *iter = 33;
   //  iter++;
   //  *iter = 10;
   //  iter++;
   //  display(list2);



   //  // Merging 2 lists 
   //  list1.merge(list2);
   //  cout<<"After merging : ";
   //  display(list1);


    return 0;
}

/*

##############################################Extra Notes#####################################################

List  -> Internally maintained as a doubly linked list hence some extra functions from the beginning 
of the list can be performed

1. A List is a bi-directional linear storage of elements. 

2. Few key features as to why a list should be used is, 
    1. It gives faster insertion and deletion operations.
    2. Its access to random elements is slow.

3. What makes a list different from an array?
   An array stores the elements in a contiguous manner in which inserting some element calls for a shift of other 
   elements, which is time taking. But in a list, we can simply change the address the pointer is pointing to.

4. Due to the fact that a list element cannot be directly accessed by its index, we must traverse through each element 
   and print them.

5. We use two methods, begin() and end() to define the starting and the end of the loop. end() returns the pointer next 
   to the last element.

6. We dereference the list iterator, using * to print the element at that index.

7. We can use pop_back() to delete one element from the back of the list everytime we call this method and pop_front() 
   to delete elements from the front. These commands decrease the size of the list by 1. 

8. We can remove an element from a list by passing it in the list remove method. It will delete all the occurrences of that 
   element. The remove method receives one value as a parameter and removes all the elements which match this parameter. 

9. Using sort(): We can sort a list in ascending order using its sort method. 




*/