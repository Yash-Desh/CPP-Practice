// Author: Yash Deshpande
// Date  : 07-10-2026
// Position: Darwin Runtime Engineer, Core OS
// Interviewers: Aaron Morrison, Bryce Wilson

// Problem:
//   Implement a list that supports the four operations below:
//     push_front(l, n)  - insert node n at the front of list l
//     pop_front(l)      - remove and return the front node (NULL if empty)
//     push_back(l, n)   - insert node n at the back of list l
//     pop_back(l)       - remove and return the back node (NULL if empty)

//   The underlying data structure was not specified -- you define the
//   contents of `node` and `list`. The caller allocates and owns the nodes;
//   the list only links them (push takes a node *, pop hands one back).

// NOTE TO READER:
//   See the "Claude Answers" Q&A section at the bottom of this file for a
//   review of this attempt, the bug it contains, and the design trade-offs.
//   The corrected reference solution is in Apple_linked_list_solution.c.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// define the node
// top, back list
// dummy node 

// -1 -> 2 -> NULL



// t       b
// (-1) -> 2
typedef struct node {
  int data; 
  struct node* next; 
} node;

typedef struct list {
  struct node* top;
  struct node* back;
} list;

node *
pop_front(list *l)
{
  // TODO
  if(l == NULL) {
    return NULL;
  }
  if(l->top == l->back) {
    return NULL;
  }
  struct node* temp = l->top->next;
  l->top->next = temp->next;
  temp->next = NULL;

  // BUG in my actual interview implementation, missed this case:
  // if we just removed the node l->back was pointing to
  // if(l->back == temp) {
  //   l->back = l->top;
  // }

  return temp;
  
  // return NULL;
}

void
push_front(list *l, node *n)
{
  // TODO
  if(l == NULL || n == NULL) {
    return;
  }
  // insert the node
  n->next = l->top->next;
  l->top->next = n;
  // handle the back pointer
  if(l->top == l->back) {
    l->back = n;
  }
}

node *
pop_back(list *l)
{
  // TODO
  return NULL;
}

void
push_back(list *l, node *n)
{
  // TODO
  if(l == NULL || n == NULL) {
    return;
  }
}

void print_node(node *n) {
  printf("node value: %d\n", n->data);
}

void print_list(list *l) {
  
  if(l->top == l->back){
    printf("list is empty\n");
  }
  struct node* ptr = l->top->next;
  while(ptr != NULL) {
    printf("%d\n", ptr->data);
    ptr = ptr->next;
  }
}

int main()
{
  // TODO: Test cases
  struct list l;  
  l.top = (struct node*)malloc(sizeof(struct node));
  l.top->next = NULL;
  l.top->data = -1;
  l.back = l.top;
  
  
  pop_front(&l);
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->data = 3;
  push_front(&l, temp);
  struct node* temp2 = (struct node*)malloc(sizeof(struct node));
  temp2->next = NULL;
  temp2->data = 5;
  push_front(&l, temp2);
  pop_front(&l);
  print_list(&l);
}


