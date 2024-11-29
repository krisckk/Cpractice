#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;
Node *newNode(char *color){
    Node *res = (Node*)malloc(sizeof(Node));
    res -> next = NULL;
    strcpy(res -> color, color);
}

void insert(Node** head, char* color, int dest) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->color, color);
    
    Node* current = *head;
    // Move "current" to one node to the destination node.
    // If dest is larger than sequence length, "current" will stop on the last element of the sequence.

    int i = 0;
    while (i < dest && current->next != NULL) {
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void erase1(Node** head, int dest) {
    Node* current = *head;
    Node* to_delete = NULL;
    // Move "now" to one node to the destination node.
    // If dest is larger than sequence length, "now" will stop on the last element of the sequence.
    for (int i = 0; i < dest - 1 && current->next != NULL; i++) {
        current = current->next;
    }
    
    if (current->next != NULL) {
        to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }
}

void erase2(Node** head, char* color) {
    Node* current = *head;
    Node* to_delete;
    
    while (current != NULL) {
        if (!strcmp(current->color, color)) {
            // Color matches, Erase the node current
            to_delete -> next = current->next;
            free(current);
            // Since current has been freed, we need to assign "current" a new valid node*
            // We assign "current" to "to_delete" because we will move "current" forward right after this line
            current = to_delete;
        }
        to_delete = current;
        current = current -> next;
    }
}

void reverse(Node** head, int dest1, int dest2) {
    Node *current = (*head), *left = NULL;
    int idx;
    // Move "now" to one node to dest1 node.
    // If dest is larger than sequence length, "now" will stop on the last element of the sequence.
    // "left" is the node that right before dest1 node (previous node of dest1 node).
    for(idx = 0; current -> next != NULL && idx != dest1; left = current, current = current -> next, ++idx);
    while(current -> next != NULL && idx < dest2){
        Node *tmp = current -> next;
        current -> next = tmp -> next;
        tmp -> next = left -> next;
        left -> next = tmp;
        ++idx;
    }
}

// The show function is already implemented in the provided code