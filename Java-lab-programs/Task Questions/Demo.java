/*
   Simple program to implement Hierarchical Inheritance
 */

package pack;

class vehicle{
    int no_of_wheels,no_of_seats;
    vehicle(){
        no_of_wheels=0;
        no_of_seats=0;
    }

    void show_vehicle(){
        System.out.println("This is Vehicle class");
        System.out.println("Number of wheels: "+no_of_wheels);
        System.out.println("Number of seats: "+no_of_seats);
    }
}

class MotorCycle extends vehicle{
      MotorCycle(){
          no_of_wheels=2;
          no_of_seats=2;
      }
    void show_vehicle(){
        System.out.println("This is Motorcycle class");
        System.out.println("Number of wheels: "+no_of_wheels);
        System.out.println("Number of seats: "+no_of_seats);
    }
}

class car extends vehicle{
    car(){
        no_of_wheels=4;
        no_of_seats=5;
    }
    void show_vehicle(){
        System.out.println("This is car class");
        System.out.println("Number of wheels: "+no_of_wheels);
        System.out.println("Number of seats: "+no_of_seats);
    }
}

public class Demo {
    public static void main(String args[]){
        MotorCycle obj1=new MotorCycle();
        obj1.show_vehicle();
        car obj2=new car();
        obj2.show_vehicle();
    }
}
