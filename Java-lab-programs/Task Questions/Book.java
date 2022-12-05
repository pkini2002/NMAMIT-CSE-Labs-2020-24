package pack;
import java.util.Scanner;

public class Book {
    int bookid,pages,price;
    Scanner s=new Scanner(System.in);

    void get(){
        System.out.println("Enter the book id: ");
        bookid=s.nextInt();
        System.out.println("Enter the number of pages: ");
        pages=s.nextInt();
        System.out.println("Enter the price: ");
        price=s.nextInt();
    }

    void show(){
        System.out.println("The book id is: "+bookid);
        System.out.println("Number of pages is: "+pages);
        System.out.println("Price of the book is: "+price);
    }

    void set(int bookid,int pages,int price){
        this.bookid=bookid;
        this.pages=pages;
        this.price=price;
    }

    int getPrice(){
        return price;
    }

    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int bookid,pages,price;
        Book obj=new Book();
        obj.get();
        obj.show();
        int value=obj.getPrice();
        System.out.println("Price is: "+value);

        System.out.println("Enter the book id: ");
        bookid=s.nextInt();
        System.out.println("Enter the number of pages: ");
        pages=s.nextInt();
        System.out.println("Enter the price: ");
        price=s.nextInt();
        obj.set(bookid,pages,price);
        obj.show();

    }
}
