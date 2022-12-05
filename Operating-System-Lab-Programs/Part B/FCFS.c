/*  FCFS Scheduling algo to find avg waiting time and avg turn around time for a list of processes  */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct process{
   int bt,wt,tt,pno;
}p[10];

int main()
{
    int n,i;
    float totwt=0,tott=0,avg1,avg2;

    printf("Enter the number of process: \n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the bt of process %d",i+1);
        scanf("%d",&p[i].bt);
        p[i].pno=i+1;
    }p[0].wt=0;

    p[0].tt=p[0].bt+p[0].wt;
    for(i=1;i<n;i++){
        p[i].wt=p[i-1].tt;
        p[i].tt=p[i].wt+p[i].bt;
    }

    for(i=0;i<n;i++){
        totwt=totwt+p[i].wt;
        tott=tott+p[i].tt;
    }
    printf("Total waiting time: %f\n",totwt);
    printf("Total tt time: %f\n",tott);
    avg1=(totwt/n);

    printf("Avg wt is: %f\n",avg1);
    avg2=(tott/n);
    printf("Avg is %f\n",avg2);
    printf("Process\tbt\twt\ttt\n");

    for(i=0;i<n;i++){
        printf("p[%d]\t %d\t %d\t %d",(i+1),p[i].bt,p[i].wt,p[i].tt);
        printf("\n");
    }
    return 0;
}

// Output

/*
Enter the number of process:
3
Enter the bt of process 1 24
Enter the bt of process 2 3
Enter the bt of process 3 3
Total waiting time: 51.000000
Total tt time: 81.000000
Avg wt is: 17.000000
Avg is 27.000000
Process bt      wt      tt
p[1]     24      0       24
p[2]     3       24      27
p[3]     3       27      30

*/
