// implementing circular linked list;
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first;

int createlinkedlist(int arr[],int n)
{
    struct Node *last;
    struct Node *t;
    first=new Node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for (int i = 1; i < n; i++)
    {
        t=new Node;
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


int main()
{
    int count;
    cin>>count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    createlinkedlist(arr,count);
    Display(first);
    return 0;
}