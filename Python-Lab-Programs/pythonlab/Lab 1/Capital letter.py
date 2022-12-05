s1=input("Enter string 1:")
s2=input("Enter string 2:")
s3=""

for i in range(0,len(s1)):
    if s1[i].isupper():
        s3=s3+s1[i]

for i in range(0,len(s2)):
    if s2[i].isupper():
        s3=s3+s2[i]

print("The merged string is:",s3)