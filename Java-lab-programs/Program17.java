//UDP-Client

package p1;

import java.io.*;
import java.net.*;
import java.util.*;

public class udpclient {
    private static InetAddress host;
    private static final int PORT=1234;
    private static DatagramSocket datagramSocket;
    private static DatagramPacket inPacket,outPacket;
    private static byte[] buffer;
    
    public static void main(String args[]) throws IOException {
    	try {
    		host=InetAddress.getByName("127.0.0.1");
    	}catch(UnknownHostException uhex) {
    		System.out.println("Unknown Host ID");
    	}
    	
    	accessServer();
    	System.out.println("Closing Connection..");
    	datagramSocket.close();
    }
    
    private static void accessServer() throws IOException{
    	datagramSocket=new DatagramSocket();
    	String message,response;
    	Scanner s=new Scanner(System.in);
    	
    	do {
    		System.out.println("Enter the message: ");
    		message=s.nextLine();
    		if(!message.equals("CLOSE")) {
    		outPacket=new DatagramPacket(
    				   message.getBytes(),
    				   message.length(),
    				   host,
    				   PORT
    				);
    		datagramSocket.send(outPacket);
    		buffer=new byte[256];
    		inPacket=new DatagramPacket(buffer,buffer.length);
    		datagramSocket.receive(inPacket);
    		response=new String(inPacket.getData(),0,inPacket.getLength());
    		System.out.println("Server > "+response);		
    	   }
    	}while(!message.equals("CLOSE"));
    }
}

//Udp-server

package p1;

import java.io.*;
import java.net.*;
import java.util.*;

public class udpserver {
	private static final int PORT=1234;
    private static DatagramSocket datagramSocket;
    private static DatagramPacket inPacket,outPacket;
    private static byte[] buffer;
    
    public static void main(String args[]) throws IOException {
    	 try {
    		 datagramSocket=new DatagramSocket(PORT);
    	 }catch(SocketException soex) {
    		 System.out.println("Cannot connect to port");
    		 System.exit(1);
    	 }
    	 
    	 System.out.println("Ready to serve client..");
    	 handleclient();
    	 System.out.println("Closing connection...");
    	 datagramSocket.close();
    }
    
    private static void handleclient() throws IOException {
    	int nummessages=0;
    	String messageIn,messageOut;
    	do {
    		buffer=new byte[256];
    		inPacket=new DatagramPacket(buffer,buffer.length);
    		datagramSocket.receive(inPacket);
    		InetAddress clientaddress=inPacket.getAddress();
    		int port=inPacket.getPort();
    		messageIn=new String(inPacket.getData(),0,inPacket.getLength());
    		System.out.println("Message received");
            nummessages++;
            messageOut="Message "+nummessages+":"+messageIn;
            outPacket=new DatagramPacket(
 				   messageOut.getBytes(),
 				   messageOut.length(),
 				   clientaddress,
 				   port
 				);
            datagramSocket.send(outPacket);
    	}while(true);
    }  
}
