#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],n,i,sum=0;

    int*p;
    printf("Enter the value of n\n");
    scanf("%d",&n);

    printf("Enter the numbers\n");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);

      p=a;
      for(i=0;i<n;i++)
      {
          sum=sum+*p;
          p=p+1;
      }
      printf("\n The sum is %d\n",sum);
      return 0;
}
