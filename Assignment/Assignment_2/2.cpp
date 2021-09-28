#include <stdio.h>
#include <stdlib.h>
void ins(int a[], int n, int d, int ind);
void del(int a[], int n, int ind2);
int main()
{
    int a[100], n, i, d, ind1, ind2;
    printf("enter the size of an array\n");
    scanf("%d", &n);
    printf("enter %d elements in an array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the data you want to insert:\n");
    scanf("%d", &d);
    printf("enter the index position where you want to insert:\n");
    scanf("%d", &ind1);
    ins(a, n, d, ind1);
    printf("enter the index of an elements which you want to delete:\n");
    scanf("%d", &ind2);
    del(a, n, ind2);

    return 0;
}
void ins(int a[], int n, int d, int ind)
{
    int i, temp = a[ind];
    for (i = n; i > ind; i--)
    {
        a[i] = a[i - 1];
    }
    a[ind] = d;
    n += 1;
    printf("your new array after insertion is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void del(int a[], int n, int index)
{
    int i;
    for (i = index; i < n; i++)
        a[i] = a[i + 1];
    printf("your new array after deletion is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
