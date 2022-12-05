#include <stdio.h>
#include <stdlib.h>

int v,e,adjMat[20][20],VT[20],V_VT[20],edges[25][3],inc=0;

void initialize() //Initializes Vt and V-Vt
{
 int i;
 for(i=1; i<=v; i++)
 {
 VT[i]=0; //Vt is null initially
 V_VT[i]=1; //V-Vt is V
 }
 VT[1]=1; // Initialize VT with vertex-1
 V_VT[1]=0;
}

void prims()
{ int i,j,k,v1,v2,min;
 initialize();
 for(i=1; i<v; i++) //<v because one vertex is already selected
 {
 min=9999;
 for(j=1; j<=v; j++) //To find minimum weight edge
 for(k=1; k<=v; k++)
 if(VT[j]!=0 && V_VT[k]!=0 && adjMat[j][k]<min)
 {
 min=adjMat[j][k];
 v1=j;
 v2=k;
 }
 edges[inc][0]=v1; //Store end vertices of minimum weight edge in a 2-D array
 edges[inc][1]=v2;
 edges[inc][2]=min; //Store minimum weight along with the end vertices
 inc++;
 VT[v2]=1;
 V_VT[v2]=0;
 }
}

int main()
{
 int i,j,v1,v2,w,total=0;
 printf("Enter the number of vertices : ");
 scanf("%d",&v);
 printf("Enter the number of edges : ");
 scanf("%d",&e);
 printf("Enter %d edges :\n",e);
 for(i=1; i<=v; i++)
 for(j=1; j<=v; j++)
 if(i==j)
 adjMat[i][j]=0; //from vertex to itself
 else
 adjMat[i][j]=9999; //No direct edge
 for(i=1; i<=e; i++)
 {
 printf("Edge-%d : ",i);
 scanf("%d%d",&v1,&v2);
 printf("Enter the weight of edge %d %d : ",v1,v2);
 scanf("%d",&w);
 adjMat[v1][v2]=adjMat[v2][v1]=w;
 }
 prims();
 printf("\nEdges in minimum spanning tree :\n");
 for(i=0; i<inc; i++)
 {
 v1=edges[i][0];
 v2=edges[i][1];
 total+=edges[i][2];
 printf("%d --> %d (Weight:%d)\n",v1,v2,adjMat[v1][v2]);
 }
 printf("\nSum of edge weight in minimum spanning tree : %d",total);
 return 0;
}
