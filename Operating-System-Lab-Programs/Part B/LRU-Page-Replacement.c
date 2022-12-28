#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,f,free,pf=0,time=0,pos=0,index,min,found;
    printf("Enter the number of pages: \n");
    scanf("%d",&n);
    printf("Enter the number of page frames: \n");
    scanf("%d",&f);
    free=f;

    int count[f],frame[f];

    for(int i=0;i<f;i++){
        frame[i]=-1;
        count[i]=0;
    }

    int ref[n];// reference string
    printf("Enter the reference string: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&ref[i]);
    }

    for(int i=0;i<n;i++){
        found=0;
        for(int j=0;j<f;j++){
            if(frame[j]==ref[i]){
                count[j]=time;
                found=1;
                break;
            }
        }
        if(!found){
            if(free){
                frame[pos]=ref[i];
                pf++;
                free--;
                count[pos]=time;
                pos++;
            }
            else{
                min=count[0];
                index=0;
                for(int j=1;j<f;j++){
                    if(count[j]<min){
                        min=count[j];
                        index=j;
                    }
                }
               frame[index]=ref[i];
               count[index]=time;
               pf++;
            }
        }
        time++;
        printf("%d --> ",ref[i]);
        for(int j=0;j<f;j++){
            printf("%d ",frame[j]);
        }

        if(found==0){
            printf("\nPage Hit\n");
        }
        else{
            printf("\nPage Miss\n");
        }
    }
    printf("Total number of page faults is %d\n",pf);
    return 0;
}
