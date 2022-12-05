#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1,*f2;
    char c;
    printf("Please enter your information:\n");
    f1=fopen("INPUT","w");
    while((c=getchar())!=EOF)
    putc(c,f1);

    fclose(f1);

    f1=fopen("INPUT","r");
    f2=fopen("OUTPUT","w");
    while((c=getc(f1))!=EOF)
        putc(c,f2);

    fclose(f1);
    fclose(f2);
    printf("The stored information in file are:\n");
    f2=fopen("OUTPUT","r");

    while((c=getc(f2))!=EOF)
        putchar(c);
    fclose(f2);
    return 0;
}


