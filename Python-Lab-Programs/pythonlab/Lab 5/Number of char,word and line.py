fname=input("Enter a file name: ")

nl=nw=nc=0

with open(fname,'r') as f:
    for line in f:
        nl=nl+1
        words=line.split()
        nw=nw+len(words)
        for word in words:
            nc=nc+len(word)

print("Number of lines is ",nl)
print("Number of words is ",nw)
print("Number of characters is ",nc)
