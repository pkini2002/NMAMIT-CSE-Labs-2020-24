package pack;

abstract class exam{
    int marks;
    abstract void total_marks();
}

class task extends exam{
      task(){
          marks=10;
      }

      void total_marks(){
          System.out.println("Task marks: "+marks);
      }
}

class mse extends exam{
   mse(){
       marks=40;
   }

    void total_marks(){
        System.out.println("MSE marks: "+marks);
    }
}

class see extends exam{
    see(){
        marks=50;
    }
    void total_marks(){
        System.out.println("SEE marks: "+marks);
    }
}

public class test {
    public static void main(String args[]){
        task obj1=new task();
        obj1.total_marks();
        mse obj2=new mse();
        obj2.total_marks();
        see obj3=new see();
        obj3.total_marks();
    }
}
