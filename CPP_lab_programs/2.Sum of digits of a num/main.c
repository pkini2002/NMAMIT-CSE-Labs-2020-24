//C program to find the sum of elements of a number and to find occurrence of digit
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,digit,sum=0,rem,count=0,temp;
    printf("Enter the number\n");
    scanf("%d",&num);

    printf("Enter the digit which has to be found\n");
    scanf("%d",&digit);

    temp=num;

    while(num!=0)
    {
        rem=num%10;
        sum=sum+rem;
        num=num/10;

    if(rem==digit)
        count++;
    }
    printf("The sum of all %d elements is %d\n",temp,sum);
    printf("The digit %d has occurred for %d times\n",digit,count);


    return 0;
}
