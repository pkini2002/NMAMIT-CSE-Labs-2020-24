/*
You are given an interface AdvancedArithmetic which contains method signature int divisor_sum(int n)
You need to write a class called MyCalculator which implements the interface. divisor_sum() function
just takes an integer as an input and returns the sum of all its divisors. For ex: divisors
of 6 are 1,2,3 and 6 so divisor sum should return 12. The value of n will be atmost 1000.
 */


package pack;
import java.util.Scanner;

interface AdvancedArithmetic{
    int divisor_sum(int n);
}

class MyCalculator implements AdvancedArithmetic{
    int n;
    int sum=0;
    MyCalculator(int n){
        this.n=n;
    }

    public int divisor_sum(int n){
       for(int i=1;i<=n;i++){
           if(n%i==0){
               sum+=i;
           }
       }
       return sum;
    }

    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n;
        System.out.println("Enter the value of n:");
        n=s.nextInt();
        MyCalculator obj=new MyCalculator(n);
        int value=obj.divisor_sum(n);
        System.out.println("The sum of divisors of "+n+" is "+value);
    }
}

