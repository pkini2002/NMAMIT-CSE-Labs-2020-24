3. Write a file program that copies the content from previous file to print "Hellogoodmorning"

package p1;

import java.io.*;
import java.util.*;

public class demo2{
   public static void main(String args[]) throws FileNotFoundException {
	   File f1=new File("a1.txt");
	   File f2=new File("a2.txt");
	   File f3=new File("a3.txt");
	   
	   PrintWriter p;
	   p=new PrintWriter(f1);
	   p.print("Hello");
	   p.close();
	   
	   Scanner sc=new Scanner(f1);
	   String s;
	   sc=new Scanner(f1);
	   s=sc.nextLine();
	   
       p=new PrintWriter(f2);
       p.print(s+"good");
       p.close();
       
       sc=new Scanner(f2);
       s=sc.nextLine();
       p=new PrintWriter(f3);
       p.print(s+"morning");
       p.close();
       
       sc=new Scanner(f3);
       s=sc.nextLine();
       System.out.println(s);
       
       sc.close();
       
   }
}
