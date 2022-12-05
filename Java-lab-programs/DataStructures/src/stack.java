import java.util.Scanner;
class stackdemo {
    Scanner s=new Scanner(System.in);
    private static final int STACK_SIZE=3;
    int top=-1;
    int [] stack=new int[STACK_SIZE];

//    Push function
    void push(){
        int value;
        System.out.println("Enter the value that needs to be pushed into the stack:");
        value=s.nextInt();
        if(top==STACK_SIZE-1){
            System.out.println("Stack overflow!");
//            System.exit(0);
        }
        else{
            top=top+1;
            stack[top]=value;
        }
    }

//    Pop function
    void pop(){
        if(top==-1){
            System.out.println("Stack is underflow!");
//            System.exit(0);
        }
        else{
            System.out.println("Item deleted is: "+stack[top]);
            top=top-1;
        }
    }

//    Display function
    void display(){
        System.out.println("The elements present in the stack are: ");
        for(int i=0;i<=top;i++){
            System.out.print(stack[i]+" ");
        }
    }
}

public class stack{
    public static void main(String[] args){
         Scanner s=new Scanner(System.in);
         stackdemo obj=new stackdemo();
         boolean flag=true;

         while(flag){
             System.out.println("");
             System.out.println("Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
             int choice;
             choice=s.nextInt();
             switch(choice){
                 case 1:obj.push();
                        break;
                 case 2:obj.pop();
                        break;
                 case 3:obj.display();
                        break;
                 default:System.exit(0);
                        break;
             }
         }
    }
}