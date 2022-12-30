// 4.Write a JDBC program using sql queries to perform the following operations on a table
// Accounts. (Accounts Table consists of three fields namely Account Number, Name and Balance).
// i) Insert a record ii) Delete a record iii) Display all records

import java.util.*;
import java.sql.*;

class DBDemo{
    static Connection link;
    static Statement stm;
    static ResultSet rs;

    DBDemo() throws SQLException{
        try{
            Class.forName("com.mysql.jdbc.Driver");
          
            //College lab connection
           // link=DriverManager.getConnection("jdbc:mysql://172.16.2.3/student","student","student");
          
            //My system connection
            link=DriverManager.getConnection("jdbc:mysql://localhost:4306/student","root","1234");
        }
        catch(ClassNotFoundException cnfEx){
            System.out.println("The driver class cannot be found!");
            System.exit(1);
        }
        catch(SQLException sqlex){
            System.out.println("Cannot connect to database");
        }
        stm=link.createStatement();
    }

    void insertinfo() throws SQLException{
        String fname,surname;
        int accno,balance;
        System.out.println("Enter the fname: ");
        Scanner s=new Scanner(System.in);
        fname=s.nextLine();
        System.out.println("Enter the surname: ");
        surname=s.nextLine();
        System.out.println("Enter the accno: ");
        accno=s.nextInt();
        System.out.println("Enter the balance: ");
        balance=s.nextInt();

        int r1=0;

        try{
            String s1 = "insert into accounts values("+accno+",'"+fname+"','"+surname+"',"+balance+")";
            r1=stm.executeUpdate(s1);
        }catch(Exception e){
            System.out.println(e);
        }
        System.out.println(r1 + " rows affected!");
    }

    void deleteinfo() throws SQLException{
        Scanner s1=new Scanner(System.in);
        System.out.println("Enter the accno: ");
        int acc=s1.nextInt();
        String s2="DELETE FROM accounts where accno = "+acc;
        stm.executeUpdate(s2);
        System.out.println("Row deleted successfully!");
    }

    void closecon() throws SQLException
    {
        rs.close();
        stm.close();
        link.close();
    }


    void displayinfo() throws SQLException{
        String s="SELECT * FROM accounts";
        rs=stm.executeQuery(s);

        while(rs.next()){
            System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getString(3)+" "+rs.getInt(4));
        }
    }
}

public class JDBCDemo {
   public static void main(String args[]) throws SQLException{
       Scanner s=new Scanner(System.in);
       DBDemo obj=new DBDemo();
       boolean flag=true;
       int choice;

       while (flag) {
           System.out.println("Enter your choice: \n 1.Insert\t2.Delete\t3.Display\t4.Exit\t");
           choice = s.nextInt();
           switch (choice){
               case 1:obj.insertinfo();
                      break;
               case 2:obj.deleteinfo();
                      break;
               case 3:obj.displayinfo();
                      break;
               case 4:flag=false;
           }
       }
       obj.closecon();
   }
}
