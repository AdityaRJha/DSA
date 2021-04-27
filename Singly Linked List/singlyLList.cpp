#include "singlyLList.hpp"
#include <iostream>

using namespace std;

singlyLList::singlyLList(node* a)
{
    setHead(a);
}

node** singlyLList::getHead()
{
    return &head;
}

void singlyLList::setHead(node *a)
{
    head = a;
}

node* singlyLList::createNode(int data)
{
    node *p;
    p = new node;
    p->data = data;
    return p;
}

singlyLList::singlyLList(int dataForHead)
{
    head = createNode(dataForHead);
}

void singlyLList::delNode(node *n)
{
    delete n;    
}

void insert(singlyLList *list, int data, int pos)
{
    node *current = *(list->getHead());
    if (current && current -> data != data)
    {
        current = getNode(list,pos);
    }
    node *newNode = list->createNode(data);
    current -> next = newNode;    
}

void insorted(singlyLList *list, int data)
{
    node *current = *(list->getHead());
    node *prev = *(list->getHead());
    if (current && current ->data != data)
    {
        int i =0 ;
        while (current != NULL)
        {
            if (current->next->data >= data)
            {
                prev = current;
                break;
            }
            prev = current;
            current = current -> next;
        }
    }

    node *newNode = list->createNode(data);
    newNode -> next = prev -> next;
    prev -> next = newNode;
}

void del(singlyLList *list, int pos)
{
    node *current = getNode(list,pos);
    list ->delNode(current);
}

void reverse(singlyLList *list)
{
    node *current = *(list->getHead());
    node *prev, *temp;
    while(current)
    {
        temp = current;
        current = current ->next;
        temp ->next = prev;
        prev = temp;
        
    }
    list->setHead(prev);
}

node* getNode(singlyLList *list, int pos)
{
    node* current = *(list->getHead());
    int i =0;
    while (i != pos)
    {
        current = current -> next;
    }
    return current;
}

void singlyLList::delList()
{
    node *temp;
    while (head)
    {
        temp = head ->next;
        delNode(head);
        head = temp;
    }
    
}

void print(node *n)
{
    cout<<"\n********************\n";
    cout<<"Data = "<<n->data;
    cout<<"\n********************\n";
}


void printPos(singlyLList *list, int pos)
{
    node* current = getNode(list,pos);
    cout<<"\nNode at POS: "<<pos;
    print(current);
}

void printList(singlyLList *list)
{
    node* current = *(list->getHead());
    while (current)
    {
        print(current);
        current = current -> next;
    }
}

singlyLList :: ~singlyLList()
{
    cout<<"\nDeleting the LIST\n";
    delList();
    cout<<"OVER N OUT\n";
}

void swapNodes(node* a, node *b)
{
    if (a && b)
    {
        node * temp = a;
        a = b;
        b = temp;
    }
    
}

void swapNodes(singlyLList *list, int a, int b)
{
    node* current = *(list->getHead());
    node* A = NULL;
    node* B = NULL;
    while (current)
    {
        if (current->data == a)
        {
            A = current;
        }
        if(current -> data == b)
        {
            B = current;
        }
        if (A && B)
        {
            break;
        }
        current = current -> next;
    }
    swapNodes(A, B);
    swapNodes(A->next, B->next);
}

singlyLList* merge(singlyLList *a, singlyLList *b)
{
    node* result = new node();
    result = *(a->getHead()); 
    while(result -> next != NULL)
    {
        result = result ->next;
    }
    result -> next = *(b->getHead());
    singlyLList* res = new singlyLList(result);
    return res;
}

node* mergeSorted(node *ahead, node *bhead)
{
    node *newHead;
    while (ahead->next != NULL || bhead->next != NULL)
    {
        if(ahead->data <= bhead->data)
        {
            newHead->next = ahead;
            ahead = ahead->next;
        }
        else
        {
            newHead->next = bhead;
            bhead = bhead->next;
        }
    }
    if(ahead->next = NULL)
    {
        if (ahead->data <= bhead->data)
        {
            ahead->next = bhead;
            newHead->next = ahead;
        }
        else
        {
            ahead->next = bhead->next;
            bhead->next = ahead;
            newHead ->next = bhead;
        }
        
    }
    else
    {
        if (bhead->data <= ahead->data)
        {
            bhead ->next = ahead;
            newHead->next = bhead;
        }
        else
        {
            bhead->next = ahead ->next;
            ahead->next = bhead;
            newHead->next = ahead;
        }
    }
    return newHead;
}

singlyLList* mergesorted(singlyLList *a, singlyLList *b)
{
    node *newHead = mergeSorted(*(a->getHead()),*(b->getHead()));
    singlyLList *newList = new singlyLList(newHead);
    return newList;       
}

void mergeSort(singlyLList *list)
{
    mergeSort(list->getHead());
}

void splitMid(node *head, node **front_ref, node **back_ref)
{
    node *slow = head;
    node *fast = head->next;

    while (fast->next)
    {
        fast = fast->next;
        if (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
    }

    *front_ref = head;
    *back_ref = slow->next;
    slow->next = NULL;
}

void mergeSort(node **head_ref)
{
    node *head = *head_ref;
    node *a, *b;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    
    splitMid(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    head = mergeSorted(a,b);
}