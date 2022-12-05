//Create a Swing that is having a List View to select the city, Text box to enter the name,
// phone number. Radio button to choose the gender and check box to choose hobbies. Create an
// alert to display the selections made by the user

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;

public class swingnew implements ListSelectionListener,ItemListener,ActionListener {
    JScrollPane jsp;
    JCheckBox c1,c2,c3;
    JRadioButton r1,r2;
    JTextField t1,t2;
    String[] cities={"Mlore","Blore","Mysuru","Madikeri","Udupi","Bhatkal","Puttur","Sullia"};
    JList<String>jlist=new JList<String>(cities);
    ArrayList<String>hobbies=new ArrayList<String>();

    swingnew(){
        JFrame jf=new JFrame("Swing app");
        jf.setSize(300,300);
        jf.setLayout(new FlowLayout());
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel l1=new JLabel("Name: ");
        t1=new JTextField(20);
        JLabel l2=new JLabel("Phone number: ");
        t2=new JTextField(20);
        jf.add(l1);
        jf.add(t1);
        jf.add(l2);
        jf.add(t2);

        jlist.addListSelectionListener(this);
        jsp=new JScrollPane(jlist);
        jsp.setPreferredSize(new Dimension(100,100));
        jf.add(jsp);

        r1=new JRadioButton("Male");
        r1.addActionListener(this);
        r2=new JRadioButton("Female");
        r2.addActionListener(this);
        ButtonGroup bg=new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        jf.add(r1);
        jf.add(r2);

        c1=new JCheckBox("Chess");
        c1.addItemListener(this);
        c2=new JCheckBox("Reading");
        c2.addItemListener(this);
        c3=new JCheckBox("Playing");
        c3.addItemListener(this);

        jf.add(c1);
        jf.add(c2);
        jf.add(c3);

        JButton sub=new JButton("Submit");
        sub.addActionListener(this);
        jf.add(sub);
        jf.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
         String val=e.getActionCommand();
         String city,name,number,gender = null;
         if(e.getActionCommand()=="Submit"){
              city=jlist.getSelectedValue();
              name=t1.getText();
              number=t2.getText();

              if(r1.isSelected())
                  gender=r1.getActionCommand();
              else if(r2.isSelected())
                  gender=r2.getActionCommand();

              if(c1.isSelected())
                  hobbies.add(c1.getActionCommand());
              if(c2.isSelected())
                 hobbies.add(c2.getActionCommand());
              if(c3.isSelected())
                 hobbies.add(c3.getActionCommand());

              String res="Name: "+name+"\n Number: "+number+"\n Gender: "+gender+"\n Hobbies: ";
              for(String s:hobbies)
                  res+=s;

              JOptionPane.showMessageDialog(null,res);
         }
    }

    @Override
    public void itemStateChanged(ItemEvent e) {

    }

    @Override
    public void valueChanged(ListSelectionEvent e) {

    }

    public static void main(String args[]){
        new swingnew();
    }
}
