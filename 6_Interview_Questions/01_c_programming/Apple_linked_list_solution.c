// Author: Yash Deshpande
// Date  : 07-10-2026
// Position: Darwin Runtime Engineer, Core OS
// Interviewers: Aaron Morrison, Bryce Wilson

// Reference solution for Apple_linked_list.c
//
// Design: doubly linked list, head and tail start as NULL.
//   - All four operations are O(1) (prev pointers make pop_back O(1)).
//   - No init function is needed: a zero-initialised list
//     (`list l = {0};`) is already a valid empty list, so callers don't
//     need to know anything about the internals.
//   - Each operation has exactly one edge case: the empty <-> non-empty
//     transition, where both head and tail must be updated together.
//
// Invariant: (head == NULL) == (tail == NULL)

// NOTE TO READER:
//   Before reading this code, see the "Claude Answers" Q&A section at the
//   bottom of Apple_linked_list_my_solution.c. It explains the design choices
//   (singly vs doubly linked, dummy/sentinel node, no init function), the bug
//   in the original interview attempt, and why the reference solution in
//   Apple_linked_list_solution.c is structured the way it is.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} node;

typedef struct list {
  node *head;
  node *tail;
} list;

node *
pop_front(list *l)
{
  if (l == NULL || l->head == NULL)
    return NULL;

  node *n = l->head;
  l->head = n->next;
  if (l->head)
    l->head->prev = NULL;
  else
    l->tail = NULL;           // popped the last node -> list is now empty

  n->next = n->prev = NULL;   // don't hand back dangling links
  return n;
}

void
push_front(list *l, node *n)
{
  if (l == NULL || n == NULL)
    return;

  n->prev = NULL;
  n->next = l->head;
  if (l->head)
    l->head->prev = n;
  else
    l->tail = n;              // list was empty -> n is also the tail
  l->head = n;
}

node *
pop_back(list *l)
{
  if (l == NULL || l->tail == NULL)
    return NULL;

  node *n = l->tail;
  l->tail = n->prev;
  if (l->tail)
    l->tail->next = NULL;
  else
    l->head = NULL;           // popped the last node -> list is now empty

  n->next = n->prev = NULL;
  return n;
}

void
push_back(list *l, node *n)
{
  if (l == NULL || n == NULL)
    return;

  n->next = NULL;
  n->prev = l->tail;
  if (l->tail)
    l->tail->next = n;
  else
    l->head = n;              // list was empty -> n is also the head
  l->tail = n;
}

void print_node(node *n) {
  if (n == NULL)
    printf("(null)");
  else
    printf("%d", n->data);
}

void print_list(list *l) {
  if (l == NULL) {
    printf("(null list)\n");
    return;
  }
  printf("[");
  for (node *n = l->head; n != NULL; n = n->next) {
    print_node(n);
    if (n->next)
      printf(", ");
  }
  printf("]\n");
}

// ---------------------------------------------------------------------------
// Tests
// ---------------------------------------------------------------------------

static node *
make_node(int v)
{
  node *n = malloc(sizeof(*n));
  assert(n != NULL);
  n->data = v;
  n->prev = n->next = NULL;
  return n;
}

// Pops n, checks its value and that it was fully unlinked, then frees it.
static void
expect_and_free(node *n, int v)
{
  assert(n != NULL);
  assert(n->data == v);
  assert(n->next == NULL && n->prev == NULL);
  free(n);
}

// Walks the list both ways and checks it matches `expected`.
static void
check_list(list *l, const int *expected, int len)
{
  int i = 0;
  node *prev = NULL;
  for (node *n = l->head; n != NULL; n = n->next, i++) {
    assert(i < len);
    assert(n->data == expected[i]);
    assert(n->prev == prev);
    prev = n;
  }
  assert(i == len);
  assert(l->tail == prev);    // tail is the last node reached (NULL if empty)

  i = len - 1;
  for (node *n = l->tail; n != NULL; n = n->prev, i--)
    assert(n->data == expected[i]);
  assert(i == -1);
}

static void
test_empty_list(void)
{
  list l = {0};               // zero-init is a valid empty list, no init needed
  assert(pop_front(&l) == NULL);
  assert(pop_back(&l) == NULL);
  check_list(&l, NULL, 0);
  print_list(&l);
}

