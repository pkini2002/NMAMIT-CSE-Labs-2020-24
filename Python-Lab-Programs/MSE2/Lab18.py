import matplotlib.pyplot as plt
import pandas as pd

df= pd.read_csv("placement.csv",index_col=0)
#print(df)

# sub question 1
rowsum= df.iloc[:,0:].sum(axis=1)
#(rowsum)

i= rowsum.idxmax()
#print(i)
print( "Branch with highest placements is {0} with total {1} ".format( i,max(rowsum)))

# sub question 2 
colsum= df.iloc[:,0:].sum()
i1= colsum.idxmax()
print("Company with highest placement is {0}, with total {1}".format( i1,max(colsum)))

# subquestion 3
dct={}
num=df.iloc[:,0:].max(axis=1)
num=num.values
cname=df.iloc[:,0:].idxmax(axis=1)
print(cname)
cname=cname.values
dct['Company']=cname
dct['Number']=num.astype(int)

branchlist=df.index
df2=pd.DataFrame(dct,index=branchlist)
print(df2)

# pie chart  1
plt.figure(figsize=(7,7))
plt.pie(rowsum,labels=branchlist)
plt.show()

#pie chart 2
clist=df.columns
plt.figure(figsize=(7,7))
plt.pie(colsum,labels=clist.values)
plt.show()
