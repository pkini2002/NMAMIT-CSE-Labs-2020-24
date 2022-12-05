#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[],int n)
{
    int temp;
    for(int i=0;i<=n-2;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(a[j+1]<=a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubblesort(a,n);
    printf("The elements after sorting is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
