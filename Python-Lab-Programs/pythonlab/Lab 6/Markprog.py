# -*- coding: utf-8 -*-
"""
Created on Tue May 10 21:13:47 2022

@author: HP
"""

import matplotlib.pyplot as plt
ans1=open("Keys.txt","r")
f=open("Mark.txt","r")

l1=[] # list of total marks
l2=[] # list of student names

ans=ans1.readline().split()

for line in f:
    t=line.split()
    name=t[0]
    l2.append(name)
    count=0
    
for x in range(1,len(ans)+1):
    
    if t[x]==ans[x-1]:    
        count+=1
l1.append(count)

print(name," Marks =",count,"/ 10")
i=l1.index(max(l1))
print("{0} got maximum marks {1}".format(l2[i], max(l1)) ) #place holders

c1=0
c2=0
c3=0

for i in range(len(l1)):
    if l1[i]==0 or l1[i]==1 or l1[i]==2:
        c1=c1+1
    if l1[i]==3 or l1[i]==4 or l1[i]==5 or l1[i]==6:
        c2=c2+1
    if l1[i]==7 or l1[i]==8 or l1[i]==9:
        c3=c3+1
        
l3=["0-2","3-6","7-10"]
l4=[c1,c2,c3]

plt.bar(l3,l4,width=0.50,color=["yellow","green","red"])
plt.show()
    
