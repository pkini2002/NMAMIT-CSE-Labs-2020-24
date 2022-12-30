//Write a Java Program to implement the Comparator using TreeSet class of Java
//        respectively and perform sorting operations on employee name and salary.

import java.util.*;

class Empl{
    String name;
    int salary;

    Empl(String name,int salary){
        this.name=name;
        this.salary=salary;
    }

    public int getSalary(){
        return salary;
    }

    public void setSalary(int salary){
        this.salary=salary;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name=name;
    }

    public String toString(){
        return "Name: "+this.name+" Salary: "+this.salary;
    }
}

public class TreeSetprog {
    public static void main(String args[]){
          TreeSet<Empl>nameComp=new TreeSet<Empl>(new MyNameComp());
          nameComp.add(new Empl("Prathiksha",1000));
          nameComp.add(new Empl("Pallavi",900));
          nameComp.add(new Empl("Pooja",1200));

          for(Empl e:nameComp){
              System.out.println(e);
          }

          System.out.println("=================================");

          TreeSet<Empl>salComp=new TreeSet<Empl>(new MySalaryComp());
          salComp.add(new Empl("Prathiksha",1000));
          salComp.add(new Empl("Pallavi",900));
          salComp.add(new Empl("Pooja",1200));

         for(Empl e:salComp){
            System.out.println(e);
         }

        System.out.println("=================================");
    }

    static class MyNameComp implements Comparator<Empl>{
        public int compare(Empl e1,Empl e2){
            return e1.getName().compareTo(e2.getName());
        }
    }

    static class MySalaryComp implements Comparator<Empl>{
        public int compare(Empl e1,Empl e2){
            if(e1.salary > e2.salary)
                return 1;
            else
                return -1;
        }
    }
}
