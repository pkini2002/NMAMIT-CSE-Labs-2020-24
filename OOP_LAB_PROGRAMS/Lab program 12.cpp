#include <iostream>

using namespace std;

class Complex
{
    int re,img;
public:
    Complex()
    {
        re=0;
        img=0;
    }
    Complex(int a,int b)
    {
        re=a;
        img=b;
    }
    Complex operator +(Complex c)
    {
        Complex temp;
        temp.re=re+c.re;
        temp.img=img+c.img;
        return temp;
    }
     Complex operator -(Complex c)
    {
        Complex tem;
        tem.re=re-c.re;
        tem.img=img-c.img;
        return tem;
    }
    void display()
    {
        cout<<"Complex number="<<re<<"+i"<<img<<endl;
    }

};

int main()
{
    int i,j,m,n;
    cout<<"Enter the 1st complex number:\n";
    cout<<"Enter the real and imaginary part\n";
    cin>>i>>j;
    cout<<"Enter the 2nd complex number:\n";
    cout<<"Enter the real and imaginary part\n";
    cin>>m>>n;
    Complex c1(i,j),c2(m,n),c3,c4;
    c1.display();
    c2.display();
    c3=c1+c2;
    c4=c1-c2;
    c3.display();
    c4.display();

    return 0;
}
