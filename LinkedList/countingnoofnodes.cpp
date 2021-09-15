#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first;

void createLinkedList(int arr[], int n)
{
    struct Node *last, *t;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int countnoofnodes(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
    }
    return count;
}

int main()
{
    int count;
    cin >> count;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    createLinkedList(arr, count);
    Display(first);
    cout<<endl<<"The no of nodes in the linked list are = "<<countnoofnodes(first)<<endl;

    return 0;
}