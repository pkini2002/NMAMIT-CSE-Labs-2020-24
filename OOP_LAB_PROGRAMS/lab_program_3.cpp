/*Write a C++ program with class Time with data members that represents hours and 
minutes.Include appropriate member functions to compute time in hours and minutes . (Use of 
objects as arugemnts).*/

#include<iostream>
using namespace std;

class Time{
    int hours;
    int minutes;
public:
    void getdata();
    void putdata();
    void compute(Time t1,Time t2);
};

void Time::getdata()
{
    cout<<"Enter the hours:"<<endl;
    cin>>hours;
    cout<<"Enter the minutes:"<<endl;;
    cin>>minutes;
    cout<<"The entered time is:"<<hours<<":"<<minutes<<endl;
}

void Time::compute(Time t1,Time t2)
{
    hours=t1.hours+t2.hours;
    minutes=t1.minutes+t2.minutes;
    if(minutes>59)
    {
        hours+=1;
        minutes=minutes-60;
    }
}

void Time::putdata()
{
    cout<<"The entered time is:"<<hours<<":"<<minutes<<endl;
}

int main()
{
    Time t1,t2,t3;
    t1.getdata();
    t2.getdata();
    t3.compute(t1,t2);
    t3.putdata();
    return 0;
}
