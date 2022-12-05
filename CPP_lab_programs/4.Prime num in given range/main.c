#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sr,er,i,j,c,flag;
    printf("Enter the starting and ending range:\n");
    scanf("%d %d",&sr,&er);

    printf("The prime numbers are:\n");
    for(i=sr;i<=er;i++)
    {
        if(i==1)
        continue;
        flag=0;
        for(j=2;j<=(i/2);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            c++;
            printf("%d\t",i);
        }

    }
    if(c==0)
    {
        printf(" NULL \n There is no prime numbers within range\n");
    }
    else
    {
        printf("There are %d prime numbers within given range\n",c);
    }
    return 0;
}
