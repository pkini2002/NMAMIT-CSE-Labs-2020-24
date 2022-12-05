#Write a binary search function which searches an item in a sorted list. The function should
# return the index of element to be searched in the list

def binarySearch(item,list):
    low=0
    high=len(list)-1
    mid=0

    while (low<=high):
        mid=(high+low)//2

        if(list[mid]<item):
            low=mid+1

        elif(list[mid]>item):
            high=mid-1

        else:
            return mid
    return -1

#Defining a sorted list
list=[1,5,10,56,89]

#Asking the user to input an item
print("Enter the item to be searched in the list:")
item=int(input())

#Function call
result=binarySearch(item,list)

if result!=-1:
    print("Element is present at index",str(result+1))

else:
    print("Element is not present in the list")
