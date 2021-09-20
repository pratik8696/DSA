#include <bits/stdc++.h>
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
    cout << "O/P:--"
         << "   ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl
         << "The length of the array is " << arr.length << endl;
}
// basic array operations
// int geta(struct array a, int index)
// {
//     return a.A[index];
// }
// // set
// int seta(struct array *a, int index, int x)
// {
//     a->A[index] = x;
// }
// // max
// int max(struct array a)
// {
//     int temp = INT_MIN;
//     for (int i = 0; i < a.length; i++)
//     {
//         if (temp < a.A[i])
//         {
//             temp = a.A[i];
//         }
//     }
//     return temp;
// }
// // min
// int min(struct array a)
// {
//     int temp=INT_MAX;
//     for (int i = 0; i < a.length; i++)
//     {
//         if (temp>a.A[i])
//         temp=a.A[i];
//     }
//     return temp;
// }
// // sum
// int sum(struct array a)
// {
//     int summation=0;
//     for (int i = 0; i < a.length; i++)
//     {
//         summation=summation+a.A[i];
//     }
//     return summation;
// }
// int avg(struct array a)
// {
//     int average=sum(struct array a);
//     average=average/a.length;
//     return average;
// }
// Reversing an array
int Reverse_using2iterators(struct array *a)
{
    cout << "The array after reversing is = " << endl;
    for (int i = 0, j = (a->length) - 1; i < j; i++, j--)
    {
        Swap(&a->A[i], &a->A[j]);
    }
}
// Shifting or rotating an array
int Shifting(struct array *a, bool s, int count)
{
    // true for left shift
    if (s)
    {
        cout << "The array after " << count << " left shift  is  " << endl;
        for (int i = 0; i < count; i++)
        {
            int temp = a->A[0];
            for (int i = 0; i < (a->length) - 1; i++)
            {
                a->A[i] = a->A[i + 1];
            }
            a->A[(a->length)-1] = temp;
        }
    }
    // false for right shift
    else
    {
        cout << "The array after " << count << " right shift  is  " << endl;
        for (int i = 0; i < count; i++)
        {
            int temp = a->A[a->length-1];
            for (int i = (a->length) - 1; i > 0; i--)
            {
                a->A[i] = a->A[i - 1];
            }
            a->A[0] = temp;
        }
    }
}
// Checking whether an array is sorted or not
bool ifsorted(struct array a)
{
    for (int i = 0; i < (a.length) - 1; i++)
    {
        if (a.A[i] > a.A[i + 1])
        {
            return false;
        }
    }
    return true;
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
    Display(p);
    if (ifsorted(p))
        cout << "The entered array is sorted" << endl;
    else
        cout << "The array is unsorted" << endl;
    Reverse_using2iterators(&p);
    Display(p);
    Shifting(&p, true, 3);
    Display(p);
    // cout<<geta(p,4)<<endl;
    // seta(&p,4,10);
    // Display(p);
    // cout<<max(p)<<endl;
    // cout<<min(p)<<endl;
    // cout<<sum(p)<<endl;
    // cout<<avg(p)<<endl;
}