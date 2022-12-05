# Factorial of a given number
fact = 1
num = int(input("Enter the number:"))

if num < 0:
    print("Invalid input")

for i in range(1, num + 1):
    fact *= i;

print(fact)