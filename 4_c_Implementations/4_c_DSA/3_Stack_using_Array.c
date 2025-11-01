// Author: Yash Deshpande
// Date  : 31-10-2025
// Tutor : https://www.geeksforgeeks.org/c/array-implementation-of-stack-in-c/

// ################################
// Fundamental Stack Operations are 
// 1. push()
// 2. pop()
// 3. peek()
// 4. isEmpty()
// 5. size()
// ################################

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Stack {
    int* arr;
    int top;
    int size;
};

void createStack(struct Stack* st ,int capacity) {
    st->size = capacity;
    st->arr = (int *)malloc(sizeof(int) * capacity);
    st->top = -1;
} 

bool isEmpty(struct Stack* st) {
    if(st->top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void push(struct Stack* st, int val) {
    if(st->size - st->top == 1) {
        printf("Stack Overflow\n");
        return;
    }
    st->top++;
    st->arr[st->top] = val;
}

void pop(struct Stack* st) {
    if(st->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    st->top--;
}

int peek(struct Stack* st) {
    if(st->top == -1) {
        printf("Stack is Empty\n");
        return INT_MIN;
    }

    return st->arr[st->top];
}

int size(struct Stack* st) {
    return st->top + 1;
}

void display(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    }
    else {
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->arr[i]);
        }
    }
}

int main() {
    struct Stack stack;
    createStack(&stack, 100);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    pop(&stack);
    printf("Popped from stack\n");
    printf("Top element is %d\n", peek(&stack));

    printf("Elements present in stack:\n");
    display(&stack);
    return 0;
}