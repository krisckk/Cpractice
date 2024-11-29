#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = data;
    newNode->ptr_to_left_node = newNode->ptr_to_right_node = NULL;
    return newNode;
}

int search(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTreeHelper(int* inorder, int* preorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* root = createNode(preorder[(*preIndex)++]);

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, root->number);

    root->ptr_to_left_node = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->ptr_to_right_node = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end) {
    int preIndex = 0;
    return buildTreeHelper(inorder, preorder, inorder_start, inorder_end, &preIndex);
}

void showPostorder(Node *root) {
    if (root == NULL)
        return;

    showPostorder(root->ptr_to_left_node);
    showPostorder(root->ptr_to_right_node);
    printf("%d ", root->number);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;

    freeTree(root->ptr_to_left_node);
    freeTree(root->ptr_to_right_node);
    free(root);
}
