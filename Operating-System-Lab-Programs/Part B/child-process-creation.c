#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
 int pid,i;
 printf("The parent process id=%d\n",getpid());
 for(i=1; i<=5; i++)
 {
 int pid=fork();
 if(pid<0)
 {
 printf("Fork failed!");
 exit(0);
 }
 else if(pid==0)
 {
 printf("Child process id=%d\n",getpid());
 exit(0);
 }
 wait(NULL);
 }
 return 0;
}
