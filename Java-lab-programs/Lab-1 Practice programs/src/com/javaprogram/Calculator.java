//Simple Java program to calculate addition,subtraction and multiplication of 2 numbers using Class concept
package com.javaprogram;

class Operation{
    int var1,var2;
}

public class Calculator {
    public static void main(String[] args){
        int answer ;
        //Creating 3 different objects of Operation Class
        Operation add=new Operation();
        Operation sub=new Operation();
        Operation prod=new Operation();

        //Assigning instance variables with values
        add.var1=2;
        add.var2=5;

        answer=add.var1+add.var2;

        System.out.println("Sum: "+answer);

        sub.var1=5;
        sub.var2=3;

        answer=sub.var1- sub.var2;
        System.out.println("Difference is: "+answer);

        prod.var1=6;
        prod.var2=9;

        answer=prod.var1* prod.var2;
        System.out.println("Product is: "+answer);
    }
}
