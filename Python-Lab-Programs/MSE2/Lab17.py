import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df= pd.read_csv("Lab171.csv")

# first sub question finding usn with highest total score
c_s=df.iloc[:,1:13].sum(axis=1)
#print(c_s)  
i=c_s.idxmax() # index 

print(i)
print("{0} is the Highest Scorer with {1} marks".format(df.iloc[i,0], max(c_s)))


# finding the grades
d2={'CS301':0,'CS302':0,'CS303':0,'CS304':0,'CS305':0,'CS306':0} # S grade count
d3={'CS301':0,'CS302':0,'CS303':0,'CS304':0,'CS305':0,'CS306':0} # A grade count
d4={'CS301':0,'CS302':0,'CS303':0,'CS304':0,'CS305':0,'CS306':0} # F grade count

for i in range(1,len(df.columns),2):
                  
    gd1=df.iloc[:,i:i+2].sum(axis=1)
   # print(gd1)# series  sum of see and cie    
    for j in range(0,10):
        if gd1.iloc[j]>=90:
            
            if i==1:
                d2['CS301']+=1
            if i==3:
                d2['CS302']+=1    
            if i==5:
                d2['CS303']+=1   
            if i==7:
                d2['CS304']+=1  
            if i==9:
                d2['CS305']+=1 
            if i==11:
                d2['CS306']+=1 
        elif gd1.iloc[j]>=80 and gd1.iloc[j]<90:
            
            if i==1:
                d3['CS301']+=1
            if i==3:
                d3['CS302']+=1    
            if i==5:
                d3['CS303']+=1   
            if i==7:
                d3['CS304']+=1  
            if i==9:
                d3['CS305']+=1 
            if i==11:
                d3['CS306']+=1 
        elif gd1.iloc[j]<40:
            
            if i==1:
                d4['CS301']+=1
            if i==3:
                d4['CS302']+=1    
            if i==5:
                d4['CS303']+=1   
            if i==7:
                d4['CS304']+=1  
            if i==9:
                d4['CS305']+=1 
            if i==11:
                d4['CS306']+=1 
       
# visualizing grade analysis
# drawing bar graph code here
r= np.arange(6)
width=.2
plt.figure(figsize = (10, 8))

plt.bar(r, d2.values(), width=.2,color  ="red", label="S")  # bar 1
plt.bar(r+width,d3.values(), width=.2,color  ="green", label="A") # bar 2
plt.bar(r+width+width,d4.values(), width=.2,color  ="blue", label="F") # bar 3
plt.xlabel("Courses")
plt.ylabel("No.of Students")
plt.xticks(r + width/1.1, d2.keys())
plt.legend()
plt.title("Students Performance Avg CIE vs Avg SEE")
plt.show()
