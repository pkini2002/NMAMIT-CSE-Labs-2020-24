/*Write a C++ program with two classes A and B with one integer data member in each 
class. Write member functions to read and display, place a friend function in these 
classes which takes the data members of these classes and computes maximum of two 
data members. Demonstrate using main function*/

#include<iostream>
using namespace std;

class B;
class A{
    int m;
public:
   void read(int a)
   {
       m=a;
   }
   void display()
   {
       cout<<"Value:"<<m<<endl;
   }
   friend void maximum(A obj1,B obj2);
};

class B{
    int n;
public:
    void read(int b)
    {
        n=b;
    }
    void display()
    {
        cout<<"Value:"<<n<<endl;
    }
    friend void maximum(A obj1,B obj2);
};

void maximum(A obj1,B obj2)
{
    if(obj1.m>obj2.n)
    {
        cout<<"Maximum value is:"<<obj1.m<<endl;
    }
    else{
        cout<<"Maximum value is:"<<obj2.n<<endl;
    }
}

int main()
{
     A a1;
     B b1;
     a1.read(15);
     b1.read(30);
     cout<<"A=";
     a1.display();
     cout<<"B=";
     b1.display();
     maximum(a1,b1);
     return 0;
}