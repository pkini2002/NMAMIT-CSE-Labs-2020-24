#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],mid,l,h,n,key,i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the key element to be searched:\n");
    scanf("%d",&key);
    l=0;
    h=n-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==key)
        {
            printf("The key if found at the position %d\n",mid+1);
            exit(0);
        }
        if(key>a[mid])
            l=mid+1;
        else
            h=mid-1;

    }
    printf("The key element is not found\n");
    return 0;
}
