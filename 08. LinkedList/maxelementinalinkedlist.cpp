#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;

int sum(struct Node *p)
{
    int summation = 0;
    while (p != NULL)
    {
        summation += p->data;
        p = p->next;
    }
    return summation;
}

int Create(int arr[], int n)
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

int maxandmin(struct Node *p)
{
    int maxno=INT_MIN;
    for (int i = 0; i < p.size()-1; i++)
    {
        maxno=max(maxno,p->data);
        p=p->next;
    }
    
}

int Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
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
    Create(arr, count);
    // cout << sum(first);
}