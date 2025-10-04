#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* buildTree(int *arr, int index, int size) {
    // Base Case.
    if(index >= size) {
        return NULL;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = arr[index];

    if(2*index + 1 < size) {
        temp->left = buildTree(arr, 2*index+1, size);
    }

    if(2*index +2 < size) {
        temp->right = buildTree(arr, 2*index+2, size);
    }
    return temp;
}

void levelOrderTraversal(Node *head) {
    if(head == NULL) {
        return;
    }

    levelOrderTraversal(head->left);
    printf("%d ", head->data);
    levelOrderTraversal(head->right);
}

int main() {
     int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
     struct Node * head = buildTree(arr, 0, 10);
     levelOrderTraversal(head);
    return 0;
}