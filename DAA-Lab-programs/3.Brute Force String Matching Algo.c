#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int str_match(char pattern[],char text[])
{
    int m=strlen(pattern);
    int n=strlen(text);
    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        while(j<m && pattern[j]==text[i+j])
        {
            j++;
        }
        if(j==m)
            return i;
    }
    return -1;
}

int main()
{
    char text[50],pattern[50];
    int l;
    printf("Enter the text:\n");
    gets(text);
    printf("Enter the pattern:\n");
    gets(pattern);
    l=str_match(pattern,text);
    if(l==-1)
    {
        printf("No match\n");
    }
    else{
        printf("Found at %d\n",l);
    }
    return 0;
}
