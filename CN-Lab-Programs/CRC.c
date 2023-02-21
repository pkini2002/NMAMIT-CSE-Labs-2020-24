#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

struct reg{
     int bit;
}r[16];

int n,input[MAX_SIZE];

void compute_crc(){
     int i,j,lmb;

     for(j=0;j<(n+16);j++){
        lmb=r[15].bit;
        for(i=15;i>0;i--){
            r[i].bit=r[i-1].bit;
        }
        r[0].bit=input[j];
        if(lmb == 1){
            r[12].bit=r[12].bit ^ lmb;
            r[5].bit=r[5].bit ^ lmb;
            r[0].bit=r[0].bit ^ lmb;
        }
     }

     printf("Register Content: \n");
     for(i=15;i>=0;i--){
        printf("%d ",r[i].bit);
     }
     for(i=n,j=15;j>=0;i++,j--){
        input[i]=r[j].bit;
     }
}

int check_err(){
    int i;
    for(i=15;i>=0;i--){
        if(r[i].bit!=0){
            return i;
        }
    }
    return 0;
}

void read_input(){
    int i;
    printf("\nEnter the number of bits in the input:\n");
    scanf("%d",&n);

    printf("\nEnter the information bits (1's and 0's): \n");
    for(i=0;i<n;i++){
        scanf("%d",&input[i]);
    }

    for(i=n;i<(n+16);i++){
        input[i]=0;
    }
}

int main()
{
    int i;
    read_input();
    printf("\n\nAt Sender\n\n");

    for(i=0;i<16;i++){
        r[i].bit=0;
    }

    compute_crc();
    printf("\nThe total message along with crc: \n");
    for(i=0;i<(n+16);i++){
        printf("%d",input[i]);
    }

    printf("\n\nThe data is transmitted\n\n");
    printf("\nAt receiver: \n\n");
    printf("\nEnter the received data:\n");

    for(i=0;i<(n+16);i++){
        scanf("%d",&input[i]);
    }

    for(i=0;i<16;i++){
        r[i].bit=0;
    }

    compute_crc();

    if(i=check_err()){
        printf("\nThere is error in the received data. Error position: %d\n",i);
    }
    else{
        printf("\nThe received data is fine\n");
    }
    return 0;
}
