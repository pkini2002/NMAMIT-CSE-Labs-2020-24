print("Enter the string: ")
str=input()

count1=0
count2=0
count3=0
count4=0
count5=0

for i in range(len(str)):
    if(str[i]=='a' or str[i]=='A'):
        count1=count1+1
    if(str[i]=='e' or str[i]=='E'):
        count2=count2+1
    if(str[i]=='i' or str[i]=='I'):
        count3=count3+1
    if(str[i]=='o' or str[i]=='O'):
        count4=count4+1
    if(str[i]=='u' or str[i]=='U'):
        count5=count5+1

print(" Count of vowel a is: ",count1)
print(" Count of vowel e is: ",count2)
print(" Count of vowel i is: ",count3)
print(" Count of vowel o is: ",count4)
print(" Count of vowel u is: ",count5)


