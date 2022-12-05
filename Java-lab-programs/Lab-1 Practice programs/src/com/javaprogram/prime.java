package com.javaprogram;


public class prime {
    public static void main(String[] args){
        int num=5;
        int flag=0;
        for(int i=2;i<num/2;i++){
            if(num%i==0){
                System.out.println("The number is not prime!");
                flag=1;
                break;
            }
        }
        if(flag==0)
            System.out.println("The number is prime!");
    }
}
