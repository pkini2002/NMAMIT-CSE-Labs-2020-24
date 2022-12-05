package com.javaprogram;

class StudentDemo{
    String usn="4NM20CS139";
    String name="Prathiksha Kini";
    int age=19;
}

public class Student {
    public static void main(String[] args){
        StudentDemo obj=new StudentDemo();
        System.out.print(obj.usn+" "+obj.name+" "+obj.age);
    }
}
