//Write a program for simple RSA algorithm to encrypt and decrypt the data

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 100

int cipher[MAX],n,e,len;

int gcd(int x,int y){
     while(x!=y){
        if(x>y){
            x-=y;
        }
        else{
            y-=x;
        }
     }
     return x;
}

void sender(){
    char ch[MAX];
    printf("\nEnter the message to be sent:\n");
    for(len=0;len<MAX;len++){
        scanf("%c",&ch[len]);
        if(ch[len]=='\n')
            break;
    }
    printf("\nEncryption..\n");
    printf("n=%d\t\t e=%d\t\t",n,e);
    for(int j=0;j<len;j++){
        cipher[j]=1;
        for(int i=0;i<e;i++){
            cipher[j]=(cipher[j]*ch[j])%n;
        }
    }

    for(int i=0;i<len;i++){
        printf("%d",cipher[i]);
    }
}

void receiver(){
   long msg[MAX];
   int p=11;
   int q=17;
   n=p*q;
   int z;
   int d;
   int i,j;
   z=(p-1)*(q-1);
   e=1;
   do{
    e++;
   }while((gcd(e,z)!=1) && (e<z));

   for(d=2;d<z;d++){
      if(((e*d)%z) ==1){
        break;
      }
   }

   sender();

   printf("\nDecryption..\n");
   for(j=0;j<len;j++){
       msg[j]=1;
       for(i=0;i<d;i++){
          msg[j]=(msg[j]*cipher[j])%n;
       }
   }

   for(i=0;i<len;i++){
      printf("%c",msg[i]);
   }
}

int main(){
    receiver();
    getchar();
    return 0;
}


/*

Output:

Enter the message to be sent:
helloworld

Encryption..
n=187            e=3            59118808010010210013080111
Decryption..
helloworld

*/
