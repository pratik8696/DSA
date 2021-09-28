#include <stdio.h>
int Lin(int a[], int key);
int binary(int l, int h, int a[], int key);
int main()
{
    int a[5], key;
    printf("Enter elements of araay in sorted manner\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("enter the number to be searched");
    scanf("%d", &key);
    if (Lin(a, key) != -1 || binary(0, 4, a, key) != -1)
    {
        printf("found at %d index by linear search\n", Lin(a, key));
        printf("found at %d index by binary search\n", binary(0, 4, a, key));
    }
    else
        printf("Not found\n");
    return 0;
}

int Lin(int a[], int key)
{

    for (int i = 0; i < 5; i++)
    {
        if (key == a[i])
            return i;
    }

    return -1;
}

int binary(int l, int h, int A[], int key)
{
    int mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else if (key > A[mid])
            l = mid + 1;
    }
    return -1;
}
