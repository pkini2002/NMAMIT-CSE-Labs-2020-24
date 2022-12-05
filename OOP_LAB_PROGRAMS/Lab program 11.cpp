#include <iostream>

using namespace std;

class Student
{
protected:
     char name[50];
     int usn;
     int age;
public:
    void getdata()
    {
        cout<<"Enter the name of the student:\n";
        cin>>name;
        cout<<"Enter the usn:\n";
        cin>>usn;
        cout<<"Enter the age:\n";
        cin>>age;
    }
    void putdata()
    {
        cout<<"Name="<<name<<endl;
        cout<<"USN= "<<usn<<endl;
        cout<<"Age= "<<age<<endl;
    }
};

class Test:virtual public Student
{
protected:
    int sub1,sub2;
public:
    void getmarks()
    {
        cout<<"Enter the marks of sub 1 and sub 2:\n";
        cin>>sub1>>sub2;
    }
    void putmarks()
    {
        cout<<"Sub1="<<sub1<<endl;
        cout<<"Sub2="<<sub2<<endl;
    }
};

class Sports:virtual public Student
{
protected:
    int score;
public:
    void getscore()
    {
        cout<<"Enter the score:\n";
        cin>>score;
    }
    void putscore()
    {
        cout<<"Score="<<score<<endl;
    }

};

class Result:public Test,public Sports
{
protected:
    int total;
public:
    void display()
    {
        total=sub1+sub2+score;
        putdata();
        putmarks();
        putscore();
        cout<<"Total="<<total<<endl;
    }
};

int main()
{
    Result r[100];
    int n,i;
    cout<<"Enter the number of students in the class:\n";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        r[i].getdata();
        r[i].getmarks();
        r[i].getscore();
        r[i].display();
    }
    return 0;
}
