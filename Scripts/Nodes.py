import os
import sys
import cantools
from pprint import pprint
import numpy as np
from collections import defaultdict
from itertools import groupby 
db = cantools.database.load_file(sys.argv[1])
print(sys.argv[1])
file1 = open(sys.argv[2]+'.txt','w')
t3=db.nodes
nodenames=[]
res = {} 
resRx = {} 
t4=db.messages
totalmessages=[]
nodemessages=[]
for i in t3:
     nodenames.append(i.name)

for j in t4:
    totalmessages.append(j.name)
def list_contains(nodenames, totalmessages): 
    nodemessages=[]
    for m in nodenames:
        for n in totalmessages:
            if m in n:
                nodemessages.append(n)
                continue
                return nodemessages
    return nodemessages
zz=list_contains(nodenames, totalmessages)
zz.sort()
for key in nodenames:
    res[key]=[]
    for value in zz:
        if key in value:
            res[key].append(value)
        else:
            continue

2 c xxz 
file1.write("\n")
file1.write(str(res))




    
                                        
