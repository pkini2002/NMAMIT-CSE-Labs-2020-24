/*Given that an EMPLOYEE class ontains following members. Data members:Eno, Ename 
and salary Member functions: to read the data , to print data members.Write a C++ program 
to read the data of N employees and display detials of each employee.(use Array of objects 
concept).*/

#include<iostream>
using namespace std;

class Employee{
    char emp_name[50];
    int emp_num;
    int salary;
 public:
    void getdata();
    void putdata();
};

void Employee::getdata()
{
    cout<<"Enter the name of the employee:";
    cin>>emp_name;
    cout<<"Enter the employee number:";
    cin>>emp_num;
    cout<<"Enter the salary:";
    cin>>salary;
}

void Employee::putdata()
{
    cout<<"The name of the employee is:";
    cout<<emp_name;
    cout<<"\n";
    cout<<"The employee number is:";
    cout<<emp_num;
    cout<<"\n";
    cout<<"The salary is:";
    cout<<salary;
    cout<<"\n";
}

int main()
{
   Employee e[100];
   int n;
   cout<<"Enter the number of employees:";
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cout<<"Enter the details of employee"<<i+1<<endl;
       e[i].getdata();
   }
   cout<<"The enetered information is:"<<endl;
   for(int i=0;i<n;i++)
   {
       cout<<"The details of the employee"<<i+1<<endl;
       e[i].putdata();
       cout<<"\n";
   }
   return 0;
}