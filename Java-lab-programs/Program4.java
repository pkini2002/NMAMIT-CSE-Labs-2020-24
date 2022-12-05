//  Create a class as Student. Write a program in Java to display the names and roll numbers of 
// students. Create an array of 10 students and initialize the array with user input. Handle 
// ArrayIndexOutOfBoundsExeption, so that any such problem doesn’t cause illegal termination 
// of program. Read a character from user and display the student names starting with given 
// character.

import java.util.Scanner;

class student {
    String name;
    int rollno;

    student(String name, int rollno){
        this.name=name;
        this.rollno=rollno;
    }

    void display(){
        System.out.println("Name of the student is: "+ name);
        System.out.println("Roll number is: "+rollno);
    }
}

public class Exception {
    public static void main(String args[]){
        String name;
        int rollno;
        Scanner s=new Scanner(System.in);
        Scanner s2=new Scanner(System.in);

        Student st[]=new Student[5];

        try{
            for(int i=0;i<5;i++){
                System.out.println("Enter the name of the student: ");
                name=s.nextLine();
                System.out.println("Enter the rollnumber: ");
                rollno=s2.nextInt();
                st[i]=new Student(name,rollno);
            }
        }catch(ArrayIndexOutOfBoundsException e){
            e.printStackTrace();
        }

        System.out.println("Enter the first character: ");
        char check=s.next().charAt(0);
        try{
            for(int i=0;i<5;i++){
                if(check == st[i].name.charAt(0)){
                    st[i].display();
                }
            }
        }catch(ArrayIndexOutOfBoundsException e){
            e.printStackTrace();
        }
    }
}
