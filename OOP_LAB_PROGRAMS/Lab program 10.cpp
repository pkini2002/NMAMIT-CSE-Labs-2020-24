#include <iostream>

using namespace std;

class Alpha
{
    int a;
public:
    Alpha(int x)
    {
        a=x;
        cout<<"Constructor of alpha class\n";
    }
    void put_a()
    {
        cout<<"Value of a is:"<<a<<endl;
    }
};

class Beta
{
    int b;
public:
    Beta(int y)
    {
        b=y;
      cout<<"Constructor of beta class\n";
   }
   void put_b()
   {
    cout<<"Value of b is:"<<b<<endl;
   }
};

class Gamma:public Alpha,public Beta
{
    int m,n;
public:
    Gamma(int p,int q,int r,int s):Alpha(p),Beta(q)
    {
        m=r;
        n=s;
        cout<<"Constructor of gamma class\n";
    }
    void display()
    {
        cout<<"M="<<m<<endl;
        cout<<"N="<<n<<endl;
        put_a();
        put_b();
    }
};

int main()
{
    Gamma ob(10,20,30,40);
    ob.display();
    return 0;
}
