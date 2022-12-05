list1=[] #List 1
list2=[] #List 2

n = int(input("Enter number of elements in list1 : "))

print("Enter the elements of list1:")
for i in range(n):
    element=int(input())
    list1.append(element)

print("Enter the elements of list2:")
for i in range(n):
    element=int(input())
    list2.append(element)

even1=0 #Count of even numbers in list1
even2=0 #Count of even numbers in list2
odd1=0 #Count of odd numbers in list1
odd2=0 #Count of odd numbers in list2

for i in range(0,n):
    if list1[i]%2==0:
        even1=even1+1
    else:
        odd1=odd1+1

for i in range(0,n):
    if list2[i]%2==0:
        even2=even2+1
    else:
        odd2=odd2+1

if(even1==even2 and odd1==odd2):
    print("Lists are Symmetrical")
else:
    print("Lists are not Symmetrical")



