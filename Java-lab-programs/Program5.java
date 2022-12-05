// Write a java program that creates multiple threads. Main thread generates a random integer. First 
// child thread computes the square of next three the numbers and there should be idle time of one 
// second between displaying of each computed number. Second child thread computes the cube of 
// next three the numbers and there should be idle time of two seconds between displaying of each 
// computed number.


import java.util.Random;

class T1 extends Thread{
 int x;
  T1(int val){
      x=val;
  }

  public void run(){
      try {
          for (int i = 1; i <= 3; i++) {
              System.out.println((x + i) + ": " + Math.pow((x + i), 2));
              Thread.sleep(1000);
          }
      }catch(InterruptedException e){
          e.printStackTrace();
      }
  }
}

class T2 extends Thread{
    int x;
    T2(int val){
        x=val;
    }

    public void run(){
        try {
            for (int i = 1; i <= 3; i++) {
                System.out.println((x + i) + ": " + Math.pow((x + i), 3));
                Thread.sleep(2000);
            }
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}

public class Threadprog {
    public static void main(String args[]){
           Random rand=new Random();
           int x=rand.nextInt(11);
           System.out.println("x");
           T1 thread1=new T1(x);
           thread1.start();
           T2 thread2=new T2(x);
           thread2.start();
    }
}
