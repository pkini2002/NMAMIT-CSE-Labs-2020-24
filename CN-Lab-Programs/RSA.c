#include <stdio.h>
#include <stdlib.h>
#define max 100
int n,e,cipher[max],len;
int gcd(int x,int y)
{
    while(x!=y)
    {
        if(x>y)
        {
            x-=y;

        }
        else
        {
            y-=x;
        }
    }
    return x;
}
void sender()
{
   char ch[max];
   int i,j;
   printf("Enter message\n");
   for(len=0;len<max;len++)
   {
        scanf("%c",&ch[len]);
        if(ch[len]=='\n')
            break;
   }
    printf("\nEncryption\n");
    printf("n=%d, e=%d\n",n,e);
    for(j=0;j<len;j++)
    {
        cipher[j]=1;
        for(i=0;i<e;i++)
        {
            cipher[j]=(cipher[j]*ch[j])%n;
        }
    }
    for(i=0;i<len;i++)
    {
        printf("%d",cipher[i]);
    }
}
void receiver()
{
     int p=11,q=17,z,d,i,j;
    long msg[max];
    n=p*q;
    z=(p-1)*(q-1);
    e=1;
    do{
        e++;
    }
    while((gcd(e,z)!=1)&&(e<z));
    for(d=2;d<z;d++)
    {
        if(((e*d)%z)==1)
            break;
    }
    sender();
    printf("\nDecryption\n");
    for(j=0;j<len;j++)
    {
        msg[j]=1;
        for(i=0;i<d;i++)
            msg[j]=(msg[j]*cipher[j])%n;
    }
    for(i=0;i<len;i++)
        printf("%c",msg[i]);
}

int n,e,cipher[max],len;

int main()
{
    receiver();
    getchar();
    return 0;
}
