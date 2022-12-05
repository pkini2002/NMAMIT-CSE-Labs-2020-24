// Simple program to demonstrate multilevel inheritance

package pack;

class class1{
    int a;
   class1(){
       a=5;
       System.out.println("This is the constructor of class 1");
   }
}

class class2 extends class1{
    int b;
    class2(){
        b=2;
        System.out.println("This is the constructor of class 2");
    }
}

class class3 extends class2{
    int c;
    class3(){
        c=10;
        System.out.println("This is the constructor of class 3");
    }

    void show(){
        System.out.println("Value of a is: "+a);
        System.out.println("Value of b is: "+b);
        System.out.println("Value of c is: "+c);
    }
}

public class Multilevel {
   public static void main(String args[]){
       class3 obj=new class3();
       obj.show();
   }
}
