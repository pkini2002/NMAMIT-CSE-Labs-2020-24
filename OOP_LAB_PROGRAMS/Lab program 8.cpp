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
        cout<<"Name is:"<<name<<endl;
        cout<<"USN is:"<<usn<<endl;
        cout<<"Age is:"<<age<<endl;
    }
};

class Engineering:public Student
{
protected:
    int sem;
public:
    void getsem()
    {
        cout<<"Enter the sem of the student:\n";
        cin>>sem;
    }
    void putsem()
    {
        cout<<"Sem is:"<<sem<<endl;
    }
};

class Medical:public Student
{
    int year;
public:
    void getyear()
    {
        cout<<"Enter the year:\n";
        cin>>year;
    }
    void putyear()
    {
        cout<<"Year= "<<year;
    }
};


int main()
{
    Engineering ob1;
    Medical ob2;
    cout<<"Engineering student details:\n";
    ob1.getdata();
    ob1.getsem();
    ob1.putdata();
    ob1.putsem();
    cout<<"Medical student details:\n";
    ob2.getdata();
    ob2.getyear();
    ob2.putdata();
    ob2.putyear();
    return 0;
}
