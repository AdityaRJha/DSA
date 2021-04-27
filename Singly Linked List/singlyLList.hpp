#ifndef SINGLYLLIST_HPP
#define SINGLYLLIST_HPP

struct node
{
    int data;
    node* next;
};

class singlyLList
{
private:
    node* head;
    
public:
    singlyLList(int dataForHead);
    singlyLList(node *a);
    node* createNode(int data);
    void swapNodes(node *a, node *b);
    void print(node * n);
    void delNode(node *n);
    node** getHead();
    void setHead(node* a);
    void delList();    
    ~singlyLList();
};

void insert(singlyLList *list, int data, int pos = 0);
void del(singlyLList *list, int pos);
void insorted(singlyLList *list, int data);
void reverse(singlyLList *list);
void printPos(singlyLList *list, int pos);
void printList(singlyLList *list);
node* getNode(singlyLList *list, int pos);
void swapNodes(singlyLList *list, int x, int y);//based on the data stored in it.
singlyLList* merge(singlyLList *a, singlyLList *b);
singlyLList* mergeSorted(singlyLList *a, singlyLList *b);
void mergeSort(singlyLList *list);
void mergeSort(node **head_ref);
node* mergeSorted(node *a, node* b);
void splitMid(node *head, node **front_ref, node **back_ref);

#endif