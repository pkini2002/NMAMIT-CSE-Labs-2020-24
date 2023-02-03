// Algorithm: 

/*
     1. Read a msg from the keyboard
     2. Divide the msg into fixed size packets (Include sequenceno and other info in each packet)
     3. Shuffle the packets
     4. Order the packets based on sequence number
     5. Display the ordered packets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SZ 3

typedef struct packet{
     int seqnum;
     char data[DATA_SZ+1];
}PACKET;

PACKET *readdata,*transdata;
time_t t;

int divide(char *msg){
   int msglen,NoOfPacket,i,j;
   msglen=strlen(msg);
   NoOfPacket=msglen/DATA_SZ;

   if((msglen%DATA_SZ)!=0)
           NoOfPacket++;

   readdata=(PACKET *)malloc(sizeof(PACKET) *NoOfPacket);

   for(i=0;i<NoOfPacket;i++){
     readdata[i].seqnum=i+1;
     for(j=0;(j<DATA_SZ)&& (*msg!='\0');j++,msg++)
        readdata[i].data[j]=*msg;
     readdata[i].data[j]='\0';
   }

   printf("The message has been divided as follows:\n");
   printf("\nPacket No\tData\n\n");
   for(i=0;i<NoOfPacket;i++){
     printf("%d\t\t%s\n",readdata[i].seqnum,readdata[i].data);
   }
   return NoOfPacket;
}

void shuffle(int NoOfPacket){
    int *Status;
    int i,j,trans;
    srand(time(&t));
    Status=(int *)calloc(NoOfPacket,sizeof(int));
    transdata=(PACKET *)malloc(sizeof(PACKET) *NoOfPacket);

    for(i=0;i<NoOfPacket;){
        trans=rand()%NoOfPacket;
        if(Status[trans]!=1){
            transdata[i].seqnum=readdata[trans].seqnum;
            strcpy(transdata[i].data,readdata[trans].data);
            i++;
            Status[trans]=1;
        }
    }
    free(Status);
}

void sortFrames(int NoOfPacket){
    PACKET temp;
    int i,j;

    for(i=0;i<NoOfPacket;i++){
        for(j=0;j<NoOfPacket-(i+1);j++){
            if(transdata[j].seqnum > transdata[j+1].seqnum){
                temp.seqnum=transdata[j].seqnum;
                strcpy(temp.data,transdata[j].data);
                transdata[j].seqnum=transdata[j+1].seqnum;
                strcpy(transdata[j].data,transdata[j+1].data);
                transdata[j+1].seqnum=temp.seqnum;
                strcpy(transdata[j+1].data,temp.data);
            }
        }
    }
}

void receive(int NoOfPacket){
     int i;
     printf("Packets received in the following order:\n");
     for(i=0;i<NoOfPacket;i++){
        printf("%4d",transdata[i].seqnum);
     }

     sortFrames(NoOfPacket);

     printf("\nPackets in order after sorting is: \n");
     for(i=0;i<NoOfPacket;i++){
        printf("%4d",transdata[i].seqnum);
     }

     printf("\nMessage received in following order:\n");
     for(i=0;i<NoOfPacket;i++){
        printf("%s",transdata[i].data);
     }
}

int main()
{
    char msg[25];
    int NoOfPacket;
    printf("Enter the message to be transmitted\n");
    scanf("%[^\n]",msg);
    NoOfPacket=divide(msg);
    shuffle(NoOfPacket);
    receive(NoOfPacket);
    free(readdata);
    free(transdata);
    return 0;
}
