#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[50];
    int id,marks[6];
    float avg;
};


int main()
{
    struct student s[50];
    int i,j,n;
    float avg,sum=0.0;


    printf("Enter number of students in the class:\n");
    scanf("%d",&n);
    printf("Enter the student details of %d students:\n",n);
           for(i=1;i<=n;i++)
           {
               printf("Enter Student details %d\n",i);
               printf("Enter the name of the student:\n");
               scanf("%s",s[i].name);
               printf("Enter the ID of the student:\n");
               scanf("%d",&s[i].id);
               printf("Enter the marks in 6 subjects obtained by the student:\n");
               for(j=1;j<=6;j++)
               {
                   printf("Subject:%d\n",j);
                   scanf("%d",&s[i].marks[j]);
               }
               sum=0;

               for(j=1;j<=6;j++)

                sum=sum+s[i].marks[j];
               s[i].avg=sum/6;

               printf("Average marks of a student %d is %f\n",i,s[i].avg);

               if(s[i].avg>=80&&s[i].avg<=100)
                printf("Distinction\n");
               else if(s[i].avg>=60&&s[i].avg<=79)
                printf("First class\n");
               else if(s[i].avg>=40&&s[i].avg<=59)
                printf("Second class\n");
               else
                printf("Fail\n");
           }
           return 0;
}
