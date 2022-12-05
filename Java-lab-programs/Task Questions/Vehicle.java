/*
  Create a class vehicle. The class should have 2 fields no_of_seats and no_of_wheels. Create
  2 objects motor cycle and Car for this class. Your o/p should show the description for car and
  motorcycle.

 */


package pack;
import java.util.Scanner;

public class Vehicle {
    int no_of_seats,no_of_wheels;
    Vehicle(int m,int n){
        no_of_seats=m;
        no_of_wheels=n;
    }

    void show_vehicle(){
        System.out.println("The number of wheels is: "+no_of_wheels);
        System.out.println("The number of seats is: "+no_of_seats);
    }

    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int no_of_seats,no_of_wheels;

        System.out.println("Motorcycle");
        System.out.println("Enter the number of seats: ");
        no_of_seats=s.nextInt();
        System.out.println("Enter the number of wheels: ");
        no_of_wheels=s.nextInt();
        Vehicle motor=new Vehicle(no_of_seats,no_of_wheels);

        System.out.println("Car");
        System.out.println("Enter the number of seats: ");
        no_of_seats=s.nextInt();
        System.out.println("Enter the number of wheels: ");
        no_of_wheels=s.nextInt();
        Vehicle car=new Vehicle(no_of_seats,no_of_wheels);
        motor.show_vehicle();
        car.show_vehicle();
    }
}
