marks_list={'John':86.5,'Jack':91.2,'Jill':84.5,'Harry':72.1,'Joe':80.5}

#Sorts dictionary in descending order
sorted_keys=sorted(marks_list,key=marks_list.get,reverse=True)

print("Top 3 students: ")

for student in sorted_keys[:3]:
    print(student," : ",marks_list[student])

#Average marks of the student
Sum=0
average=0
list=[]

for i in marks_list.values():
    list.append(i)
    Sum=sum(list)

#To find the length of the list
length=len(sorted_keys)

print("The average marks of the student is:")
average=Sum/length
print(average)
