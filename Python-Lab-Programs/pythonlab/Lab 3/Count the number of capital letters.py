print("Enter the input string: ")
str=input()

list1=[]
list2=[]

for i in range(0,len(str)):
    if(str[i].isupper()):
        list1.append(str[i])
        list2.append(i)

print("Number of capital letters= ",len(list1))

print("Capital letter position: ")
for i in range(0,len(list1)):
    print(list1[i]," ",list2[i])