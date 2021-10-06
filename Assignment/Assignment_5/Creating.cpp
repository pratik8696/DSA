/**************************
// SAMPLe


Enter the total number of nodes in list: 4
Enter data of 1 node: 8
Enter data of 2 node: 77
Enter data of 3 node: 3
Enter data of 4 node: 55
DATA IN THE LISt
Data 1 = 8
Data 2 = 77
Data 3 = 3
Data 4 = 55


***************************/
#include <stdio.h>
#include <stdlib.h>
void createList(int n);
void displayList();

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *last, *t, *it;

int main()
{
    int n;
    head = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);
    displayList();
    return 0;
}

void createList(int n)
{
    if (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("Enter data of %d node: ", i);

            if (i == 1)
            {
                head = (struct Node *)malloc(sizeof(struct Node));
                int firstnode;
                scanf("%d", &firstnode);
                head->data = firstnode;
                head->next = NULL;
                last = head;
            }

            else
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                int newnode;
                scanf("%d", &newnode);
                t->data = newnode;
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        last->next = head;
    }
}

void displayList()
{
    it = head;
    int flag = 0, i = 1;
    if (it != NULL)
    {
        printf("DATA IN THE LIST:\n");
        printf("Data 1 = %d\n", it->data);
        it = it->next;
    }
    while (it != head)
    {
        i++;
        printf("Data %d = %d\n", i, it->data);
        it = it->next;
    }
}
