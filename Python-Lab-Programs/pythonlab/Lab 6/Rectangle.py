# -*- coding: utf-8 -*-
"""
Created on Tue May 10 21:02:24 2022

@author: HP
"""

class Rectangle:
    def __init__(self,width,height):
        self.w=width
        self.h=height
        
    def getArea(self):
        return(self.w*self.h)
        
    def display(self):
        print("Height is: ",self.h)
        print("Width is: ",self.w)

n=int(input("Enter the number of Rectangle objects: "))
list1=[] #Storing rectangle objects
list2=[] #Storing area

for i in range(n):
    width=int(input("Enter the width : "))
    height=int(input("Enter the height: "))
    list1.append(Rectangle(width,height))
    list1[i].display()
    list2.append(list1[i].getArea())
    print("Area of rectangle is: ",list2[i])
    
i_max=list2.index(max(list2))
i_min=list2.index(min(list2))
print("The maximun width and height of rectangle is: ",list1[i_max].w,list1[i_max].h)
print("The minimum width and height of rectangle is: ",list1[i_min].w,list1[i_min].h)
