/* Write a C program to generate Hamming Code Sequence */

#include <stdio.h>
#include <stdlib.h>

// Number of databits = 7 and redundant bits=4

int hammingcode[11];
void CorrectError();

void generateHammingCode(){
    int temp,i;
    /* First parity bit */
  
    // Counting the number of 1's if its even parity then bit is 0 else bit is 1
    temp=hammingcode[3]+hammingcode[5]+hammingcode[7]+hammingcode[9]+hammingcode[11];
    (temp%2!=0)?(hammingcode[1]=1):(hammingcode[1]=0);

    /* Second parity bit */
    temp=hammingcode[3]+hammingcode[6]+hammingcode[7]+hammingcode[10]+hammingcode[11];
    (temp%2!=0)?(hammingcode[2]=1):(hammingcode[2]=0);

    /* Third parity bit */
    temp=hammingcode[5]+hammingcode[6]+hammingcode[7];
    (temp%2!=0)?(hammingcode[4]=1):(hammingcode[4]=0);

    /*Fourth parity bit*/
    temp=hammingcode[9]+hammingcode[10]+hammingcode[11];
    (temp%2!=0)?(hammingcode[8]=1):(hammingcode[8]=0);

    printf("\nHamming Code generated!\n");
    for(i=11;i>=1;i--){
        printf("%d ",hammingcode[i]);
    }
}

void makeError(){
    int pos,i;
    printf("\nAt what position do you want to make an error? \n");
    scanf("%d",&pos);

    // Used to change the bit at specified position since hamming code technique is used for single bit error detection
    if(hammingcode[pos]==1)
        hammingcode[pos]=0;
    else
        hammingcode[pos]=1;
    printf("\nError occurred..\n");
    for(i=11;i>=1;i--){
        printf("%d ",hammingcode[i]);
    }
    CorrectError();
}

void CorrectError(){
    int r1,r2,r4,r8,errpos,i;
    r1=(hammingcode[1]+hammingcode[3]+hammingcode[5]+hammingcode[7]+hammingcode[9]+hammingcode[11])%2;
    r2=(hammingcode[2]+hammingcode[3]+hammingcode[6]+hammingcode[7]+hammingcode[10]+hammingcode[11])%2;
    r4=(hammingcode[4]+hammingcode[5]+hammingcode[6]+hammingcode[7])%2;
    r8=(hammingcode[8]+hammingcode[9]+hammingcode[10]+hammingcode[11])%2;
    // Converting binary to decimal
    errpos=r8*8+r4*4+r2*2+r1*1;
    if(hammingcode[errpos]==1)
        hammingcode[errpos]=0;
    else
        hammingcode[errpos]=1;
    printf("\n Error has occurred at position %d\n",errpos);
    printf("\nThe error is corrected\n");
    for(i=11;i>=1;i--){
        printf("%d ",hammingcode[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    char ch;
    printf("\nEnter the message in bits: \n");
    for(i=11;i>=1;i--){
       // Don't take the input for redundant bits so just continue onto the next iteration
        if(i==1 || i==2 || i==4 || i==8){
            continue;
        }
        else{
            scanf("%d",&hammingcode[i]);
        }
    }
    generateHammingCode();
    printf("\n Do you want to make any error?(Y/N): \n");
    scanf("%s",&ch);
    if(ch=='y' || ch=='Y')
        makeError();
    else
        printf("\n Bits received without any errors!\n");
    return 0;
}

/*
Output:
       
Case 1: When you want to make an error in the message and correct it
       
       
Enter the message in bits:
1 0 1 1 0 0 1

Hamming Code generated!
1 0 1 0 1 0 0 1 1 1 0
 Do you want to make any error?(Y/N):
y

At what position do you want to make an error?
6

Error occurred..
1 0 1 0 1 1 0 1 1 1 0
 Error has occurred at position 6

The error is corrected
1 0 1 0 1 0 0 1 1 1 0

Process returned 0 (0x0)   execution time : 16.570 s
Press any key to continue.


Case 2: When you don't want to make any error

Enter the message in bits:
1 0 1 1 0 0 1

Hamming Code generated!
1 0 1 0 1 0 0 1 1 1 0
 Do you want to make any error?(Y/N):
n

 Bits received without any errors!

Process returned 0 (0x0)   execution time : 17.909 s
Press any key to continue.
*/
