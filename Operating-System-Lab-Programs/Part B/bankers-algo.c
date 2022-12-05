#include <stdio.h>
#include <stdlib.h>

int main()
{
int p,r,i,j,k,found=0,count=0;
printf("Enter number of processes:\n");
scanf("%d",&p);
printf("Enter number of resources:\n");
scanf("%d",&r);
int alloc[p][r],max[p][r],avail[r],need[p][r],safeseq[p],finish[p];
printf("\nEnter the allocation matrix:\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
printf("\nEnter the max matrix:\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
printf("\nEnter the availble matrix:\n");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
printf("\nNeed Matrix :\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d\t",need[i][j]);
printf("\n");
}
for(i=0;i<p;i++)
finish[i]=0;
while(count<p)
{
found=0; //Assume !(need<=available) for all processes
for(i=0;i<p;i++)
{
if(finish[i]==0) //Didn't completed
{
for(j=0;j<r;j++)
{
if(need[i][j]>avail[j])
break;
}
if(j==r) //need<available
{
for(k=0;k<r;k++)
avail[k]=avail[k]+alloc[i][k];
safeseq[count++]=i;
found=1; //need<available found
finish[i]=1; //Mark process as finished
}
}
}
if(found==0) //No process can be allocated.
{
printf("System is in unsafe state.\n");
return 0;
}
}
printf("System is in safe state.\n");
printf("Safe Sequence is : ");
for(k=0;k<p;k++)
printf("P%d\t",safeseq[k]+1);
printf("\n");
return 0;
}
