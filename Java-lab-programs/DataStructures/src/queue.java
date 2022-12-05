import java.util.Scanner;

class demoqueue {
    Scanner s=new Scanner(System.in);
    private static final int QUEUE_SIZE=3;
    int front=0,rear=-1;
    int [] queue=new int[QUEUE_SIZE];

    void enqueue(){
        int item;
        if(rear==QUEUE_SIZE-1){
            System.out.println("Queue is full");
        }
        else{
            System.out.println("Enter the element that needs to be pushed into the queue: ");
            item=s.nextInt();
            rear++;
            queue[rear]=item;
            System.out.println("The element "+item+" is inserted into the queue");
        }
    }

    void dequeue(){
        int delitem;
        if(front>rear){
            System.out.println("Queue is empty!");
        }
        else{
            delitem=queue[front];
            front=front+1;
            System.out.println("The item deleted is :"+delitem);
        }
    }

    void display(){
        if(front>rear){
            System.out.println("Queue is empty!");
//            System.exit(0);
        }
        else{
            System.out.println("The elements present in queue are: ");
            for(int i=front;i<=rear;i++){
                System.out.print(queue[i]+" ");
            }
        }
    }
}

public class queue{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        demoqueue obj=new demoqueue();
        boolean flag=true;

        while(flag) {
            System.out.println("");
            System.out.println("Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
            int choice;
            choice = s.nextInt();
            switch (choice) {
                case 1:
                    obj.enqueue();
                    break;
                case 2:
                    obj.dequeue();
                    break;
                case 3:
                    obj.display();
                    break;
                default:
                    System.exit(0); //flag=false;
            }
        }
    }
}


