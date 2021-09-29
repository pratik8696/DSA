#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node* first=NULL;
void DlListcreation(int n);
void displayDlList();
int main()
{
    int n;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    DlListcreation(n);
    displayDlList();
    return 0;
}

void DlListcreation(int n)
{
    struct Node *last,*t;
    first=(int*)malloc(sizeof(struct Node));
    int num;
    printf(" Enter data for node 1 : ");
    scanf("%d", &num);
    first->next=NULL;
    first->prev = NULL;
    first->data=num;
    last=first;
    for (int i = 2; i <= n; i++)    
    {
        int num2;
        t = (int *)malloc(sizeof(struct Node));
        printf(" Enter data for node %d : ", i);
        scanf("%d", &num2);
        t->data=num2;
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void displayDlList()
{
    struct Node* p=first;
    printf("\n Data entered on the list are :\n");
    int i=1;
    while(p!=NULL)
    {
    printf(" node %d : %d\n",i,p->data );
    i++;
    p=p->next;
    }
}
