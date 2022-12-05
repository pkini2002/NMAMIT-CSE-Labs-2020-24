#include <iostream>

using namespace std;

class Shape
{
public:
     double x,y;
    void read()
    {
        cout<<"Enter the values for x and y:\n";
        cin>>x>>y;
    }

    virtual void display_area()=0;
};

class Triangle:public Shape
{
public:
    void display_area()
    {
    cout<<"The area of the triangle is:\n";
    cout<<(0.5*x*y);
    }
};

class Rectangle:public Shape
{
public:
    void display_area()
    {
        cout<<"The area of the rectangle is:\n";
        cout<<(x*y);
    }
};


int main()
{
    Shape *ptr;
    Triangle t;
    Rectangle r;
    int choice;
    while(1)
    {
        cout<<"Enter your choice:\n1.Area of triangle\n2.Area of rectangle\n3.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:ptr=&t;
                   ptr->read();
                   ptr->display_area();
            case 2:ptr=&r;
                   ptr->read();
                   ptr->display_area();
            case 3:exit(0);
            default:cout<<"Invalid choice!!\n";
        }
    }
    return 0;
}
