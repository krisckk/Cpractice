#include <stdio.h>
#include <stdlib.h>
#include "function.h"

BTNode* EXPR() {
    BTNode* right_expr = FACTOR();
    // If a left parenthesis is encountered, or if we've hit the end of the input,
    // then the expression we just computed has to be a left expression instead.
    // So return it immediately.
    if (pos == -1 || expr[pos] == '(') return right_expr;//
    BTNode* head = makeNode(expr[pos--]); // An operator is always expected here.
    head->right = right_expr;
    head->left = EXPR();
    return head;
}
BTNode* FACTOR() {
    char input = expr[pos--];
    BTNode* factorized;
    switch (input) {
        case ')': {
            factorized = EXPR();
            // A '(' (left parenthesis) is always expected after a factorized expression, so we skip it.
            pos--;
            return factorized;
        }
        default:
            return makeNode(input);
    }
}
BTNode* makeNode(char c)
{

    BTNode *node=(BTNode*)malloc(sizeof(BTNode));
    for(int i=0;i<NUMSYM;i++)
    {
        if(c==sym[i])
        {
            node->data=i;
            break;
        }
    }
    node->left=NULL;
    node->right=NULL;

    return node;
}