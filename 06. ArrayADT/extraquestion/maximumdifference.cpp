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
// Binary Search
int binarysearch(struct array a, int key)
{
    int l = 0, h = a.length, mid;
    mid = (l + h) / 2;
    while (l <= h)
    {
        if (a.A[mid] == key)
        {
            return mid;
        }
        else if (a.A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}

int leader(struct array a)
{
    cout<<"This fn was initiated"<<endl;
    int flag=1;
    for (int i = 0; i < a.length-1; i++)
    {
        for (int j = i+1 ; j < a.length; j++)
        {
            if (a.A[i]<=a.A[j])
            {
               flag=0;
               break; 
            }
            
        }
        if (flag==1)
        {
            cout<<a.A[i]<<" ";
            flag=1;
        }
    }
}

int leaderoptimised(struct array a)
{
    int curr_leader=a.A[a.length-1];
    int array_of_leaders[100];
    array_of_leaders[0]=curr_leader;
    int count=0;
    // cout<<curr_leader<<" ";
    for (int i = a.length-2; i >=0 ; i--)
    {
        if (a.A[i]>curr_leader)
        {
            curr_leader=a.A[i];
            // cout<<curr_leader<<" ";
            count++;
            array_of_leaders[count]=curr_leader;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout<<array_of_leaders[i]<<" ";
    }
    
}

int maxdifference(struct array a)
{
    int maxdiff=0;
    for(int i=0;i<a.length-1;i++)
    {
        for(int j=i+1;j<a.length;j++)
        {
            int diff=a.A[j]-a.A[i];
            maxdiff=max(maxdiff,diff);
        }
    }
    return maxdiff;
}

int maxdiffoptimised(struct array a)
{
    int curr_min=a.A[0];
    int maxdiff=a.A[1]-a.A[0];
    for(int i=2;i<a.length;i++)
    {
        curr_min=min(curr_min,a.A[i]);
        int curr_diff=a.A[i]-curr_min;
        maxdiff=max(curr_diff,maxdiff);
    }
    return maxdiff;
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
    cout<<maxdifference(p)<<" "<<maxdiffoptimised(p);
}