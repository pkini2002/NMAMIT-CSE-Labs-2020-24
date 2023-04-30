import socket
import os.path
# create a socket object
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# get local machine name
host = socket.gethostname()
print("Host name:",host)
port = 9999

# bind to the port
serversocket.bind((host,port))

# queue up to 5 requests
serversocket.listen(5)                                           

while True:
    # establish a connection
    clientsocket,addr=serversocket.accept()
    print("Got a connection from %s" % str(addr))
    f=clientsocket.recv(1024)
    if os.path.isfile(f):
      infile=open(f,"r")
      for line in infile:
         clientsocket.send(line.encode('ascii'))
      msg='Thank you for connecting'+ "\r\n"
      clientsocket.send(msg.encode('ascii'))
    else:
         f1="File doesn't exist"
         clientsocket.send(f1.encode('ascii'))  
    clientsocket.close()
