/* Write a Swing program to create frame window and three text fields to input three floating point
    numbers from the user and displays sum, average and largest of these three numbers in a dialog box. */

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class swingprog implements ActionListener{
    JTextField tf1,tf2,tf3;
    JButton jb1,jb2,jb3;
    JFrame jf;
    swingprog(){
        jf=new JFrame("Calulations");
        jf.setSize(300,300);
        jf.setLayout(new FlowLayout());

        tf1=new JTextField(20);
        tf2=new JTextField(20);
        tf3=new JTextField(20);
        jf.add(tf1);
        jf.add(tf2);
        jf.add(tf3);

        jb1=new JButton("Sum");
        jb1.addActionListener(this);
        jf.add(jb1);

        jb2=new JButton("Average");
        jb2.addActionListener(this);
        jf.add(jb2);

        jb3=new JButton("Largest");
        jb3.addActionListener(this);
        jf.add(jb3);

        jf.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        double a=Double.parseDouble(tf1.getText());
        double b=Double.parseDouble(tf2.getText());
        double c=Double.parseDouble(tf3.getText());
        double largest;

        if(e.getActionCommand()=="Sum"){
            JOptionPane.showMessageDialog(null,a+b+c);
        }

        else if(e.getActionCommand()=="Average"){
            JOptionPane.showMessageDialog(null,a+b+c/3);
        }
        else{
            if(a>b && a>c){
                largest=a;
            }
            else if(b>a && b>c){
                largest=b;
            }
            else{
                largest=c;
            }
            JOptionPane.showMessageDialog(null,largest);
        }
    }

    public static void main(String args[]){
        new swingprog();
    }
}
