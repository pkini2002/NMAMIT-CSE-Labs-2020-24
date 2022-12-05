/*
Develop with suitable hierarchy classes for Point, Shape, Rectangle, Circle, Square, Eliipse and Polygon
Design a simple test application to implement hierarchical inheritance.
 */

package pack;

class Point{
    int a;
    Point() {
        System.out.println("Point Class");
        a=10;
    }
}

class Shape extends Point{
    int b;
    Shape() {
        System.out.println("Shape Class");
        b=20;
    }
}

class rectangle extends Shape{
    int c;
   rectangle(){
       System.out.println("Rectangle Class");
       System.out.println("Value of a is: "+a);
       System.out.println("Value of b is: "+b);
   }
}

class Square extends Shape{
    int d;
    Square(){
        System.out.println("Square Class");
        System.out.println("Value of a is: "+a);
        System.out.println("Value of b is: "+b);
    }
}

class Circle extends Shape{
    int e;
    Circle(){
        System.out.println("Circle Class");
        System.out.println("Value of a is: "+a);
        System.out.println("Value of b is: "+b);
    }
}

class Ellipse extends Shape{
    int f;
   Ellipse(){
       System.out.println("Ellipse Class");
       System.out.println("Value of a is: "+a);
       System.out.println("Value of b is: "+b);
   }
}

class triangle extends Shape{
    int g;
     triangle(){
         System.out.println("Triangle Class");
         System.out.println("Value of a is: "+a);
         System.out.println("Value of b is: "+b);
     }
}

class polygon extends Shape{
    int h;
   polygon(){
       System.out.println("Polygon Class");
       System.out.println("Value of a is: "+a);
       System.out.println("Value of b is: "+b);
   }
}

public class Demonew {
    public static void main(String args[]){
          rectangle obj1=new rectangle();
          Square obj2=new Square();
          Circle obj3=new Circle();
          Ellipse obj4=new Ellipse();
          triangle obj5=new triangle();
          polygon obj6=new polygon();
    }
}
