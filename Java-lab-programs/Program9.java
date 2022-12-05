//Write a multithread java program to display the message [Welcome] [To][Java] by three separate child threads using the concept of synchronization

class First extends Thread{
    public void display(String msg){
        System.out.print("["+msg);
        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.print("]");
    }
}

class Second extends Thread{
    First fobj;
    String msg;
    Second(First fp,String msg){
        this.fobj=fp;
        this.msg=msg;
        start();
    }
   public void run(){
        synchronized (fobj){
            fobj.display(msg);
        }
   }
}

public class multithread {
  public static void main(String args[]){
      First fobj=new First();
      Second s1=new Second(fobj,"Welcome");
      try{
          s1.join();
      }catch (InterruptedException e){
          e.printStackTrace();
      }

      Second s2=new Second(fobj,"To");
      try{
          s2.join();
      }catch (InterruptedException e){
          e.printStackTrace();
      }

      Second s3=new Second(fobj,"Java");
      try{
          s3.join();
      }catch (InterruptedException e){
          e.printStackTrace();
      }
  }
}
