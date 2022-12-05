# Generating fibonacci series  upto n numbers
t1 = 0
t2 = 1
num = int(input("Enter the value of n:"))

if num <= 0:
    print("Invalid Input")

elif num == 1:
    print(t1)

else:
    for i in range(num):
        t3 = t1 + t2
        print(t1)
        t1 = t2
        t2 = t3