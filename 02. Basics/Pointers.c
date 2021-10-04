#include <stdio.h>

int byaddress(int *a,int *b)
{
    *a;
    *b++;
    printf("%d %d\n", *a, *b);
}

int main()
{
    int a = 81;
    int b=9;
    byaddress(&a,&b);
    printf("%d %d",a,b);
    return 0;
}