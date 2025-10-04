#include <stdio.h>
#include <stdlib.h>

// Q. Given an array of integers, construct a linked list 

struct Node {
    int data;
    struct Node* next;  
};

// Implementation-1
struct Node * create_linked_list1(struct Node* head, int *arr, int arr_size) {
    struct Node *tail = head;
    
    for(int i=0; i < arr_size; i++) {
        // create the node
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        // attach the node to the linked list
        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

// Implementation-2
void create_linked_list2(struct Node** head, int *arr, int arr_size) {
    struct Node *tail = *head;
    
    for(int i=0; i < arr_size; i++) {
        // create the node
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        // attach the node to the linked list
        if(*head == NULL) {
            *head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
}

void print(struct Node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse(struct Node **head) {
    struct Node *curr = *head;
    struct Node *prev = NULL;
    struct Node *forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    *head = prev;
}

int main() {
    
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    // struct Node *head = create_linked_list1(head, arr, 10);

    struct Node *head = NULL;
    create_linked_list2(&head, arr, 10);
    print(head);

    reverse(&head);
    print(head);

    return 0;
}