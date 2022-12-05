#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int l,int h)
{
    int p=a[l];
    int i=l;
    int j=h;
    while(i<=j)
    {
        while(i>=l && a[i]<=p)
        {
            i++;
        }
        while(a[j]>p && j<=h)
        {
            j--;
        }
        int temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
     int temp;
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;

     int m;
     m=a[l];
     a[l]=a[j];
     a[j]=m;
     return j;
}

void divide(int a[],int l,int h)
{
    if(l<h)
    {
        int m=partition(a,l,h);
        divide(a,l,m-1);
        divide(a,m+1,h);
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
    divide(a,0,n-1);
    printf("The elements after sorting is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
