package com.javaprogram;

public class palindrome {
    public static void main(String[] args){
        int n=5357;
        int rem,sum=0;
        int temp=n;
        while(n!=0){
            rem=n%10;
            sum=sum*10+rem;
            n/=10;
        }
        if(sum==temp)
            System.out.println("The number is a palindrome");
        else
            System.out.println("The number is not a palindrome");
    }
}
