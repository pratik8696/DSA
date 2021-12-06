#include <stdio.h>
#include <stdlib.h>
void createlist(int);
struct node
{
    int item;
    struct node *next;
};
struct node *head = NULL;
int main()
{
    int n;
    printf("enter number of nodes in a linked list\n");
    scanf("%d", &n);
    createlist(n);
    int data;
    printf("Enter the data you want to delete\n");
    scanf("%d", &data);
    if (find_node(data))
        printf("Yes the data found\n");
    else
        printf("Given data not found\n");
    return 0;
}
// CREATE LIST IS USED TO CREATE LINKED LIST HERE
void createlist(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        int data;
        struct node *t, *r;
        t = (struct node *)malloc(sizeof(struct node));
        printf("enter the data in the node %d : ", i);
        scanf("%d", &data);
        printf("\n");
        t->item = data;
        t->next = NULL;
        if (head == NULL)
        {
            head = t;
            r = t;
        }
        else
        {
            r->next = t;
            r = r->next;
        }
    }
}
// HERE IN FIND NODE I AM FINDING THE ELEMENT ALONG WITH THAT
// I AM MOVING THAT NODE TO FRONT AS HEAD NODE .
int find_node(int data)
{
    if (head->item == data)
        return 1;
    if (head == NULL)
        return 0;
    struct node *t = head->next;
    struct node *pre = head;
    while (t)
    {
        if (t->item == data)
        {
            pre->next = t->next;
            t->next = head;
            head = t;
            return 1;
        }
        pre = t;
        t = t->next;
    }
    return 0;
}