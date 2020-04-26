import os
import sys
import cantools
from pprint import pprint
import pdb

import csv
import binascii
db = cantools.database.load_file(sys.argv[1])
from itertools import chain
t3=db.messages
t4=db.nodes
message_nodes=[]
Txmessage_names=[]
nodesenders=[]
Txmessagenmes={}
Rxframeid={}
Urxmessages=[]
Urxmessagesframeid=[]
signa=[]
msgsender=[]
msgsignals={}



####### Network Node names  ##############
txt_file = open(sys.argv[2]+'.txt','w')
nodenames=[]
for i in t4:
    nodenames.append(i.name)
txt_file.write(str(nodenames)+'\n')
#### Tx message name, Tx node names####
Names = []
senders1 = []
Trns_final={}
for i in t3:
    Names.append(i.name)
    i1 = i.signals
    sender = i.senders
    senders1.append(sender)
    sender_1 = list(chain.from_iterable(senders1))
Trns =dict(zip(Names,sender_1))
for key, value in Trns.items(): 
   if value in Trns_final: 
       Trns_final[value].append(key) 
   else: 
       Trns_final[value]=[key] 
for i in Trns_final: 
    pass
txt_file.write(str(Trns_final)+'\n')
#### Rx message name, Rx node name ####
data = []
for i in t3:
    i1 = i.signals
    for elem in i1:
        data.append([i.name,elem.receivers])
txt_file.write((str(data)+'\n'))
#### Tx Message name , Tx frame id ####
messagename=[]
messageframeid=[]
Txframeid={}
for i in t3:
    messagename.append(i.name)
    
    messageframeid.append(hex(i.frame_id))
Txframeid=dict(zip(messagename,messageframeid))
txt_file.write(str(Txframeid)+'\n')
#### Tx Message name, Tx DLC ####
dlcmessagename=[]
dlc=[]
Txdlc={}
for i in t3:
    dlcmessagename.append(i.name)
    dlc.append(i.length)
Txdlc=dict(zip(dlcmessagename,dlc))
txt_file.write(str(Txdlc)+'\n')
#### Rx Message name, Rx DLC ####
dlcmessagename=[]
dlc=[]
Rxdlc={}
for i in t3:
    dlcmessagename.append(i.name)
    dlc.append(i.length)
Rxdlc=dict(zip(dlcmessagename,dlc))
txt_file.write(str(Rxdlc)+'\n')
#### Tx Message name, Tx Method ####
Txmessagename=[]
TxMethod=[]
Txmethodtyp={}

for i in t3:
    Txmessagename.append(i.name)
    TxMethod.append(i.send_type)
Txmethodtyp=dict(zip(Txmessagename,TxMethod))
txt_file.write(str(Txmethodtyp)+'\n')
####Rx Message name, Rx Method ####
Rxmessagename=[]
RxMethod=[]
Rxmethodtyp={}

for i in t3:
    Rxmessagename.append(i.name)
    RxMethod.append(i.send_type)
Rxmethodtyp=dict(zip(Rxmessagename,RxMethod))
txt_file.write(str(Rxmethodtyp)+'\n')
    
#### Tx Message name, Tx Cyclic time ####
Cymessagename=[]
TxCycletime=[]
Txcycletme={}


for i in t3:
    Cymessagename.append(i.name)
    TxCycletime.append(i.cycle_time)
Txcycletme=dict(zip(Cymessagename,TxCycletime))
txt_file.write(str(Txcycletme)+'\n')

#### Tx Message name , Tx Signals####
data4 = []
data5 = []
for i in t3:
    i1 = i.signals
    name = (i.name)
    data = []
    data1 =[]
    data4.append(i.name)
    data5.append(i.signal_tree)
TXframe =dict(zip(data4,data5))

txt_file.write(str(TXframe)+'\n')

#### Rx Message name, Rx Frame id #### 
Namesm1=[]
receive_msg_frameid = []
sendersm1 = []
for i in t3:
    im1 = i.signals
    senderm = i.senders
    sendersm1.append(senderm)
    for im2 in im1:
        splitm1 = (im2.name)
        Namesm1.append(i.name)
        receive_msg_frameid.append(hex(i.frame_id))
RXframeid=dict(zip(Namesm1,receive_msg_frameid))
txt_file.write(str(RXframeid)+'\n')
#### Tx Message name, Tx Signal name, Tx Initial Value ####
Intials = []
Namesm1=[]
Rxns_init={}
for i in t3:
    i1 = i.signals
    data = []
    data1 = []
    data.append(i.name)
    for i2 in i1:
        data1.append(i2.name)
        data1.append(i2.initial)
    Rxns_init.update({i.name:data1})
txt_file.write(str(Rxns_init)+'\n')
#### Tx Message name, Tx Is Extended #####
Extended_frame = []
Namesm1=[]
for i in t3:
    Namesm1.append(i.name)
    Extended_frame.append(int(i.is_extended_frame))
output =dict(zip(Namesm1,Extended_frame))
txt_file.write(str(output)+'\n')
#### Rx Message name, Rx Cycle time ###
Cymessagename=[]
RxCycletime=[]
Rxcycletme={}


for i in t3:
    Cymessagename.append(i.name)
    RxCycletime.append(i.cycle_time)
Rxcycletme=dict(zip(Cymessagename,RxCycletime))
txt_file.write(str(Rxcycletme)+'\n')

#### Rx Message name, Rx Signals ####
data = []
data5 = []
for i in t3:
    i1 = i.signals
    data1 = []
    data2 = []
    for elem in i1:
        data1.append((elem.name))
        data2.append(elem.receivers)
    list1 = list(chain.from_iterable(data2))
    mylist = list(dict.fromkeys(list1))
    data5.append((i.name,data1,mylist))
txt_file.write(str(data5)+'\n')

##### its optional Message_name,signal_tree #####
data = []
for i in t3:
    data.append((i.name,i.signal_tree))
txt_file.write(str(data)+'\n')

###### scale_factor ######
t3 = db.messages
Rxns_factor ={}
for i in t3:
    i1 = i.signals
    scale1 = []
    for elem in i1:
        scale1.append(elem.name)
        scale1.append(elem.scale)
    Rxns_factor.update({i.name:scale1})
print(Rxns_factor)
txt_file.write(str(Rxns_factor)+'\n')

#### offset ######
t3 = db.messages
Rxns_offset ={}
for i in t3:
    i1 = i.signals
    offset1 = []
    for elem in i1:
        offset1.append(elem.name)
        offset1.append(elem.offset)
    Rxns_offset.update({i.name:offset1})
print(Rxns_offset)
txt_file.write(str(Rxns_offset)+'\n')

#### Signal Length ######
t3 = db.messages
Rxns_length ={}
for i in t3:
    i1 = i.signals
    length11 = []
    for elem in i1:
        length11.append(elem.name)
        length11.append(elem.length)
    Rxns_length.update({i.name:length11})
#print(Rxns_length)
txt_file.write(str(Rxns_length)+'\n')
