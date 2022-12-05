#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10],b[10][10],i,j,n,m,trace=0;
    printf("\n Enter the size of the matrix\n");
    scanf("%d %d",&m,&n);
    printf("\n Enter %d * %d matrix\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n The entered matrix is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    //Transpose
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
        }
        printf("\n Transpose of a matrix\n");
        for(i=0;i<n;i++)//row
        {
            for(j=0;j<m;j++)
            {
                printf("%d\t",b[i][j]);
            }
            printf("\n");
        }
        //Trace
        if(m==n)
        {
            //Find trace
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==j)
                        trace=trace+b[i][j];
                }
            }
            printf("\n The trace is :%d",trace);
        }
        else
            {
            printf("\n Cannot find trace since entered matrix is not a square matrix\n");
        }
    return 0;
}
