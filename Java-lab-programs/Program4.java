//  Create a class as Student. Write a program in Java to display the names and roll numbers of 
// students. Create an array of 10 students and initialize the array with user input. Handle 
// ArrayIndexOutOfBoundsExeption, so that any such problem doesn’t cause illegal termination 
// of program. Read a character from user and display the student names starting with given 
// character.


import java.util.Scanner;

class Student{
    String name;
    int rollno;

    Student(String name,int rollno){
        this.name=name;
        this.rollno=rollno;
    }

    void display(){
        System.out.println("The name of the student is: "+name);
        System.out.println("The roll number is: "+rollno);
    }
}

class Test extends student {
    int marks1,marks2,marks3;
    Test(int marks1,int marks2,int marks3,String name,int rollno){
        super(name, rollno);
        this.marks1=marks1;
        this.marks2=marks2;
        this.marks3=marks3;
    }

    void show_marks(){
        System.out.println("Marks of subject 1 is: "+marks1);
        System.out.println("Marks of subject 1 is: "+marks2);
        System.out.println("Marks of subject 1 is: "+marks3);
    }
}

interface Sports{
    final int sports_marks=10;
    void show_sportswt();
}

class Result extends Test implements Sports{
    int total=marks1+marks2+marks3+sports_marks;

    Result(int marks1,int marks2,int marks3,String name,int rollno){
        super(marks1,marks2,marks3,name,rollno);
    }

    void display(){
        System.out.println("Total marks is: "+total);
    }

    public void show_sportswt(){
        System.out.println("Sports marks is: "+sports_marks);
    }
}
public class Demo {
    public static void main(String args[]){
         Scanner s=new Scanner(System.in);
         System.out.println("Enter the name: ");
         String name=s.nextLine();
         System.out.println("Enter the roll number: ");
         int rollno=s.nextInt();
         System.out.println("Enter subject1,subject2,subject3 marks: ");
         int sub1=s.nextInt();
        int sub2=s.nextInt();
        int sub3=s.nextInt();
        Result r=new Result(sub1,sub2,sub3,name,rollno);
        r.display();
    }
}
