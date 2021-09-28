#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int k, l;
    for (k = 1; k <= n; k++)
    {
        for (l = 1; l <= n * 2 - k; l++)
        {
            if (k % 2 != 0)
            {
                if (l >= k && l <= 2 * n - k && l % 2 != 0)
                    printf("*");
                else
                    printf(" ");
            }
            else
            {
                if (l >= k && l <= 2 * n - k && l % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