static void
test_null_arguments(void)
{
  list l = {0};
  assert(pop_front(NULL) == NULL);
  assert(pop_back(NULL) == NULL);
  push_front(NULL, NULL);
  push_back(NULL, NULL);
  push_front(&l, NULL);       // NULL node must not corrupt the list
  push_back(&l, NULL);
  check_list(&l, NULL, 0);
}

// The bug from the interview attempt: popping the only node must reset BOTH
// ends, otherwise tail/back dangles at a node that is no longer in the list.
static void
test_single_node_both_ends_reset(void)
{
  list l = {0};

  push_front(&l, make_node(1));
  assert(l.head == l.tail);
  expect_and_free(pop_front(&l), 1);
  assert(l.head == NULL && l.tail == NULL);

  push_back(&l, make_node(2));
  assert(l.head == l.tail);
  expect_and_free(pop_back(&l), 2);
  assert(l.head == NULL && l.tail == NULL);
}

// Push at one end, pop at the other with a single element.
static void
test_single_node_cross_ends(void)
{
  list l = {0};

  push_front(&l, make_node(1));
  expect_and_free(pop_back(&l), 1);
  check_list(&l, NULL, 0);

  push_back(&l, make_node(2));
  expect_and_free(pop_front(&l), 2);
  check_list(&l, NULL, 0);
}

// Use the list as a stack from each end (LIFO).
static void
test_stack_order(void)
{
  list l = {0};
  for (int i = 1; i <= 3; i++)
    push_front(&l, make_node(i));
  check_list(&l, (int[]){3, 2, 1}, 3);
  for (int i = 3; i >= 1; i--)
    expect_and_free(pop_front(&l), i);

  for (int i = 1; i <= 3; i++)
    push_back(&l, make_node(i));
  check_list(&l, (int[]){1, 2, 3}, 3);
  for (int i = 3; i >= 1; i--)
    expect_and_free(pop_back(&l), i);

  check_list(&l, NULL, 0);
}

// Use the list as a queue in both directions (FIFO).
static void
test_queue_order(void)
{
  list l = {0};
  for (int i = 1; i <= 3; i++)
    push_back(&l, make_node(i));
  for (int i = 1; i <= 3; i++)
    expect_and_free(pop_front(&l), i);

  for (int i = 1; i <= 3; i++)
    push_front(&l, make_node(i));
  for (int i = 1; i <= 3; i++)
    expect_and_free(pop_back(&l), i);

  check_list(&l, NULL, 0);
}

// Interleave operations on both ends; prev/next must stay consistent.
static void
test_mixed_operations(void)
{
  list l = {0};
  push_back(&l, make_node(2));
  push_front(&l, make_node(1));
  push_back(&l, make_node(3));
  push_front(&l, make_node(0));
  check_list(&l, (int[]){0, 1, 2, 3}, 4);
  print_list(&l);

  expect_and_free(pop_back(&l), 3);
  expect_and_free(pop_front(&l), 0);
  check_list(&l, (int[]){1, 2}, 2);

  // Down to two nodes, then one: the remaining node must be head AND tail.
  expect_and_free(pop_back(&l), 2);
  check_list(&l, (int[]){1}, 1);
  assert(l.head == l.tail);
  expect_and_free(pop_front(&l), 1);
  check_list(&l, NULL, 0);
}

// After draining, the list must be fully reusable (no stale head/tail).
static void
test_reuse_after_drain(void)
{
  list l = {0};
  for (int round = 0; round < 3; round++) {
    push_back(&l, make_node(10));
    push_front(&l, make_node(20));
    check_list(&l, (int[]){20, 10}, 2);
    expect_and_free(pop_back(&l), 10);
    expect_and_free(pop_back(&l), 20);
    check_list(&l, NULL, 0);
    assert(pop_front(&l) == NULL);
  }
}

// A popped node is fully unlinked, so it can be moved to another list.
static void
test_move_node_between_lists(void)
{
  list a = {0}, b = {0};
  push_back(&a, make_node(1));
  push_back(&a, make_node(2));

  push_front(&b, pop_back(&a));
  check_list(&a, (int[]){1}, 1);
  check_list(&b, (int[]){2}, 1);

  expect_and_free(pop_front(&a), 1);
  expect_and_free(pop_front(&b), 2);
}

int main()
{
  test_empty_list();
  test_null_arguments();
  test_single_node_both_ends_reset();
  test_single_node_cross_ends();
  test_stack_order();
  test_queue_order();
  test_mixed_operations();
  test_reuse_after_drain();
  test_move_node_between_lists();

  printf("all tests passed\n");
  return 0;
}
