// Author: Yash Deshpande
// Date  : 31-10-2025
// Tutor :

// Q. Define the following functions
// insertAtHead()
// insertAtTail()
// insertAtPostion()
// deleteNode()
// print()

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtHead(struct Node** head, struct Node** tail, int val) {
    // Create node.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;

    // Add the node to the head.
    if(*head == NULL) {
        // Case-1: LL is empty
        *head = temp;
        *tail = temp;
    }
    else {
        temp->next = *head;
        *head = temp;
    }
}

void insertAtTail(struct Node** head, struct Node** tail, int val) {
    // Create the Node. 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;

    if(*head == NULL) {
        // Case-1: LL is empty
        *head = temp;
        *tail = temp;
    }
    else {
        (*tail)->next  = temp;
        *tail = temp;
    }
}

void insertAtPosition(struct Node** head, struct Node** tail, int val, int index) {
    // Check if index is valid.
    
    // 0-index LL
    if(index == 0) {
        insertAtHead(head, tail, val);
    }

    // Traverse the list.
    struct Node* ptr = *head;
    for(int i=0; i<(index-1); i++) {
        ptr = ptr->next;
    }

    // last index.
    if(ptr == *tail) {
        insertAtTail(head, tail, val);
        return;
    }

    // Insert in the middle.
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = ptr->next;
    ptr->next = temp;
}

void deleteNode(struct Node** head, struct Node** tail, int index) {
    // Check if the index is valid

    // Check if the LL is empty
    if(*head == NULL) {
        return;
    }

    // Check if head 
    if(index == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        temp = NULL;
    }
    else {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        for(int i=0; i<index; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Check if last node
        if(curr == *tail) {
            *tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
        curr = NULL;
    }
}

void print(struct Node* head) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {

    // //***************************
    // // Insert at beginning of SLL
    // //***************************

    // // Create a new Node
    // struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    // node1->data = 150;
    // node1->next = NULL;

    // // Make it head node
    // struct Node *head = node1;
    // print(head);

    // struct Node *tail = head;

    // // Insertion at beginning
    // insertAtHead(&head, &tail, 25);
    // print(head);

    // insertAtHead(&head, &tail, 67);
    // print(head);

    // //**********************
    // //  Insert at End of SLL
    // //**********************

    // // Note : "tail pointer" is not a
    // // necessity , insertion at end can
    // // also be done using SLL traversal

    // // Create a new Node
    // struct Node * node1 = (struct Node*)malloc(sizeof(struct Node));
    // node1->data = 44;
    // node1->next = NULL;

    // // Make it head
    // struct Node *head = node1;

    // // Make it Tail
    // struct Node *tail = node1;
    // print(head);

    // // Insert at end
    // insertAtTail(&head, &tail, 63);
    // // print(head);

    // insertAtTail(&head, &tail, 77);
    // print(head);


    // // **********************
    // // Insert at any position
    // // **********************

    // // Create a new Node
    // struct Node * node1 = (struct Node*)malloc(sizeof(struct Node));
    // node1->data = 44;
    // node1->next = NULL;

    // // Make it head
    // struct Node *head = node1;

    // // Make it Tail
    // struct Node *tail = node1;
    // print(head);

    // insertAtTail(&head, &tail, 63);
    // insertAtTail(&head, &tail, 105);
    // insertAtHead(&head, &tail, 67);
    // insertAtHead(&head, &tail, -9);
    // print(head);

    // insertAtPosition(&head, &tail, 32, 3);
    // insertAtPosition(&head, &tail, 55, 5);
    // print(head);


    // ************************
    // Deletion at any position
    // ************************

    // NOTE : Deletion can be done using index & value

    // Create a new Node
    struct Node * node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 44;
    node1->next = NULL;
    
    // Make it head
    struct Node *head = node1;

    // Make it Tail
    struct Node *tail = node1;
    print(head);

    insertAtTail(&head, &tail, 63);
    insertAtTail(&head, &tail, 105);
    insertAtHead(&head, &tail, 67);
    insertAtHead(&head, &tail, -9);
    print(head);
    printf("tail : %d\n", tail->data);

    deleteNode(&head, &tail, 4);
    print(head);
    printf("tail : %d\n", tail->data);

    return 0;
}