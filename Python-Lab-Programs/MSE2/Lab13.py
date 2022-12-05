class account:
   
    def _init_(self,acno):
        self.__bal=100  # private 
        self.__acno=acno
        
    def deposit(self,dp):
        self.__bal+=dp
        
    def withdraw(self,wd):
        if self.__balance-wd>=100:
           self._balance=self._balance-wd
           print("Balance is",self.__balance)
        else:
           print("Cannot withdraw")
            
    def getbalance(self):
        return self.__bal    
 
    def getaccountno(self):
        return  self.__acno
 
L1=[]  #  To store Objects
L2=[]  #  to store Acctno
L3=[]  #  to store Balance

f=True
while f:
    print("1-Create\n2-Deposit\n3-Withdraw\n4-Disp_max\n5-Exit\n")
    
    ch=int(input(""))
    if ch==1:
        acno=int(input("Enter the acno:\n"))
        if acno in L2:
            print("account already present\n")
        else:
            L1.append(account(acno))     
            L2.append(acno)
            
    if ch==2:
        try:
            acno=int(input("Enter the account no.:\n"))
            bal=float(input("Enter the balance to be deposited:\n"))
            i=L2.index(acno)
            L1[i].deposit(bal)
            
        except:
            print("Account no. not found")
            
    if ch==3:
        try:
            acno=int(input("Enter account no:\n"))
            bal=float(input("Enter the balance to be withdrawn:\n"))
            i=L2.index(acno)
            L1[i].withdraw(bal)
            
        except:
            print("Account no. not found")
    
    if ch==4:
        if len(L1)==0: # to check list is empty
            print("No account ,Please create account :")
        else:
            for i in L1:
           
                L3.append(i.getbalance())
            j=L3.index(max(L3))   
            print("The acno. with maximum balance:",L1[j].getaccountno())
        
            L3=[]
    if ch==5:
        f=False
