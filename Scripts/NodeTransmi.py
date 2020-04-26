import os
import sys
import cantools
from pprint import pprint
import pdb
import numpy as np
import csv
db = cantools.database.load_file(sys.argv[1])
file1 = open(sys.argv[2]+'tx.txt','w')
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
        sender = i.senders
        senders1.append(sender)
        receivers1.append((str(i.name) +' '+ str(i.senders)+' '+str(i2.name)))
for elem in receivers1:
    write = (elem.replace('[','').replace(']',''))
    write = (write.replace("'",""))
    file1.write(write+'\n')