#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;
void Create(int arr[],int size)
{
    first=new Node;
    struct Node *last,*t;
    first->data=arr[0];
    first->next=NULL;
    last=first;

       for (int i = 1; i < size; i++)
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
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        Display(p->next);
    }
    else if(p==NULL){
        return 0;
    }
}

int main()
{
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    // constructing a linked list
    Create(array,10);
    Display(first);
    return 0;
}