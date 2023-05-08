// Leaky bucket

#include<stdio.h>
#include<stdlib.h>

#define OUTRATE 25
#define BUCKET_SIZE 250

struct{
    int arrtime;
    int weight;
}packet[15];

void readpackets(int n){
    for(int i=0;i<n;i++){
        printf("Enter the arrival time: \n");
        scanf("%d",&packet[i].arrtime);
        printf("Enter the weight: \n");
        scanf("%d",&packet[i].weight);
    }
}

void leaky_bucket(){
    int i,j=0,rem=0;
    int excess=BUCKET_SIZE;

    for(i=0;i<=30;i++){
        if(packet[j].arrtime==i){
            if(packet[j].weight <= excess){
                rem+=packet[j].weight;
                excess-=packet[j].weight;
                printf("At time %d %d is inserted into the bucket\n",i,j+1);
                printf("Remaining bucket size is %d\n",excess);
                j=j+1;
            }
            else{
                printf("At time %d the packet %d is discarded\n",i,j+1);
                printf("Packet size is more than buffer size\n");
                j+=1;
            }
        }

        // send packet every 5 millisec
        if((i%5==0)){
            if(rem>=OUTRATE){
                rem-=OUTRATE;
                excess+=OUTRATE;
                printf("At time %d 25KBytes are transferred\n",i);
            }
            else if(rem > 0){
                excess+=rem;
                printf("At time %d , %d KBytes are transferred\n",i,rem);
                printf("The free space available in the bucket is %d\n",excess);
                rem=0;
            }
        }

    }

      while(rem!=0){
            if(rem<OUTRATE){
                excess+=rem;
                printf("At time %d , %d KBytes are transferred\n",i++,rem);
                printf("The free space available in the bucket is %d\n",excess);
                break;
            }
             rem-=OUTRATE;
             excess+=OUTRATE;
             printf("At time %d , %d KBytes are transferred\n",i++,OUTRATE);
              printf("The free space available in the bucket is %d\n",excess);
    }
    printf("The bucket is empty\n");
}

int main(){
   int n;
   printf("Enter the number of packets: \n");
   scanf("%d",&n);
   readpackets(n);
   leaky_bucket();
   return 0;
}
