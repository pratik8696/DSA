#include <stdio.h>
#include <string.h>
#include <math.h>
int add(int a[10][10],int b[10][10],int m,int n)
{
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ",a[i][j]+b[i][j]);
        }
        printf("\n");
    }    
}
int main()
{
    int n,key,k=0;
    scanf("%d%d",&n,&key);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int s=0;
    int e=n-1;
    while (s<e)
    {
        int mid=(s+e)/2;
        if (a[mid]==key)
        {
            printf("Found");
            k=1;
        }
        if (a[mid]>key)
        {
            e=mid-1;
        }
        if (a[mid]<key)
        {
            s=mid+1;
        }
    }
    if (k==0)
    {
        printf("not found");
    }

}
