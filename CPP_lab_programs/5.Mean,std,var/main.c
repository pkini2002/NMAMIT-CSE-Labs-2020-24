#include <stdio.h>
#include<math.h>

int main()
{
    float a[10],sum=0,sumv=0,mean,var,std;
    int i,n;
    printf("Enter the number:\n");
    scanf("%d",&n);
    printf("Enter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
        sum=sum+a[i];
    }
    mean=sum/n;
    for(i=0;i<n;i++)
    {
    sumv=sumv+pow(a[i]-mean,2);
    }
    printf("sumv=%f\n",sumv);
    var=sumv/n;
    std=sqrt(var);
    printf("\n The mean=%f\n the variance=%f\n standard deviation=%f\n",mean,var,std);
    return 0;
}
