/*1. Write C++ program to design a class called BankAccount. Include following data members 
like name of the depositor, account number and balance. Use following member functions a) to 
initialize values b) deposit an amount c) to withdraw an amount d) to display name and balance*/

#include<iostream>
using namespace std;

class BankAccount{
    char name[50];
    int acc_num;
    int balance;
public:
    void initialize();
    void deposit();
    void withdraw();
    void display();
};

int main()
{
    BankAccount b1;
    b1.initialize();
    int choice;
    for(;;)
    {
        cout<<"Enter the operation you want to perform:"<<endl;
        cout<<"1.Deposit\n2.Withdraw\n3.Display\n";
        cin>>choice;
        switch(choice)
        {
            case 1:b1.deposit();
                   break;
            case 2:b1.withdraw();
                   break;
            case 3:b1.display();
                   break;
            case 4:exit(0);
            default:cout<<"Invalid!!"<<endl;
        }
    }
    return 0;
}

void BankAccount::initialize()
{
     cout<<"Enter the name of the account holder:";
     cin>>name;
     cout<<"Enter the account number:";
     cin>>acc_num;
     cout<<"Enter the balance:";
     cin>>balance;
}

void BankAccount::deposit()
{
   int deposit_amt;
   cout<<"Enter the deposit amount:";
   cin>>deposit_amt;
   balance+=deposit_amt;
   cout<<"Balance:"<<balance<<endl;
}

void BankAccount::withdraw()
{
    int withdraw_amt;
    cout<<"Enter the amount to be withdrawn:";
    cin>>withdraw_amt;
    if(balance<withdraw_amt)
    {
        cout<<"Insufficient amount!!"<<endl;
    }
    else{
        balance=balance-withdraw_amt;
        cout<<"Balance="<<balance<<endl;
    }
}

void BankAccount::display()
{
    cout<<"Name:"<<name<<endl;
     cout<<"Account number:"<<acc_num<<endl;
      cout<<"Balance:"<<balance<<endl;
}