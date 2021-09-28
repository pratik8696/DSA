#include <stdio.h>

int main()
{
    int v;
    printf("Enter the order of square matrix\n");
    scanf("%d", &v);
    int a[v][v];
    int sum = 0, Sum = 0;
    int l = 0, m = v - 1;
    printf("Enter the elements of square matrix\n");

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                sum = sum + a[i][j];
        }
    }
    while (m >= 0 && l <= v - 1)
    {
        Sum = Sum + a[l][m];
        l++;
        m--;
    }

    printf(" sum of diagonal elements from left to right is %d\n", sum);

    printf(" sum of diagonal elements from right to left  is %d", Sum);
}
