#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50],n,temp,i,j,pos;
    printf("Enter the values for n\n");
    scanf("%d",&n);
    printf("Enter the numbers\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The entered values are\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos])
                pos=j;
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    printf("\n The sorted values are \n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}
