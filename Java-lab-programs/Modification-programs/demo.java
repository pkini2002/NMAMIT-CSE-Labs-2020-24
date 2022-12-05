1. Write a java program to copy the content of each line of file into different files

package p1;

import java.io.*;
import java.util.*;

public class demo {
     public static void main(String args[]) throws FileNotFoundException {
              File f=new File("in1.txt");
              Scanner s=new Scanner(f);
              File fo;
              String fname;
              int num,count=0;
              PrintWriter p;
              while(s.hasNext()) {
            	  num=s.nextInt();
            	  fname="f"+(++count)+".txt";
            	  fo=new File(fname);
            	  p=new PrintWriter(fo);
            	  p.print(num);
            	  p.close();  
              }
     }
}
