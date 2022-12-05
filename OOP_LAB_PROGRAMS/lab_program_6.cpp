/*. Write a C++ program to create a class sample with integer ,character and float data
members. Demonstrate Constructor Overloading on this class with all types of
constructors including default argument constructor.*/

#include<iostream>
using namespace std;

 class sample
 {
     char a;
     int b;
     float c;
public:
     sample(char m,int n,float q)//Parametrized constructor
     {
         a=m;
         b=n;
         c=q;
     }
     sample()//Default constructor
     {
         a='\0';
         b=0;
         c=0;
     }
     sample(sample &s)//Copy constructor
     {
         a=s.a;
         b=s.b;
         c=s.c;
     }
     sample(int m,float n,char q='s')//Parametrized constructor with 1 default argument
     {
        a=q;
        b=m;
        c=n;
     }
     void putdata()
     {
         cout<<"a="<<a<<" "<<"b="<<b<<" "<<"c="<<c<<endl;
     }
 };

 int main()
 {
     sample s1;
     s1.putdata();
     sample s2('d',50,78.9);
     s2.putdata();
     sample s3(s2);
     s3.putdata();
     sample s4(45,56.89);
     s4.putdata();
     return 0;
 }
