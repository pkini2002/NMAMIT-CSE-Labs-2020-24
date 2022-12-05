/*Write a C++ program to create a class called COMPLEX and implement the following 
overloading function ADD that return a COMPLEX number.
i. ADD(a,c2);- where a is an integer(real part) & c2 is a complex no.
ii. ADD(c1,c2);- where c1 & c2 are complex nos.
use Function overloading(ADD) and Friend function concept for the implementation*/

#include<iostream>
using namespace std;

class Complex{
    int real;
    int imaginary;
public:
    void getdata();
    friend void add(int a,Complex c2);
    friend void add(Complex c1,Complex c2);
};

void Complex::getdata()
{
    cout<<"Enter the complex number:"<<endl;
    cout<<"Enter the real part:"<<endl;
    cin>>real;
    cout<<"Enter the imaginary part:"<<endl;
    cin>>imaginary;
    cout<<"The entered complex number is:"<<real<<"i"<<imaginary<<endl;
}

void add(int a,Complex c2)
{
    int rl,img;
    rl=a+c2.real;
    img=c2.imaginary;
    cout<<"Complex number is:"<<rl<<"+"<<"i"<<img<<endl;
}

void add(Complex c1,Complex c2)
{
    int rl,img;
    rl=c1.real+c2.real;
    img=c1.imaginary+c2.imaginary;
    cout<<"Complex number is:"<<rl<<"+i"<<img<<endl;
}

int main()
{
    Complex c1,c2;
    int a;
    cout<<"Enter the real number:"<<endl;
    cin>>a;
    c1.getdata();
    c2.getdata();
    add(a,c2);
    add(c1,c2);
    return 0;
}