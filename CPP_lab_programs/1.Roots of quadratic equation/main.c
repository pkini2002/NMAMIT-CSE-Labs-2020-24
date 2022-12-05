#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float a,b,c,r1,r2,d;
    printf("Enter the coefficients for a,b and c:\n");
    scanf("%f %f %f",&a,&b,&c);

    if(a==0)
    {
        printf("Roots cannot be found\n");
        exit(0);
    }
    d=b*b-4*a*c;
    if(d==0)
    {
        printf("The roots are real and equal\n");
        r1=r2=-b/(2*a);
        printf("r1=%f\n r2=%f\n",r1,r2);
    }
    else if(d>0)
    {
        printf("The roots are real and distinct\n");
        r1=(-b+sqrt(d))/(2*a);
        r2=(-b-sqrt(d))/(2*a);
        printf("r1=%f\n r2=%f\n",r1,r2);
    }
    else
    {
        printf("The roots are real and imaginary\n");
        r1=-b/(2*a);
        r2=(sqrt(fabs(d)))/(2*a);
        printf("(r1+ir2)=%f+i%f\n",r1,r2);
        printf("(r1-ir2)=%f-i%f\n",r1,r2);
    }
    return 0;
    }
