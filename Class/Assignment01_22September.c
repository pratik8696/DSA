#include <stdio.h>
#include <stdlib.h>
void createNodeList(int n);
void displayList();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last, *t;

int main()
{
    int n;
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    if (n > 0)
    {
        createNodeList(n);
        printf("Data entered in the list : ");
        displayList();
    }
    return 0;
}
void createNodeList(int n)
{
    if (n > 0)
    {
        head = (struct Node *)malloc(sizeof(struct Node));
        int first;
        scanf("%d", &first);
        head->data = first;
        head->next = NULL;
        last = head;
        for (int i = 1; i < n; i++)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            int curr_element;
            scanf("%d", &curr_element);
            t->data = curr_element;
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
}
void displayList()
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
