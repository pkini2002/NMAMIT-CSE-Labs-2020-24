package com.javaprogram;

public class summation {
    public static void main(String[] args){
        int sum=0;
        for(int i=1;i<=20;i++){
            if(i%2==0){
                sum+=i;
            }
        }
        System.out.println("The sum of first 10 even numbers is: "+sum);
    }
}
