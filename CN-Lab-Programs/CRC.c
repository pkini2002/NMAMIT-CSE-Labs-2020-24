#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct reg{
    int bit;
}r[16];

int n,input[MAX];

void computeCRC(){
     int i,j,lmb;
     for(j=0;j<=(n+16);j++){
        lmb=r[15].bit;
        for(i=15;i>0;i--){
            r[i].bit=r[i-1].bit;
        }
        r[0].bit=input[j];
        if(lmb==1){
            r[12].bit = r[12].bit ^ lmb;
            r[5].bit = r[5].bit ^ lmb;
            r[0].bit = r[0].bit ^ lmb;
          }

     }

     printf("\nThe register contents are: \n");
     for(i=15;i>=0;i--){
        printf("%d",r[i].bit);
     }

     for(i=n,j=15;j>=0;i++,j--){
        input[i]=r[j].bit;
     }
}

void read_data(){
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    printf("Enter the input bits: (0/1)\n");
    for(int i=0;i<n;i++){
        scanf("%d",&input[i]);
    }

    for(int i=n;i<(n+16);i++){
        input[i]=0;
    }
}


int check_error(){
   for(int i=15;i>=0;i--){
      if(r[i].bit!=0){
        return i+1;
      }
   }
   return 0;
}

int main(){
   int i;
   read_data();
   printf("At sender..\n");

   for(int i=0;i<16;i++){
      r[i].bit=0;
   }

   computeCRC();

   printf("\nThe total message along with crc is:\n");
   for(i=0;i<(n+16);i++){
      printf("%d ",input[i]);
   }

   printf("Message sent..\n");
   printf("\nAt the receiver enter the received data is:\n");
   for(i=0;i<(n+16);i++){
      scanf("%d", &input[i]);
   }
   printf("\n");

   for(i=0;i<16;i++){
     r[i].bit=0;
   }

   computeCRC();

   if(i==check_error()){
     printf("\nThere is an error in received data at position %d", check_error());
   }
   else{
      printf("\nThe received data is fine\n");
   }
    return 0;
}
