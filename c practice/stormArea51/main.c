#include <stdio.h>
#include <stdlib.h>
#define MAX_N 101
enum {VAL, ID, OP};
typedef struct Node
{
    int type;
    int val;
    char op_id;
    struct Node *left, *right;
} Node;

struct Node *createNode(int type, int value, char op_id){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> type = type;
    newNode -> val = value;
    newNode -> op_id = op_id;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}
char exp[MAX_N];
int ids[3];

struct Node *build_tree(){
    scanf("%s", exp);
    Node* current;
    if('0' <= exp[0] && exp[0] <= '9') current = createNode(VAL, atoi(exp), '\0');
    else if('x' <= exp[0] && exp[0] <= 'z') current = createNode(ID, 0, exp[0]);
    else current = createNode(OP, 0, exp[0]);

    switch(current -> type){
        case VAL:
        case ID:
            break;
        case OP:
            current -> left = build_tree();
            current -> right = build_tree();
            break;
    }
    return current;
}
int showInorder(Node *current){
    int l, r;
    switch(current -> type){
        case VAL:
            printf("%d", current -> val);
            return current -> val;
        case ID:
            printf("%c", current -> op_id);
            return ids[current -> op_id - 'x'];
        case OP:
            l = showInorder(current -> left);
            printf("%c", current -> op_id);
            r = showInorder(current -> right);
            switch(current -> op_id){
                case '+': return l + r;
                case '-': return l - r;
                case '*': return l * r;
                case '/': return l / r;
                default: exit(1);
            }
        default: exit(1);
    }
}
int main(){
    Node *root = build_tree();
    scanf("%d%d%d", &ids[0], &ids[1], &ids[2]);
    printf("\n%d\n", showInorder(root));
    return 0;
}
