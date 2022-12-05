package pack;
import java.util.Scanner;

public class Student {
    int id,year;
    String name,branch,location,college;

    Student(){
        id=139;
        year=2022;
        name="Prathiksha";
        branch="CS";
        location="Nitte";
        college="NMAMIT";
    }

    int calc_avg(int sub1,int sub2,int sub3,int sub4,int sub5,int sub6){
        return (sub1+sub2+sub3+sub4+sub5+sub6)/6;
    }
    float calc_perc(float days_attended,float class_held){
        return (days_attended/class_held)*100;
    }

    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int sub1,sub2,sub3,sub4,sub5,sub6,res;
        float result;
        float days_attended,class_held;

        System.out.println("Enter the marks of 6 subjects: ");
        sub1=s.nextInt();
        sub2=s.nextInt();
        sub3=s.nextInt();
        sub4=s.nextInt();
        sub5=s.nextInt();
        sub6=s.nextInt();

        Student obj=new Student();
        res=obj.calc_avg(sub1,sub2,sub3,sub4,sub5,sub6);

        System.out.println("Enter the number of classes attended by student: ");
        days_attended=s.nextFloat();

        System.out.println("Enter the number of classes held");
        class_held=s.nextFloat();

        result= obj.calc_perc(days_attended,class_held);

        System.out.println("The avg marks obtained by the student is: "+res);
        System.out.println("The attendance percentage is: "+result);
    }
}
