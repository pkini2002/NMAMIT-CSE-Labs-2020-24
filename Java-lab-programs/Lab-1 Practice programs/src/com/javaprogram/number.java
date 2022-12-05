package com.javaprogram;

public class number {
    public static void main(String[] args){
        System.out.println("Even numbers are: ");
        for(int i=1;i<=20;i++){
            if(i%2==0){
                System.out.print(i+" ");
            }
        }
        System.out.println("");
        System.out.println("Odd numbers are: ");
        for(int i=1;i<=20;i++){
            if(i%2==1){
                System.out.print(i+" ");
            }
        }
    }
}
