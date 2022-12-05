# -*- coding: utf-8 -*-
"""
Created on Tue May 10 21:06:29 2022

@author: HP
"""

#simple graph
import matplotlib.pyplot as plt
xpoints=[0,6]
ypoints=[0,250]
plt.plot(xpoints,ypoints)
plt.show()

#Bar graph
x=[1,2,3,4,5,6]
y=[9,12,8,13,6,9]
plt.bar(x,y,color=["red","green","blue","yellow","brown","pink"])
plt.show()

#bargraph-multiple
import matplotlib.pyplot as plt
import numpy as np
r=np.arange(6)
width=.4
x=[7,6,4,14,12,15]
y=[9,12,8,13,6,9]
plt.bar(r,x,width=.4,color="blue",label="India")
plt.bar(r+width,y,width=.4,color="yellow",label="Australia")
plt.xlabel("No. of overs")
plt.ylabel("No. of runs scored")
plt.xticks(r+width/2,[1,2,3,4,5,6]) #givesnot in the middle of each graph
plt.legend()
plt.title("Score comparition")
plt.show()