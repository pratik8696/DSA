#include <stdio.h>
#include <conio.h>

void mM(int a[], int q)
{
    int m, M, i;
    m = M = a[0];
    for (i = 1; i < q; i++)
    {
        if (m > a[i])
            m = a[i];
        if (M < a[i])
            M = a[i];
    }
    printf("Maximum of array is : %d", M);
    printf("\nMinimum of array is : %d", m);
}

int main()
{
    int a[100], i, sum;
    int q = 10;
    printf("Enter elements in array of size 10 : \n");
    for (i = 0; i < q; i++)
    {
        scanf("%d", &a[i]);
    }
    mM(a, q);
    return 0;
}
