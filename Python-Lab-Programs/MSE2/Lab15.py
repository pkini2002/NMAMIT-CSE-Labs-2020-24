class Country():
    def init(self):
        self.name = " "
        self.capital = "  "
        self.pop = 0

    def readdetails(self):
        self.name = input("Enter the country name:")
        self.capital = input("Enter capital :")
        self.pop = int(input("Enter population:"))

    def printdetails(self):
        print("Details:", self.name, " ", self.capital, " ", self.pop)


countrylist = []


def addnewcountry():
    cobj = Country()
    cobj.readdetails()
    countrylist.append(cobj)


def printcountrydetails():
    cname = input("Enter the country name")
    cfound = False
    for obj in countrylist:
        if obj.name == cname:
            obj.printdetails()
            cfound = True
    if cfound == False:
        print("Country", cname, "is not found")


def printcountryhighpop():
    highpopulation = countrylist[0]
    for cobj in countrylist:
        if(highpopulation.pop < cobj.pop):
            highpopulation = cobj
    highpopulation.printdetails()


t = True
while(t):
    print("Enter 1 for creating new country")
    print("Enter 2 for  country name")
    print("Enter 3 for conytry name of highest ppulation")
    userchoice = int(input("Enter your choice"))

    if(userchoice == 1):
        addnewcountry()
    elif(userchoice == 2):
        printcountrydetails()
    elif(userchoice == 3):
        printcountryhighpop()
    else:
        t = False
