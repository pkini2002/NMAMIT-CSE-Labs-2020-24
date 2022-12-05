#include<stdio.h>
int main()
{
  int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
  float avg_wt,avg_tat;
   printf("\nEnter number of process:");
   scanf("%d",&n);

   printf("\nEnter Burst Time:");
  for(i=0;i<n;i++)
  {
     printf("p%d:",i+1);
     scanf("%d",&bt[i]);p[i]=i+1;
  }

//sorting of burst times
  for(i=0;i<n;i++)
  {
    pos=i;
    for(j=i+1;j<n;j++)
    {
       if(bt[j]<bt[pos])
        pos=j;
     }
  temp=bt[i];
  bt[i]=bt[pos];
  bt[pos]=temp;

  temp=p[i];
  p[i]=p[pos];
  p[pos]=temp;
}

wt[0]=0;

for(i=1;i<n;i++)
{
   wt[i]=0;
   for(j=0;j<i;j++)
     wt[i]+=bt[j];

total+=wt[i];
}

avg_wt=(float)total/n;
total=0;

printf("\nProcess\t BurstTime \tWaitingTime\tTurnaround Time\n");
for(i=0;i<n;i++)
{
 tat[i]=bt[i]+wt[i];
 total+=tat[i];
printf("\n p%d\t\t%d \t \t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}

avg_tat=(float)total/n;
printf("\n\nAverage Waiting Time=%f",avg_wt);
printf("\n Average Turnaround Time=%f\n",avg_tat);
return 0;
}

/*

Output:

Enter number of process:4

Enter Burst Time:p1:6
p2:8
p3:7
p4:3

Process  BurstTime      WaitingTime     Turnaround Time

 p4             3                0                      3
 p1             6                3                      9
 p3             7                9                      16
 p2             8                16                     24

Average Waiting Time=7.000000
 Average Turnaround Time=13.000000

*/
