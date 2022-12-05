package pack;

class Employee{
    int salary;
    String ename;
    int empid;

    Employee(){
        ename="Kini";
        empid=139;
    }

    void earnings(){
        salary=10000;
        System.out.println("Salary is: "+salary);
    }
}

class salariedEmployee extends Employee{
    int salary;
    void earnings(){
        salary=15000;
        System.out.println("Salary is: "+salary);
    }
}

public class EmployeeTest {
    public static void main(String args[]){
        salariedEmployee obj=new salariedEmployee();
        obj.earnings();
    }
}
