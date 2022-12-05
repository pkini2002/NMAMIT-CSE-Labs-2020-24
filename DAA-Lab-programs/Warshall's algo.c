#include <stdio.h>
#include <stdlib.h>

int A[25][25];

void Warshall(int n){
  int i,j,k;
  for(k=1;k<=n;k++){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            A[i][j]=A[i][j] || (A[i][k]&&A[k][j]);
        }
    }
  }
}

int main()
{
    int i,j,v,e,v1,v2;
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    printf("Enter the number of edges: \n");
    scanf("%d",&e);

    printf("Enter %d edges\n",e);
    for(i=1;i<=e;i++){
        printf("Edge %d\n",i);
        scanf("%d %d",&v1,&v2);
        A[v1][v2]=1;
    }
    printf("Adjacency matrix is: \n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    Warshall(v);
    printf("The transitive closure is: \n");
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
