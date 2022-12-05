#include <stdio.h>
#include <stdlib.h>
void read(int x[10][10],int r,int c);
void display(int x[10][10],int row,int col);
void multiply(int a[10][10],int b[10][10],int c[10][10],int r, int col, int p);

int main()
{
    int a[10][10],b[10][10],c[10][10],m,n,p,q,i,j,k;

    printf("Enter the order of matrix A\n");
    scanf("%d %d",&m,&n);
    printf("Enter the order of matrix B\n");
    scanf("%d %d",&p,&q);

    if(n!=p)
    {
        printf("not possible\n");
        exit(0);
    }
    printf("Enter the matrix A\n");
    read(a,m,n);
    printf("Enter the matrix B\n");
    read(b,p,q);
    printf("Entered matrix A is\n");
    display(a,m,n);
    printf("Entered matrix B is\n");
    display(b,p,q);
    multiply(a,b,c,m,n,q);
    printf("The resultant matrix is\n");
    display(c,m,q);
    return 0;
}

void read(int x[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d",&x[i][j]);
}
void display(int x[10][10],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }
}
void multiply(int a[10][10],int b[10][10],int c[10][10],int m,int n,int q)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
}
