package p1;

import javax.swing.*;

public class SwingDemo1 extends JFrame{
	SwingDemo1(){
		super("Swing app");
		setSize(300,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JLabel l=new JLabel("Simple swing app");
		add(l);
		setVisible(true);
	}
	
	public static void main(String args[]) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new SwingDemo1();
			}
		});
	}
}
