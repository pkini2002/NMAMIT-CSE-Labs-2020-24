'''Write a function that returns the index of smallest element in a list of integers
If the number of such elements is greater than 1, return the smallest index. Use the following
header def indexOfSmallestElement(lst):
Write a program that prompts the user to enter a list of numbers, invokes this function to return the
index of the smallest element and displays the index.'''

def indexOfSmallestElement(lst):
    smallestIndex=0
    smallestElement=lst[0]

    for i in range(0,len(lst)):
        if lst[i]<smallestElement:
            smallestElement=lst[i]
            smallestIndex=i

    return smallestIndex


lst=[]
n=int(input("Enter the number of elements in the list: "))

print("Enter the elements of the list:")
for i in range(0,n):
    item=int(input())
    lst.append(item)



smallestIndex=indexOfSmallestElement(lst)
print("Smallest index is ",smallestIndex)