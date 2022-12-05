test=str(input("Enter the name of the file which you want to manipulate: "))

file = open(test, "r")

Lines = file.readlines()
count = 0

for line in Lines:
    count = 0
    sum_number = 0
    for i in line.split(' '):
        count += 1
        sum_number += int(i)
    print("The total marks obtained by student is: ",sum_number)
    print("The average marks obtained by the student is: ",sum_number/count)


file.close()