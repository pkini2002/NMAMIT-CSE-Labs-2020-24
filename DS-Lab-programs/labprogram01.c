#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[30];
    int age;
    char branch[10];
};

int main()
{
   int n;
   printf("Enter the number of students:\n");
   scanf("%d",&n);
   struct student s[100],*p[100];
   for(int i=1;i<=n;i++)
   {
       p[i]=&s[i];
       printf("Enter the name of the student:\n");
       scanf("%s",s[i].name);
       printf("Enter the age:\n");
       scanf("%d",&s[i].age);
       printf("Enter the branch:\n");
       scanf("%s",s[i].branch);
   }
   for(int i=1;i<=n;i++)
   {
       printf("The entered information is:\n");
       printf("%s\n",p[i]->name);
       printf("%d\n",p[i]->age);
       printf("%s\n",p[i]->branch);
   }
   return 0;
}
