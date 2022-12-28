#include <stdio.h>
#include <stdlib.h>

int n,f;

int optimal(int ref[],int frame[],int optindex[],int index){
    int max,pos,found;
    for(int i=0;i<f;i++){
        found=0;
        for(int j=index+1;j<n;j++){
            if(frame[i]==ref[j]){
                found=1;
                optindex[i]=j;
                break;
            }
        }
        if(!found)
            return i;
    }
    max=optindex[0];
    pos=0;

    for(int i=1;i<f;i++){
        if(max<optindex[i]){
            max=optindex[i];
            pos=i;
        }
    }
    return pos;
}

int main()
{
    int pf=0,victim=-1,count=0;
    printf("Enter the number of pages: \n");
    scanf("%d",&n);
    int ref[n];

    printf("Enter the number of frames: \n");
    scanf("%d",&f);

    printf("Enter the reference string:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ref[i]);
    }

    int frame[f],optindex[f];

    for(int i=0;i<f;i++){
        frame[i]=-1;
        optindex[i]=-1;
    }

    int found;
    for(int i=0;i<n;i++){
        found=0;
        for(int j=0;j<f;j++){
            if(ref[i]==frame[j]){
                found=1;
                break;
            }
        }
        if(!found){
            count++;
            if(count<=f)
                victim++;
            else
                victim=optimal(ref,frame,optindex,i);
            pf++;
            frame[victim]=ref[i];
        }

        printf("%d ",ref[i]);
        for(int j=0;j<f;j++){
            printf("%d ",ref[j]);
        }

        if(found==0){
            printf("\nPage Hit\n");
        }
        else{
            printf("\nPage Miss\n");
        }
    }
    printf("Total number of page frames: %d\n",pf);
    return 0;
}
