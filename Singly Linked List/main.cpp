#include "singlyLList.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of the nodes for Linked List";
    cin>>n;

    singlyLList *list = new singlyLList(n);
    for(int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        insert(list, data);
    }

    //any any code you want to
    list->~singlyLList();
}