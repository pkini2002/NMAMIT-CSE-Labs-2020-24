import socket

# create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

# get local machine name
host = socket.gethostname()                           
print("Host name:",host)
port = 9999

# connection to hostname on the port.
s.connect((host,port))                               

f1=input("Enter the file name:")

s.send(f1.encode('ascii'))
# Receive no more than 1024 bytes
msg = s.recv(1024)                                     

s.close()

print (msg.decode('ascii'))
