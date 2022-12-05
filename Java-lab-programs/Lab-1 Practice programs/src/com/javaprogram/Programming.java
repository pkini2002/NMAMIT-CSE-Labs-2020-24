//Java program to create a class called student with fields usn,name and age
//Single class and a main function concept
package com.javaprogram;

public class Programming {
    String usn="4NM20CS139";
    String name="Prathiksha";
    int age=19;

    public static void main(String[] args){
        Programming obj=new Programming(); //Creating an object of the class
        System.out.println("Name is: "+obj.name); //Accessing the class members
        System.out.println("USN is: "+obj.usn);
        System.out.println("Age is: "+obj.age);
    }
}
