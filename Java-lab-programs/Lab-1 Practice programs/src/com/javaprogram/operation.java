package com.javaprogram;

public class operation {
    public static void main(String[] args){
        int num1=10;
        int num2=5;
        int ch=1;
        int answer=0;

        switch(ch){
            case 1:answer=num1+num2;
                   break;
            case 2:answer=num1-num2;
                   break;
            case 3:answer=num1*num2;
                   break;
            case 4:
                if(num2!=0){
                    if(num1>num2){
                        answer=num1/num2;
                    }
                    else{
                        answer=num2/num1;
                    }
                }
                else{
                    System.out.println("Cant divide a number by 0!");
                }
                break;
            default:break;
        }
        System.out.println("The answer is: "+answer);
    }
}