/*

################################################## Claude Answers ##################################################

Q1) What is the bug in my incomplete solution? 

pop_front doesn't update back when it removes the last node (the real bug).
push_front(&l, A);   // top -> A,  back = A
pop_front(&l);       // top -> NULL, but back is still A (and A is now the caller's)
push_front(&l, B);   // top != back, so back is never set to B
Once you pop the last node, back points at a node that's no longer in the list. Every later push_back or pop_back would then corrupt memory. Fix:
if (l->back == temp) l->back = l->top;
Your own main never hits this because it pops while two nodes are still in the list.


Q2) Does using the dummy node really help me?

Only a little. Compare your sentinel version with plain top/back that start at NULL:

┌────────────┬────────────────────────────────────────────────┬─────────────────────────────────────────────────────┐
│ Operation  │                Sentinel (yours)                │                   NULL head/tail                    │
├────────────┼────────────────────────────────────────────────┼─────────────────────────────────────────────────────┤
│ push_front │ 1 branch (update back if the list was empty)   │ 1 branch (update tail if the list was empty)        │
├────────────┼────────────────────────────────────────────────┼─────────────────────────────────────────────────────┤
│ pop_front  │ 1 branch (reset back if the list became empty) │ 1 branch (set tail = NULL if the list became empty) │
├────────────┼────────────────────────────────────────────────┼─────────────────────────────────────────────────────┤
│ push_back  │ 0 branches (back->next = n; back = n;)         │ 1 branch                                            │
├────────────┼────────────────────────────────────────────────┼─────────────────────────────────────────────────────┤
│ pop_back   │ O(n) walk either way                           │ O(n) walk either way                                │
└────────────┴────────────────────────────────────────────────┴─────────────────────────────────────────────────────┘

So in a singly linked list the sentinel saves exactly one branch, in push_back. In exchange you need an extra allocation, 
an init step, and the "is it empty?" test becomes top == back instead of head == NULL. That's roughly break-even.


Q3) The interviewers question has no init function, have I handled the dummy node implementation correctly? 

the skeleton has no list_init(). It's probably a small negative rather than a serious one, especially if you explained 
why you chose it. Here's how an interviewer might see it:

- Your design needs setup the API doesn't give you. Any caller would have to know your internals and allocate the sentinel 
by hand, as your main did. A design where list l = {0}; is already a valid empty list (head and tail both NULL) fits the given 
API and is idiomatic C.
- The sentinel is heap-allocated and never freed, so every list leaks one node. Leaks get noticed in a Core OS interview.

If you use a sentinel again, two things make it cleaner:

1. Store it by value inside list (node sentinel;) so you don't need malloc or free.
2. Add a list_init() yourself and say so out loud, for example: "The skeleton has no init, so I'm adding one because my design 
   needs it." Adding a helper is fine. Silently depending on setup that only main knows about is what looks bad.



Q4) Is using a singly LL an efficient approach? What other data structures could I have used? 

Singly linked wasn't the best choice. The skeleton names all four operations, including pop_back, and a singly linked list can't 
do that in O(1) because finding the node before the tail means walking the whole list i.e. O(n).

What the API already tells you. push_* takes a node * and pop_* returns one. The caller owns the nodes and the list only links 
them together, so this is meant to be a linked list. An array or ring-buffer deque doesn't fit these signatures.

Options, from worst to best:

┌──────────────────────────┬────────────────┬──────────────────┬──────────────────────────────────────────────────┐
│        Structure         │    push/pop    │  push/pop back   │                      Notes                       │
│                          │     front      │                  │                                                  │
├──────────────────────────┼────────────────┼──────────────────┼──────────────────────────────────────────────────┤
│ Singly linked, head only │ O(1)           │ O(n) / O(n)      │ Worst fit                                        │
├──────────────────────────┼────────────────┼──────────────────┼──────────────────────────────────────────────────┤
│ Singly linked, head +    │ O(1)           │ O(1) push,       │ pop_back is still the problem                    │
│ tail (what you did)      │                │ O(n) pop         │                                                  │
├──────────────────────────┼────────────────┼──────────────────┼──────────────────────────────────────────────────┤
│ Doubly linked,           │ O(1)           │ O(1)             │ Correct, but every operation needs an            │
│ head/tail can be NULL    │                │                  │ "empty?" branch                                  │
├──────────────────────────┼────────────────┼──────────────────┼──────────────────────────────────────────────────┤
│ Doubly linked,           │ O(1)           │ O(1)             │ Best. No NULL checks and no special cases:       │
│ circular, one sentinel   │                │                  │ insert and remove are the same 4 pointer         │
│                          │                │                  │ updates every time                               │
└──────────────────────────┴────────────────┴──────────────────┴──────────────────────────────────────────────────┘

But the Doubly linked circular, one sentinel list still requires an init of some sort either via extra api function or the user has to be 
aware of its requirement. 

under the given API if I am not allowed to add any init function nor was the user expected to know the internals a doubly linked list 
with both top & back starting at NULL is the correct approach?

Yes. With those constraints, a doubly linked list whose head and tail both start at NULL is the right choice. It's the only design where 
a zero-initialized list (list l = {0};, or any static list) is already a valid empty list. That's the one convention every C programmer 
can be expected to follow, and it doesn't require knowing anything about the internals.

A circular sentinel can't meet these constraints. Its pointers have to point at its own address, so something has to run before the first 
use. You could hide that with a lazy init inside each operation (if (!l->s.next) l->s.next = l->s.prev = &l->s;), but that adds a branch 
to every call and defeats the reason for using a sentinel.


Q5) Thread-safety

A single lock is the right default.
There's no simple equivalent for a full deque where both ends push and pop.

Why two locks break this deque

The two ends aren't independent when the list has zero or one node.

Why don't two locks (one per end) make the doubly linked deque thread-safe?

Setup:  list = [A]          head -> A <- tail
        T1 calls pop_front()    holding head_lock only
        T2 calls push_back(B)   holding tail_lock only
        Both run at the same time, since they hold different locks.

Step | Thread | Action                       | State after the step
-----+--------+------------------------------+-----------------------------------------
  1  |   T1   | n = head                     | T1 is popping A
  2  |   T2   | B->prev = tail               | B->prev = A
  3  |   T1   | head = A->next               | head = NULL      (A->next still NULL)
  4  |   T2   | A->next = B                  | B is linked after A, but A is leaving
  5  |   T1   | head is NULL, so tail = NULL | tail = NULL      <-- T1 writes tail
     |        |                              |                      WITHOUT tail_lock
  6  |   T2   | tail = B                     | tail = B

Final state:
        head = NULL
        tail = B
        B->prev = A     (A was already popped and handed back to the caller)


Both threads write to A, and pop_front writes tail while only holding the head lock. The head == NULL ⇔ tail == NULL invariant 
is broken. To fix it, every operation that might touch the other end has to take both locks, always in the same order 
(head, then tail) to avoid deadlock. But you can't know whether the list is "near empty" without reading the other end's state, 
which already needs that end's lock. The fix ends up taking both locks most of the time, so you pay twice the locking cost for 
little real concurrency.


Adding a 2 dummy nodes at the head & tail end doesn't help either. With one real node X between the two dummies, 
both ends still try to unlink X at the same time.

Where two locks do work: the Michael–Scott two-lock queue

If the use case is a FIFO queue (producers only call push_back, consumers only call pop_front), there's a well-known correct design:
- The list always contains a dummy node, so head and tail never share a real node.
- push_back touches only tail and the last node's next, under the tail lock.
- pop_front advances head to the next node, which becomes the new dummy, under the head lock. It never touches tail.
- Even on an empty queue, the two ends work on different memory.


guard all four operations with one os_unfair_lock. It's simple and obviously correct, and the critical section is tiny. 
If profiling showed contention and the workload was producers at one end and consumers at the other, I'd switch to the 
Michael–Scott two-lock queue. Two locks don't work for a general deque because the ends share state when the list has zero 
or one node.

*/