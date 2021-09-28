#include <stdio.h>
int main()
{
    int l = 10;
    int a[l];
    printf("Enter the Elements of the array:\n");
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &a[i]);
    }
    int s = 0;
    int t = 0;
    for (int i = 0; i < l; i++)
    {
        t = (a[i] % 100) / 10;
        if (t % 5 == 0)
            s += a[i];
    }
    printf("Required Sum: %d\n", s);
    return 0;
}
