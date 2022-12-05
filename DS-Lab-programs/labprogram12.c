#include <stdio.h>
#include <stdlib.h>

void tower(int n,char sp,char dp,char ap);

int main()
{
   int n;
   printf("Enter the number of disks:\n");
   scanf("%d",&n);
   printf("The disk movements are:\n");
   tower(n,'A','C','B');
   return 0;
}

void tower(int n,char sp,char dp,char ap)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,sp,dp);
        return;
    }
    tower(n-1,sp,ap,dp);
    printf("Move disk %d from %c to %c\n",n,sp,dp);
    tower(n-1,ap,dp,sp);
    return;
}


