// CRC Correct working code

#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct reg{
    int bit;
}r[16];

int n,input[MAX];

void compute_crc(){
    int i,j,lmb;
    for(j=0;j<(n+16);j++){
        lmb=r[15].bit;
        for(i=15;i>0;i--){
            r[i].bit=r[i-1].bit;
        }
        r[0].bit=input[j];
        if(lmb==1){
            r[12].bit=r[12].bit^lmb;
            r[5].bit=r[5].bit^lmb;
            r[0].bit=r[0].bit^lmb;
        }
    }

    printf("\nThe register contents are:\n");
    for(i=15;i>=0;i--){
        printf("%d ",r[i].bit);
    }

    for(i=n,j=15;j>=0;i++,j--){
        input[i]=r[j].bit;
    }
}

int check_error(){
    for(int i=15;i>=0;i--){
        if(r[i].bit!=0){
            return 1;
        }
    }
    return 0;
}

void read_input_data(){
    printf("\nEnter the value of n:\n");
    scanf("%d",&n);

    printf("\nEnter the input data:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }

    for(int i=n;i<(n+16);i++){
        input[i]=0;
    }
}

int main(){
    read_input_data();

    printf("At sender..\n");

    for(int i=0;i<16;i++){
        r[i].bit=0;
    }

    compute_crc();

    printf("\nThe total message along with CRC is: \n");
    for(int i=0;i<(n+16);i++){
        printf("%d ",input[i]);
    }

    printf("\nThe message is sent\n");
    printf("\nAt receiver enter the received data: \n");

    for(int i=0;i<(n+16);i++){
        scanf("%d",&input[i]);
    }

    for(int i=0;i<16;i++){
        r[i].bit=0;
    }

    compute_crc();

    if(check_error()){
        printf("\nThere is an error in the received data\n");
    }
    else{
        printf("\nThe received data is fine\n");
    }
    return 0;
}

/*

Case 1 :

Enter the value of n:
8

Enter the input data:
0 1 0 0 0 0 1 0
At sender..

The register contents are:
0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0
The total message along with CRC is:
0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0
The message is sent

At receiver enter the received data:
0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0

The register contents are:
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
The received data is fine


Case 2:

Enter the value of n:
8

Enter the input data:
0 1 0 0 0 0 1 0
At sender..

The register contents are:
0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0
The total message along with CRC is:
0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0
The message is sent

At receiver enter the received data:
0 1 0 0 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 1 0

The register contents are:
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
There is an error in the received data

*/
