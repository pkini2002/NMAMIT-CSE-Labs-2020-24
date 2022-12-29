//Write a Java Program to implement the Comparator using TreeSet class of Java 
//respectively and perform sorting operations on employee name and salary.

import java.util.*;

class Empl{
    String name;
    int salary;

    Empl(String name,int salary){
        this.name=name;
        this.salary=salary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name=name;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary=salary;
    }

    public String toString() {
        return "\nName: "+this.name+" Salary: "+this.salary;
    }
}

public class Comp {
    public static void main(String args[]) {
        TreeSet<Empl>nameComp=new TreeSet<Empl>(new MyNameComp());
        nameComp.add(new Empl("Ram",3000));
        nameComp.add(new Empl("John",6000));
        nameComp.add(new Empl("Crish",2000));
        nameComp.add(new Empl("Tom",2400));

        for(Empl e:nameComp) {
            System.out.println(e);
        }

        System.out.println("=================");

        TreeSet<Empl>salComp=new TreeSet<Empl>(new MySalaryComp());
        salComp.add(new Empl("John",6000));
        salComp.add(new Empl("Crish",2000));
        salComp.add(new Empl("Tom",2400));
        salComp.add(new Empl("Ram",3000));

        System.out.println();
        for(Empl e:salComp) {
            System.out.println(e);
        }

        System.out.println("=================");
    }
}

class MyNameComp implements Comparator<Empl>{
    public int compare(Empl e1,Empl e2) {
        return e1.getName().compareTo(e2.getName());
    }
}

class MySalaryComp implements Comparator<Empl>{
    public int compare(Empl e1, Empl e2)
    {
        if(e1.getSalary() > e2.getSalary()){
            return 1;
        }
        else {
            return -1;
        }
    }
}
