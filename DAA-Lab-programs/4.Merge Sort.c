#include <stdio.h>
#include <stdlib.h>

void merge(int b[],int p,int c[],int q,int a[])
{
    int i=0;
    int j=0;
    int k=0;
    int n=p+q;
    while(j!=p && k!=q)
    {
        if(b[j] < c[k])
        {
            a[i]=b[j];
            j++;
        }
        else{
            a[i]=c[k];
            k++;
        }
        i++;
    }
    if(j==p)
    {
        for(i;i<n;i++)
        {
            a[i]=c[k];
            k++;
        }
    }
    else{
        for(i;i<n;i++)
        {
            a[i]=b[j];
            j++;
        }
    }
}

void merge_sort(int a[],int n)
{
    if(n==1)
        return;
    int m=n/2;
    int l=n-(n/2);
    int b[m],c[l];

    for(int i=0;i<m;i++)
    {
        b[i]=a[i];
    }
    for(int i=0;i<l;i++)
    {
        c[i]=a[m+i];
    }
    merge_sort(b,m);
    merge_sort(c,l);
    merge(b,m,c,l,a);
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
    merge_sort(a,n);
    printf("The array elements after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
