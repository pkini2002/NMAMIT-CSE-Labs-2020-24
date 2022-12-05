#include <stdio.h>
#include <stdlib.h>

void ins_sort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]<temp)
            {
                break;
            }
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

int main()
{
    int n,a[50];
    printf("Enter the value of n: \n");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ins_sort(a,n);
    printf("Sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
