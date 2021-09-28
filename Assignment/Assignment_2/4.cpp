#include <stdio.h>

int main(int ac, char const *av[])
{
    printf("ENTER ELEMENTS OF 1st MATRIX : \n");
    int a1[2][2];
    int a2[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    printf("ENTER ELEMENTS OF 2nd MATRIX : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }

    int mult[2][2];
    printf("sum of matrices: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a1[i][j] + a2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("difference of matrices: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", a1[i][j] - a2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mult[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                mult[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    printf("Multiplication of matrices : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
