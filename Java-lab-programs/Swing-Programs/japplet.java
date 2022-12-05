package p1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Japplet extends JApplet {
	
	    public void init() {
	    	try {
	    		SwingUtilities.invokeLater(new Runnable() {
	        		public void run() {
	        			makeGUI();
	        		}
	        	});
	    	}catch(Exception e) {
	    		System.out.println("Could not create"+e);
	    	}
	    }
    
    	private void makeGUI() {
    		JFrame jf=new JFrame("Button demo");
        	jf.setSize(300,100);
        	jf.setLayout(new FlowLayout());
        	jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        	
        	JButton b1=new JButton("Button 1");
        	JButton b2=new JButton("Button 2");
        	JLabel l=new JLabel("Press a button");
        	
        	b1.addActionListener(new ActionListener() {
        		public void actionPerformed(ActionEvent e) {
        			l.setText("Button 1 was clciked");
        		}
        	});
        	
        	b2.addActionListener(new ActionListener() {
        		public void actionPerformed(ActionEvent e) {
        			l.setText("Button 2 was clciked");
        		}
        	});
        	
        	jf.add(b1);
        	jf.add(b2);
        	jf.add(l);
        	
        	jf.setVisible(true);

    	}
}
