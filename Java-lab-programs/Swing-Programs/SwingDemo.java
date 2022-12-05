package p1;

import javax.swing.*;

public class SwingDemo{
	SwingDemo(){
		JFrame jf=new JFrame("Swing app");
		jf.setSize(300,300);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel l=new JLabel("Simple swing app");
		jf.add(l);
		jf.setVisible(true);
	}
	
	public static void main(String args[]) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new SwingDemo();
			}
		});
	}
}
