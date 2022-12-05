#include <stdio.h>
#include <stdlib.h>

int count=0;
int visited[20]={0},queue[20],front=0,rear=-1;

void bfs(int mat[20][20],int v,int i)
{
    count++;
    visited[i]=count;
    queue[++rear]=i;
    while(front<=rear)
    {
        for(int w=0;w<v;w++)
        {
            if(mat[queue[front]][w]==1)
            {
                if(visited[w]==0)
                {
                    count++;
                    visited[w]=count;
                    queue[++rear]=w;
                }
            }
        }
        int a=queue[front++];
        printf("%d(%d)",a+1,visited[a]);
    }
}

void BFS(int mat[20][20],int v,int e)
{
    count=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
            bfs(mat,v,i);
    }
}

int main()
{
    int v,e,ch;
    int mat[20][20];
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    printf("Enter the number of edges edges: ");
    scanf("%d",&e);
    printf("1.Undirected\n2.Directed\n");
    scanf("%d",&ch);
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        printf("Edge %d: ",i);
        scanf("%d %d",&v1,&v2);
        v1--;
        v2--;

        if(ch==1)
        {
            mat[v1][v2]=mat[v2][v1]=1;
        }
        else{
            mat[v1][v2]=1;
        }
    }
    BFS(mat,v,e);
    return 0;
}
