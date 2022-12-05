#include <stdio.h>
#include <stdlib.h>

int v,e,inserted[20],total=0;

struct node
{
 int v1,v2,w;
 struct node * link;
};

typedef struct node * NODE;

NODE addGraphEdge(NODE graph,int v1,int v2,int w) //Store graph edges in linked list graph
{
 NODE temp=(NODE)malloc(sizeof(struct node)); //Create new node
 temp->v1=v1;
 temp->v2=v2;
 temp->w=w;
 if(graph == NULL) //If linked list is empty
 {
 graph=temp;
 graph->link=NULL;
 }
 else
 {
 NODE cur= graph;
 NODE prev=NULL;
 while(cur!=NULL && temp->w > cur->w) //Insertion sort
 {
 prev=cur;
 cur=cur->link;
 }
 if(prev==NULL)
 {
 graph=temp;
 temp->link=cur;
 }
 else
 {
 prev->link=temp;
 temp->link=cur;
 }
 }
 return graph;
}

NODE addTreeEdge(NODE tree,int v1,int v2,int w) //Adds tree edges to minimum spanning tree
{
 NODE temp=(NODE)malloc(sizeof(struct node));
 temp->v1=v1;
 temp->v2=v2;
 temp->w=w;
 temp->link=NULL;
 if(tree == NULL)
 tree=temp;
 else
 {
 NODE cur=tree;
 while(cur->link!=NULL)
 cur=cur->link;
 cur->link=temp;
 }
 return tree;
}

NODE Kruskal(NODE graph,NODE tree)
{
 int Vcount=0,Ecount=0,c=0;
 NODE cur=graph;
 while(cur!=NULL)
 {
 if(inserted[cur->v1]==0) //Count vertices in tree after adding an edge
 {
 c++;
 inserted[cur->v1]=1; //mark added vertex as inserted
 }
 if(inserted[cur->v2]==0) //Count second vertex vertex
 {
 c++;
 inserted[cur->v2]=1;
 }
 Ecount++; //One edge need to be added to tree
 if(Ecount>=(Vcount+c)) //Cheek for cycle. If in any case of undirected graph, edgs>= vertices, there is cycle
 {
 Ecount--; //Adding edge will result in cycle
 }
 else
 {
 Vcount=Vcount+c;
 tree=addTreeEdge(tree,cur->v1,cur->v2,cur->w);
 total+=cur->w;
 }
 c=0;
 cur=cur->link;
 }
 return tree;
}

int main()
{
 int i,v1,v2,w;
 NODE graph=NULL, tree=NULL;
 printf("Enter the number of vertices : ");
 scanf("%d",&v);
 printf("Enter the number of edges : ");
 scanf("%d",&e);
 printf("Enter %d edges :\n",e);
 for(i=1; i<=e; i++)
 {
 printf("Edge-%d : ",i);
 scanf("%d%d",&v1,&v2);
 printf("Enter the weight of edge %d %d : ",v1,v2);
 scanf("%d",&w);
 graph=addGraphEdge(graph,v1,v2,w);
 }
 tree=Kruskal(graph,tree);
 printf("\nEdges in minimum spanning tree :\n");
 NODE cur=tree;
 while(cur!=NULL)
 {
 printf("%d --> %d (Weight:%d)\n",cur->v1,cur->v2,cur->w);
 cur=cur->link;
 }
 printf("\nSum of edge weight in minimum spanning tree : %d",total);
 return 0;
}

