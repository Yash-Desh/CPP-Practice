// Position   :
// Round      : 
// Interviewer: 
// Date       : 

#include <stdio.h>
#include <stdlib.h>

struct Data {
    int key;
    int weight;
    struct Data* next;
};

// Key & weight fields are immutable (can't be modified).

// You are given a sorted singly linked list, (sorted by "key" filed in struct Data). Write a function
// to remove all duplicate keys in the list, while removing duplicates, retain the node with the highest
// "weight" for a key.

// Example:

// Input : 

// [{key: 15, wt: -3}, {key: 15, wt: -2}, {key: 15, wt: 1}, {key: 16, wt: 1}, {key: 19, wt: 100}, {key: 29, wt: 1}]

// Expected Result:

// [{key: 15, wt: 1}, {key: 16, wt: 1}, {key: 19, wt: 100}, {key: 29, wt: 1}]
