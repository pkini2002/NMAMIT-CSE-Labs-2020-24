import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df=pd.read_csv('Lab161.csv')
print(df)

#Pandas function to select first columns
course_name=[]  #List to store course names
cie_see=[] #List to store CIE SEE marks

c=df.columns  #PExtracts all column names
print(c)
course=c[1:]  #Stores all columns except USN

for i in range(0,len(course),2):
    cie_cname=course[i]
    cname=cie_cname[:5]
    course_name.append(cname) #Appends the course name into the list
    
print(course_name)

ciec=df.iloc[:,1:12:2].mean(axis=0) #Selects all rows but alternate columns to select only CIE marks
siec=df.iloc[:,2:13:2].mean(axis=0) #Selects all rows but alternate columns to select only SEE marks

print(ciec)
print(type(ciec))  #Series
print(siec)
print(type(ciec))  #Series

for i in range(0,len(siec)):
    cie_see.append((ciec[i]+siec[i])/2)  #To find average marks of each course
    
print(cie_see)
    
i=cie_see.index(max(cie_see)) #Finds index with maximum marks
print(i)

print("Subject code {0} with highest score is {1}".format(course_name[i],max(cie_see)))


avg_marks_cie=df.iloc[:,1:12:2].mean(axis=1) #Selects all rows but alternate columns to select only CIE marks
avg_marks_see=df.iloc[:,2:13:2].mean(axis=1) 
usn=df.iloc[:,0] #Extracts Course names

print(avg_marks_cie)
print(avg_marks_see)

r=np.arange(10)
width=.4
fig=plt.figure(figsize=(10,5)) #To set the figure size
plt.bar(r,avg_marks_cie,width=.4,color="red",label="cie") #Bar1
plt.bar(r+width,avg_marks_see,width=.4,color="green",label="SEE") #Bar2
plt.xlabel("Students USN")
plt.ylabel("CIE VS SEE Score")
plt.xticks(r+width/2,usn)

plt.legend()
plt.title("Students Performance Avg CIE Vs Avg SEE")
plt.show()
