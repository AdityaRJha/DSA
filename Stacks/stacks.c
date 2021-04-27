#include "stacks.h"
#include <stdlib.h>
#include <stdio.h>

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node *)) ;
    newNode ->data = data;
    return newNode;
}

int isEmpty()
{
    if (!shead)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    if (isEmpty())
    {
        shead = createNode(data);
    }
    else
    {
        node* newnode = createNode(data);
        newnode ->next = shead;
        shead = newnode;
    }
}

void pop()
{
    if (!isEmpty)
    {
        exit(0);
    }
    node *temp = shead -> next;
    free(shead);
    shead = temp;
}

void popAll()
{
    while(shead)
    {
        pop();
    }
}

void print(node* n)
{
    printf("%d\n", n->data);
}

void printStk()
{
    node *current = shead;
    while (current)
    {
        print(current);
        current = current -> next;
    }
    print(current);    
}