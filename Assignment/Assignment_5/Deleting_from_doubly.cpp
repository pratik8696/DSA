/************************** 
 sample ;
 
 
 
 
 
Enter the total number of nodes in list : 4
Enter the data of node 1 : 6
Enter the data of node 2 : 13
Enter the data of node 3 : 19
Enter the data of node 4 : 22
Enter the data of node 5 : 21

the dll is:
6
13
19
22
21

after deletion dll is:
6 
13
19
22




***************************/
#include <stdio.h>
#include <stdlib.h>
void createList(int n);
void displayList();
void delete_end();

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last, *t;

int main()
{
    int n;
    head = NULL;
    last = NULL;
    printf("Enter the total number of nodes in list : ");
    scanf("%d", &n);
    createList(n);
    printf("\nthe dll is:\n");
    displayList();
    delete_end();
    printf("\nafter deletion dll is:\n");
    displayList();
    return 0;
}

void createList(int n)
{
    for (int i = 1; i <= n ; i++)
    {
        printf("Enter the data of node %d : ",i);

        if(i==1)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            int firstnode;
            scanf("%d", &firstnode);
            head->data = firstnode;
            head->prev = NULL;
            head->next = NULL;
            last = head;
        }

        else{
        t = (struct Node *)malloc(sizeof(struct Node));
        int newnode;
        scanf("%d", &newnode);
        t->data = newnode;
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
        }
    }
}

/* Function to delete the node at the end of the list */
void delete_end()
{
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next=NULL;
    free(p);
}

void displayList()
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
