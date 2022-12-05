/*
  A class named Arithmetic with a method named add that takes 2 integers as parameters and
  returns the sum of 2 numbers

  A class named Adder that inherits from a superclass named arithmetic

  Your classes should not be public
*/

package pack;

class Arithmetic{
    int sum(int a,int b){
        return (a+b);
    }
}

class adder extends Arithmetic{
    public static void main(String[] args){
        Arithmetic obj=new Arithmetic();
        int val=obj.sum(5,6);
        System.out.println("The sum is: "+val);
    }
}
