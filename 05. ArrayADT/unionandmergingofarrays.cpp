#include <iostream>
using namespace std;

struct array
{
    int *A;
    int size;
    int length;
};
int Swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}
int Display(struct array arr)
{
    cout << "The elements of the array are" << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl
         << "The length of the array is " << arr.length << endl;
    cout << endl;
}
// adding an element at the last of the index
int Add(struct array *a, int x)
{
    a->A[a->length] = x;
    a->length++;
}
// adding element at any index
int Insert(struct array *a, int index, int x)
{
    for (int i = a->length; i > index; i--)
    {
        a->A[i] = a->A[i - 1];
    }
    a->A[index] = x;
    a->length++;
}
// deleting element at a particular index
int Delete(struct array *a, int index)
{
    for (int i = index; i < a->length; i++)
    {
        a->A[i] = a->A[i + 1];
    }
    a->length--;
}
// Linear Search
int LinearSearch(struct array a, int key)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] == key)
        {
            return 1;
        }
    }
    return -1;
}
// Improved Linear Search
int ImprovedLinearSearch(struct array a, int key)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.A[i] == key)
        {
            a.A[0] = a.A[i];
            // a.A[i - 1] = a.A[i];
            // [you can prefer any one operations in one of these]
            cout << "Match Found by improved linear search" << endl;
        }
    }
}

int negativeleft(struct array *a)
{
    int i = 0, j = (a->length) - 1;

    while (i < j)
    {

        while (a->A[i] < 0)
        {
            i++;
        }
        while (a->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            Swap(&a->A[i], &a->A[j]);
        }
    }
}

int negativeright(struct array *a)
{
    int i = 0, j = (a->length) - 1;

    while (i < j)
    {

        while (a->A[i] >= 0)
        {
            i++;
        }
        while (a->A[j] < 0)
        {
            j--;
        }
        if (i < j)
        {
            Swap(&a->A[i], &a->A[j]);
        }
    }
}

int *maxandmin(struct array p)
{
    int max = p.A[0], min = p.A[0];
    for (int i = 0; i < p.length; i++)
    {
        if (p.A[i] > max)
        {
            max = p.A[i];
        }
        else if (p.A[i] < min)
        {
            min = p.A[i];
        }
    }
    int *t = new int[2];
    t[0] = max;
    t[1] = min;
    return t;
}

int sumwithk(struct array p, int k)
{
    for (int i = 0; i < (p.length) - 1; i++)
    {
        for (int j = i + 1; j < p.length; j++)
        {
            if (p.A[i] + p.A[j] == k)
            {
                cout << "The pair is " << p.A[i] << " + " << p.A[j] << " = " << k << endl;
            }
        }
    }
    return 0;
}

int findingsumusinghash(struct array p, int k)
{
    int H[1000];
    for (int z = 0; z < 1000; z++)
    {
        H[z] = 0;
    }
    for (int i = 0; i < p.length; i++)
    {
        // here u can miss a very imp thing
        // if the hash array is not long enough then it can cause many problems so
        // always take a long array and use that as your hash table
        if (H[k - p.A[i]] != 0)
        {
            cout << "The pair is " << p.A[i] << " + " << k - p.A[i] << " = " << k << endl;
        }
        else
        {
            H[p.A[i]]++;
        }
    }
}

int pairsortedarray(struct array p, int k)
{
    int i = 0;
    int j = p.length - 1;
    while (i < j)
    {
        if (p.A[i] + p.A[j] == k)
        {
            cout << "The pair is " << p.A[i] << " + " << k - p.A[i] << " = " << k << endl;
            i++;
            j--;
        }
        else if (p.A[i] + p.A[j] > k)
        {
            j--;
        }
        else if (p.A[i] + p.A[j] < k)
        {
            i++;
        }
    }
}

int mergingofarrays(struct array p, struct array q)
{
    struct array r;
    r.length = p.length + q.length;
    r.size = p.size + q.size;
    int i, j, k;
    i = j = k = 0;
    while (i < p.length && j < q.length)
    {
        if (p.A[i] > q.A[j])
        {
            r.A[k++] = q.A[j++];
        }
        else if (p.A[i] < q.A[j])
        {
            r.A[k++] = p.A[i++];
        }
        else if (p.A[i] == q.A[j])
        {
            r.A[k++] = p.A[i++];
            j++;
        }
    }

    for (; i < p.length; i++)
    {
        r.A[k++] = p.A[i];
    }
    for (; j < q.length; j++)
    {
        r.A[k++] = q.A[j];
    }

    for (k = 0; k < r.length; k++)
    {
        cout << r.A[k] << " ";
    }
}

int main()
{
    struct array p;
    cout << "Enter the size and length of the array" << endl;
    cin >> p.size >> p.length;
    p.A = new int[p.size];
    cout << "Enter " << p.length << " elements of the array" << endl;
    for (int i = 0; i < p.length; i++)
    {
        cin >> p.A[i];
    }
    struct array q;
    cout << "Enter the size and length of the array" << endl;
    cin >> q.size >> q.length;
    q.A = new int[q.size];
    cout << "Enter " << q.length << " elements of the array" << endl;
    for (int i = 0; i < q.length; i++)
    {
        cin >> q.A[i];
    }
    mergingofarrays(p,q);
}
