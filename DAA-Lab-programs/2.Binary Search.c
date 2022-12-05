#include <stdio.h>
#include <stdlib.h>

int binsearch(int a[],int key,int n)
{
    int l=0;
    int r=n-1;
    int m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(key==a[m])
            return m;
        else
            if(key < a[m])
            {
              r=m-1;
            }
            else{
              l=m+1;
            }
    }
    return -1;
}

int main()
{
    int n,key;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int a[n],i;
    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key element to be searched:\n");
    scanf("%d",&key);
    int res;
    res=binsearch(a,key,n);
    if(res==-1)
    {
        printf("The key element is not found\n");
    }
    else
        printf("The key element is found at position %d\n",res+1);
    return 0;
}
