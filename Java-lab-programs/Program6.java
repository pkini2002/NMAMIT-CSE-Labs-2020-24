//6. Develop a set of methods, which work with an integer array. The methods to be implemented are:-
//  (i) min (which finds the minimum element in the array)
//  (ii)scale.(Multiply the array elements by suitable scale factor)
//   Place this in a package called p1. Write a main method in a separate file (Driver Class) to use the
//   methods of package p1

package p1;

public class method {
    public int min(int arr[]){
        int temp=arr[0];
        for(int i=1;i<arr.length;i++){
            if(arr[i]<temp){
                temp=arr[i];
            }
        }
        return temp;
    }
    public void scale(int arr[],int k){
        for(int i=0;i< arr.length;i++){
            arr[i]*=k;
        }
    }
}

// Write the below code in other package
import p1.method;
import java.util.Scanner;

public class packageprog {
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int n;
        System.out.println("Enter the value of n: ");
        n=s.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++){
            int val=s.nextInt();
            arr[i]=val;
        }
        method m=new method();
        System.out.println("The minimum element present in the array is: "+m.min(arr));
        System.out.println("Enter the scale factor: ");
        int k=s.nextInt();
        m.scale(arr,k);
        System.out.println("Resulting array is: ");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}

