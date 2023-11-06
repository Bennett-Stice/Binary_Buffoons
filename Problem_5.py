# -*- coding: utf-8 -*-
"""
Created on Mon Nov  6 12:23:00 2023

@author: bennett stice
"""
import copy

def  transition (orig):
        copy_list=copy.deepcopy(orig)
        forwards=copy.deepcopy(orig)
        backwards=[]
        follow=[]
        
        j=len(orig)-1
        for i in range (0,len(orig)):
            forwards[i].insert(0,0)
            backwards.append(copy_list[j])
            backwards[i].insert(0,1)
            j-=1
        follow+=forwards
        follow+=backwards
        return follow

grayCodeList=[[[0],[1]]]
print ("Gray Code 1 Bit: ", grayCodeList[0])
endBitNum=3;
for i in range (1,endBitNum):
    grayCodeList.append(transition(grayCodeList[i-1]))
    print ("Gray Code " + str(i) + " Bit: ", grayCodeList[i])

