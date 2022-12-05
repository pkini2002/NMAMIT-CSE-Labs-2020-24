#include <stdio.h>
#include <stdlib.h>

int visited[20],mat[20][20];
int count=0;
int v,e;
int queue[20],front=0,rear=-1;

void bfs(int w){
count++;
visited[w]=count;
rear++;
queue[rear]=w;

while(front<=rear){
    printf("%d(%d) ",queue[front],visited[queue[front]]);
    for(int i=1;i<=v;i++){
         if(visited[i]==0 && mat[queue[front]][i]==1){
            count++;
            visited[i]=count;
            rear++;
            queue[rear]=i;
        }
    }
    front++;
}

}

void BFS(){
for(int i=1;i<=v;i++){
    if(visited[i]==0)
        bfs(i);
}
}

int main()
{
    int v1,v2,ch;
    printf("Enter your choice\n1.Undirected edge\n2.Directed edge\n");
    scanf("%d",&ch);

    if(ch!=1 && ch!=2){
        printf("Invalid choice!\n");
        return 0;
    }

    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    printf("Enter the number of edges: \n");
    scanf("%d",&e);

    printf("Enter the %d edges\n",e);
    for(int i=1;i<=e;i++){
        printf("Edge %d: ",i);
        scanf("%d %d",&v1,&v2);

        if(ch==1)
            mat[v1][v2]=mat[v2][v1]=1;
        else
            mat[v1][v2]=1;
    }
    printf("The order of vertices is processed!\n");
    BFS();
    return 0;
}
