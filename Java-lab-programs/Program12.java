//Write a Java program to perform the following operations
//        in a Random Access File (assume three fields).
//        i) Insert a record ii) Display a record


import java.io.*;
import java.util.*;


public class randaccess {
    private static final int REC_SIZE=42;
    private static final int NAME_SIZE=15;
    private static RandomAccessFile ranFile;

    public static void main(String args[]) throws IOException {
        ranFile=new RandomAccessFile("acc.dat","rw");
        writeRecord(1000,"Demo",1000);
        showRecords();
    }

    public static void writeRecord(long accno,String name,float balance) throws IOException {
        long pos = ranFile.length();
        ranFile.seek(pos);
        ranFile.writeLong(accno);
        writeString(name,NAME_SIZE);
        ranFile.writeFloat(balance);
    }

    public static void writeString(String name,int size) throws IOException {
        int len = name.length();
        if(len<size){
            ranFile.writeChars(name);
            for(int i=len;i<size;i++)
                ranFile.writeChar(' ');
        }else{
            ranFile.writeChars(name.substring(0,size));
        }
    }

    public static void showRecords() throws IOException {
        long n = ranFile.length()/REC_SIZE;
        ranFile.seek(0);
        for(int i=0;i<n;i++){
            long accno = ranFile.readLong();
            String name = readString(NAME_SIZE);
            float bal = ranFile.readFloat();
            System.out.println(accno+" "+name+" "+bal);
        }
    }
    public static String readString(int size) throws IOException {
        String res = "";
        for(int i=0;i<size;i++)
            res+=ranFile.readChar();
        return res;
    }
}
