#include <stdio.h>
#include <stdlib.h>

int weight[25],value[25],V[25][25];

int max(int a,int b){
if(a>b)
    return a;
else
    return b;
}

int MFK(int i,int j){
if(i>=0 && j>=0){
    int val;
    if(V[i][j]<0){
        if(j<weight[i])
            val=MFK(i-1,j);
        else
            val=max(MFK(i-1,j),value[i]+MFK(i-1,j-weight[i]));
        V[i][j]=val;
  }
}
return V[i][j];
}

int main()
{
    int n,w,solution,x,y;
    printf("Enter the number of items to be filled in the knapsack: \n");
    scanf("%d",&n);
    printf("Enter the knapsack capacity: \n");
    scanf("%d",&w);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0)
                V[i][j]=0;
            else
                V[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("Item %d\n",i);
        scanf("%d %d",&x,&y);
        weight[i]=x;
        value[i]=y;
    }
    solution=MFK(n,w);
    printf("The optimal solution is %d\n",solution);
    return 0;
}
