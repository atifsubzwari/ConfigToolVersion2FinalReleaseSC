import os
import sys
import cantools
from pprint import pprint
import pdb
import numpy as np
import csv
db = cantools.database.load_file(sys.argv[1])
file1 = open(sys.argv[2]+'rx.txt','w')
from itertools import chain
t3=db.messages
receivers = []
send_recev = []
receivers1 = []
senders1 = []
s = "$"
for i in t3:
    i1 = i.signals
    sender = i.senders
    senders1.append(sender)
    for i2 in i1:
        #receivers.append((i.name,i2.receivers,i2.name))
        split = (i2.receivers)
        if len(split) == 1:
           for elem in split:
               receivers.append((i.name+' '+elem+' '+i2.name))
        if len(split)>1:
           for elem in split:
               receivers1.append((i.name+' '+elem+' '+i2.name))
for i in receivers:
    
    file1.write(i+'\n')
    
