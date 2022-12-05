#include <stdio.h>
#include <stdlib.h>

void selectionsort(int a[],int n)
{
    int i,min,j;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int n,i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    printf("The elements after sorting is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
