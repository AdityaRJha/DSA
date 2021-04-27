#ifndef STACKS_H
#define STACKS_H

typedef struct t
{
    int data;
    struct t* next;
} node ;

node* shead;
node* createNode(int data);
void push(int data);
void pop();
int isEmpty();
void print(node *n);
void printStk();
void popAll();

#endif