#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int n)
{
    Node* head;
    head = (Node *)malloc(sizeof(Node));
    head -> number = 1;

    Node *current = head;
    for(int i = 2; i <= n; ++i){
        current -> next = (Node *)malloc(sizeof(Node));
        current = current -> next;
        current -> number = i;
    }
    current -> next = head;
    return head;
}
void freeList(Node* head)
{
    free(head);
}
int solveJosephus(Node **head, int step)
{
    // Count number of nodes
    int n = 0;
    Node *tmp, *deleteNode;

    for(tmp = *head; n <= tmp -> number; tmp = tmp -> next, n++);
    //repeatly delete nodes
    while(n > 1){
        int actualStep = ((step - 1) % n - 1 + n) % n;
        // step - 1 : 0 based index
        // % : remove duplicates counting
        // -1 : previous node of deleted node
        // +n : avoid negative value
        // % : to range in [0, n - 1]

        tmp = *head;
        for(int i = 0; i < actualStep; ++i){
            tmp = tmp -> next;
        }
        deleteNode = tmp -> next;
        tmp -> next = tmp -> next -> next;
        *head = tmp -> next;
        free(deleteNode);
        n--;
    }
    return (*head) -> number;
}
int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
   {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}