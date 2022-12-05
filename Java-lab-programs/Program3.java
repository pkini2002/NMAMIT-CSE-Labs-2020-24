/* 

Design a class called Student having data members like student name and roll number and 
method called show to display the name and roll number. Derive a class called Test from student 
class having three subjects’ marks as a data members and method named show_marks to 
display the marks. Create an interface called Sports contains constant sports marks and method
show_sportswt. Derive a class Result from Test class and implement the interface Sports
.Calculate total marks by considering sports marks. Then display the total in Result class.

*/

package pack;
import java.util.Scanner;

class Student{
    String name;
    int rollno;

    Student(String name, int rno){
        this.name=name;
        this.rollno=rno;
    }

    void show(){
        System.out.println("Name: "+name+"\nRoll Number:" +rollno);
    }
}

class test extends Student{
    int sub1,sub2,sub3;

    test(int sub1,int sub2,int sub3,String name,int rollno){
        super(name,rollno);
        this.sub1=sub1;
        this.sub2=sub2;
        this.sub3=sub3;
    }

    void show_marks(){
        System.out.println("Subject 1: "+sub1);
        System.out.println("Subject 2: "+sub2);
        System.out.println("Subject 3: "+sub3);
    }
}

interface Sports{
    final int sport_mark=40;
    void show_sportswt();
}

class result extends test implements Sports{
    int total=sub1+sub2+sub3+sport_mark;

    public void show_sportswt(){
        System.out.println("Sports marks: "+sport_mark);
    }

    result(String name,int rollno,int sub1,int sub2,int sub3){
        super(sub1,sub2,sub3,name,rollno);
    }

    void display(){
        System.out.println("Total marks: "+total);
    }
}

public class Lab3{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the name of the student: ");
        String name=s.nextLine();
        System.out.println("Enter the roll number of the student: ");
        int rno=s.nextInt();
        System.out.println("Enter the subject 1 marks: ");
        int sub1=s.nextInt();
        System.out.println("Enter the subject 2 marks: ");
        int sub2=s.nextInt();
        System.out.println("Enter the subject 3 marks: ");
        int sub3=s.nextInt();

        result res=new result(name,rno,sub1,sub2,sub3);
        res.show();
        res.show_marks();
        res.show_sportswt();
        res.display();
    }
}
