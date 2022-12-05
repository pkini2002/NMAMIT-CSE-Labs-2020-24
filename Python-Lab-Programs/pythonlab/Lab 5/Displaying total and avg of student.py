fname=input("Enter the file name: ")
score=0

with open(fname,'r') as f:
    for line in f:
        list1=line.split()
        for i in range(len(list1)):
            score=score+int(list1[i])

        print("The sum of marks is: ",score)
        print("The average of marks is: ",score/len(list1))
        score=0