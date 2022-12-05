/*

1. Write java program to design a class called Bank Account. Include following data members like name 
of the depositor, account number and balance. Initialize the data members using constructor (read 
the input from keyboard). Use following methods.
a) Deposit an amount b) to withdraw an amount c) to display name and balance.

*/



import java.util.Scanner;

class bankAccount{
    Scanner s=new Scanner(System.in);
    String name;
    int account_number,balance;

    bankAccount(String name,int account_number,int balance){
        this.name=name;
        this.account_number=account_number;
        this.balance=balance;
    }

    void deposit(){
        System.out.println("Enter the amount to be deposited: ");
        int amt=s.nextInt();
        balance+=amt;
        System.out.println("The current balance is: "+balance);
    }

    void withdraw(){
        System.out.println("Enter the amount to be withdrawn: ");
        int amt=s.nextInt();
        if(amt>balance){
            System.out.println("Insufficient balance!");
        }
        else{
            balance-=amt;
            System.out.println("The available balance is: "+balance);
        }
    }

    void display(){
        System.out.println("Name is: "+name+"\nAccount number is: "+account_number+"\nBalance is: "+balance);
    }
}

public class BankAcc {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the account holders name: ");
        String name=s.nextLine();
        System.out.println("Enter the account number: ");
        int account_number=s.nextInt();
        System.out.println("Enter the balance: ");
        int balance=s.nextInt();

        bankAccount account=new bankAccount(name,account_number,balance);
        boolean flag=true;

        while(flag){
            System.out.println("Enter your choice\n1.Deposit\n2.Withdraw\n3.Display Details\n");
            int ch=s.nextInt();
            switch (ch){
                case 1:account.deposit();
                       break;
                case 2:account.withdraw();
                       break;
                case 3:account.display();
                       break;
                default:flag=false;
            }
        }
    }
}
