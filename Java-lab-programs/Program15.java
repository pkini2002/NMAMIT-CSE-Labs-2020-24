// 15.Write a JDBC program using Java methods to perform the following operations on a table
// Called Student. (Student Table consists of two fields namely Roll number and Name of the
// Student).
// i) Insert a record ii) Update a Record iii) Search the name of a given USN.

import java.util.*;
import java.sql.*;

class DdDemo{
    static Connection link;
    static ResultSet rs;
    static Statement stm;

    DdDemo() throws SQLException{
        try{
            Class.forName("com.mysql.jdbc.Driver");
            link=DriverManager.getConnection("jdbc:mysql://localhost:4306/student","root","1234");
        }
        catch (ClassNotFoundException cnfEx){
            System.out.println("Cannot load driver manager");
            System.exit(1);
        }
        catch (SQLException sqlex){
            System.out.println("Cannot connect to database");
            System.exit(1);
        }
        stm=link.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        rs=stm.executeQuery("SELECT * from st");
    }

    void insertinfo() throws SQLException{
        String name;
        int rollno;
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the name: ");
        name=s.next();

        System.out.println("Enter the rollno: ");
        rollno=s.nextInt();

        rs.moveToInsertRow();
        rs.updateInt("rollno",rollno);
        rs.updateString("name",name);
        rs.insertRow();
    }

    void deleteinfo(int r) throws SQLException{
        rs.absolute(r);
        rs.deleteRow();
    }

    void updateinfo(int r) throws SQLException{
        rs.absolute(r);
        String name;
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the new name");
        name=s.nextLine();
        rs.updateString("name",name);
        rs.updateRow();
    }

    void search(int r) throws SQLException{
        String s1="SELECT * from st";
        rs=stm.executeQuery(s1);
        int pos=0;
        while(rs.next()){
            if(r==rs.getInt(1)){
                pos=1;
                break;
            }
        }
        if(pos==0){
            System.out.println("Search unsuccessful");
        }
        else{
            System.out.println("Search successful");
        }
    }
}

public class JDBDemo {
    public static void main(String args[]) throws SQLException {
        Scanner s = new Scanner(System.in);
        boolean flag = true;
        int choice;
        DdDemo obj = new DdDemo();
        int r;
        while (flag) {
            System.out.println("Enter the choice: \n1.Insert\t2.Delete\t3.Update\t4.Search\t5.Exit");
            choice = s.nextInt();


            switch (choice) {
                case 1:
                    obj.insertinfo();
                    break;
                case 2:
                    System.out.println("Enter the row to be deleted: ");
                    r = s.nextInt();
                    obj.deleteinfo(r);
                    break;
                case 3:
                    System.out.println("Enter the row to be updated: ");
                    r = s.nextInt();
                    obj.updateinfo(r);
                    break;
                case 4:
                    System.out.println("Enter the value to be searched: ");
                    r = s.nextInt();
                    obj.search(r);
                    break;
                case 5: flag = false;
            }
        }
    }
}
