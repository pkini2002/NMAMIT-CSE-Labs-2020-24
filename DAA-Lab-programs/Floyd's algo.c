#include <stdio.h>
#include <stdlib.h>

int W[25][25];

int min(int a,int b){
if(a<b)
    return a;
else
    return b;
}

void Floyds(int n){
  int i,j,k;
  for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
        }
    }
  }
}

int main()
{
    int i,j,v1,v2,v,e,w;
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    printf("Enter the number of edges: \n");
    scanf("%d",&e);

    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            if(i==j)
                W[i][j]=0;
            else
                W[i][j]=999;
        }
    }

    printf("Enter the %d edges: \n",e);
    for(i=1;i<=e;i++){
            printf("Edge %d",i);
            printf("\n");
            scanf("%d %d ",&v1,&v2);
            printf("\nEnter the weight: %d--->%d\n",v1,v2);
            scanf("%d",&w);
            W[v1][v2]=w;
        }

    printf("Weight matrix is: \n");
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

    Floyds(v);

    printf("Shortest distance matrix: \n");
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }
    return 0;
}
