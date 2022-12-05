class Node{
    int data;
    Node ptr;
    Node(){
       data=0;
       ptr=null;
    }

    static void insert_rear(Node head,int item){
        Node newnode=new Node();
        newnode.data=item;
        newnode.ptr=null;

        if(head.ptr==null){
            head.ptr=newnode;
        }
        else{
            Node temp=new Node();
            temp=head;
            while(temp.ptr!=null){
                temp=temp.ptr;
            }
            temp.ptr=newnode;
        }
    }

    static void insert_front(Node head,int item){
        Node newnode=new Node();
        newnode.data=item;
        newnode.ptr=head.ptr;
        head.ptr=newnode;
    }

    static void remove_rear(Node head){
        Node temp=new Node();
        Node prev=new Node();
        temp=head;
        prev=null;
        if(head.ptr==null){
            System.out.println("List is empty");
        }
        else{
            while(temp.ptr != null){
                prev=temp;
                temp=temp.ptr;
            }
            prev.ptr=null;
        }
    }

    static void remove_front(Node head){
        Node temp=new Node();
        temp=head.ptr;
        if(head.ptr==null){
            System.out.println("List is empty");
        }
        else{
            head.ptr=temp.ptr;
        }
    }

    static void display(Node head){
        Node temp=new Node();
        temp=head.ptr;
        if(head.ptr==null){
            System.out.println("List is empty");
        }
        else{
            System.out.println("Elements in the list are: ");
            while(temp.ptr!=null){
                System.out.println(temp.data);
                temp=temp.ptr;
            }
            System.out.println(temp.data);
        }
    }
}

public class sll {
    public static void main(String[] args){
        Node list=new Node();
        System.out.println("Displaying empty list: ");
        Node.display(list);
        System.out.println("Remove rear from an empty list: ");
        Node.remove_rear(list);
        System.out.println("Linkedlist after adding 10,20,30 respectively");
        Node.insert_rear(list,10);
        Node.insert_rear(list,20);
        Node.insert_rear(list,30);
        Node.display(list);
        System.out.println("List after popping front element");
        Node.remove_front(list);
        Node.display(list);
        System.out.println("List after popping last element");
        Node.remove_rear(list);
        Node.display(list);
        System.out.println("List after inserting front element");
        Node.insert_front(list,5);
        Node.display(list);
    }
}
