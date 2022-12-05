package com.javaprogram;

public class sumanumber {
    public static void main(String[] args){
        int num=456,sum=0;
        int rem;
        while(num!=0){
            rem=num%10;
            sum+=rem;
            num/=10;
        }
        System.out.println("The sum of digits is: "+sum);
    }
}
