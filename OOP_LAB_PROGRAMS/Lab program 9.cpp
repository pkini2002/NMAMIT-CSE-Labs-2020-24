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
        cout<<"Enter name of the student:\n";
        cin>>name;
        cout<<"Enter the usn of the student:\n";
        cin>>usn;
        cout<<"Enter the age:\n";
        cin>>age;
    }
    void putdata()
    {
        cout<<"Name is:"<<name<<endl;
        cout<<"USN is:"<<usn<<endl;
        cout<<"Age is:"<<age<<endl;
    }
};

class Test:public Student
{
protected:
    int sub1,sub2;
public:
    void getmarks()
    {
        cout<<"Enter the marks of the subject:\n";
        cin>>sub1>>sub2;
    }
    void putmarks()
    {
        cout<<"Sub 1:"<<sub1<<endl;
        cout<<"Sub 2:"<<sub2<<endl;
    }
};

class Sports
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
        cout<<"Score: "<<score<<endl;
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
        cout<<"Total= "<<total;
    }
};

int main()
{
    Result r;
    r.getdata();
    r.getmarks();
    r.getscore();
    r.display();
    return 0;
}
