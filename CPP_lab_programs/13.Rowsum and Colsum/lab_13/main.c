#include <stdio.h>
#include <stdlib.h>

int m,n,i,j,a[10][10];

void readmat();
void colsum();
void rowsum();
void totsum();
void printmat();

int main()
{
    printf("Enter the order of the matrix:\n");
    scanf("%d %d",&m,&n);
    printf("Enter %d*%d elements of the matrix:\n",m,n);
    readmat();
    printf("The entered matrix is:\n");
    printmat();

    rowsum();
    colsum();
    totsum();

    return 0;
}

void readmat()
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
}

void printmat()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void colsum()
{
    int sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum=sum+a[j][i];
        }
        printf("The sum of elements of column %d is %d\n",i+1,sum);
        sum=0;
    }
}

void rowsum()
{
    int sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=sum+a[i][j];
        }
        printf("The sum of elements of row %d is %d\n",i+1,sum);
        sum=0;
    }
}

void totsum()
{
    int sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=sum+a[i][j];
        }
    }
    printf("The sum of all elements of matrix is %d\n",sum);
}
