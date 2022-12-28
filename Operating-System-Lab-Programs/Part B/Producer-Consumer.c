#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,j;
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    printf("Enter the number of resources: \n");
    scanf("%d",&m);

    int max[n][m],need[n][m],alloc[n][m],avail[m];
    printf("Enter the allocation matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the max matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    //need matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    //avail matrix
    printf("Enter the available matrix: \n");
    for(int i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }

    int safeseq[n],finish[n],found=0,count=0;

    for(int i=0;i<n;i++)
        finish[i]=0;

    while(count<n){
        found=0;
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                for(j=0;j<m;j++){
                    if(need[i][j] > avail[j]){
                        break;
                    }
                }
                if(j==m){
                    for(int k=0;k<m;k++){
                        avail[k]=avail[k]+alloc[i][k];
                    }
                    safeseq[count++]=i;
                    found=1;
                    finish[i]=1;
                }
            }
        }

        if(found==0){
            printf("System is in unsafe state!\n");
            return 0;
        }
    }

    printf("System is in safe state\n");
    printf("Safe sequence is: ");
    for(int i=0;i<n;i++){
        printf("%d",safeseq[i]+1);
    }

    return 0;
}
