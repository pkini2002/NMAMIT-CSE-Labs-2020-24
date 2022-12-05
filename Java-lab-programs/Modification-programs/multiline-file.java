2. Write a file program to copy the contents of file into different files in multiples of 1,2 or 3

package p1;

import java.io.*;
import java.util.*;

public class demo1 {
	 public static void main(String args[]) throws IOException {
		 File f=new File("in2.txt");
		 Scanner s=new Scanner(f);
		 File fo;
		 int count=1;
		 String fname;
		 String num="";
		 while(s.hasNext()) {
			 fname="g"+count+".txt";
			 fo=new File(fname);
			 num="";
			 
			 for(int i=0;i<count;i++) {
				num=num+s.nextLine()+"\n";
				FileWriter p=new FileWriter(fo);
				p.write(num);
				p.close();  
		    }
			 count++;
		 }
		 s.close();
	 }
}
