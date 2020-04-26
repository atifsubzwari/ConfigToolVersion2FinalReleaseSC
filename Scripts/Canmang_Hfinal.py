import os
import sys
import cantools
from pprint import pprint
import pdb
import numpy as np
import csv
import binascii
db = cantools.database.load_file("Updated_DB.DBC")
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



####### Node names : It includes total nodes present in the dbc file ##############
txt_file = open('Final10'+'.txt','w')
nodenames=[]
for i in t4:
    nodenames.append(i.name)
txt_file.write(str(nodenames)+'\n')
####Transmission_message,key:Names,value:sender####
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
    #print("dictionary of Names,sender_transmission:",i, " :", Trns_final[i]) 
txt_file.write(str(Trns_final)+'\n')
#### Receiver_message,key:Names,value:receiver ####
data = []
for i in t3:
    i1 = i.signals
    for elem in i1:
        data.append([i.name,elem.receivers])
txt_file.write((str(data)+'\n'))
#### Transmission_Frame_id,key:Message,value:frame_id ####
messagename=[]
messageframeid=[]
Txframeid={}
for i in t3:
    messagename.append(i.name)
    
    messageframeid.append(hex(i.frame_id))
Txframeid=dict(zip(messagename,messageframeid))
txt_file.write(str(Txframeid)+'\n')   
#### Transmission_DLC_(byte Generation key:dlc_name,value:dlc' ####
dlcmessagename=[]
dlc=[]
Txdlc={}
for i in t3:
    dlcmessagename.append(i.name)
    dlc.append(i.length)
Txdlc=dict(zip(dlcmessagename,dlc))
txt_file.write(str(Txdlc)+'\n')
#### Transmission_TX_method,key:Txmessagename,value:TxMethod ####

Txmessagename=[]
TxMethod=[]
Txmethodtyp={}

for i in t3:
    Txmessagename.append(i.name)
    TxMethod.append(i.send_type)
Txmethodtyp=dict(zip(Txmessagename,TxMethod))
txt_file.write(str(Txmethodtyp)+'\n')

    
#### Transmission_Cycle Time Generation,key:Cyclemessagename,value:TxCycletime ####
Cymessagename=[]
TxCycletime=[]
Txcycletme={}


for i in t3:
    Cymessagename.append(i.name)
    TxCycletime.append(i.cycle_time)
Txcycletme=dict(zip(Cymessagename,TxCycletime))
txt_file.write(str(Txcycletme)+'\n')


#### Reciever_signals,key:reciever_message,value:receiver_Names ####
sendersm1=[]
recvm1=[]
Namesm1=[]
Rxns={}
Rxns_final={}

for i in t3:
    im1 = i.signals
    senderm = i.senders
    sendersm1.append(senderm)
    for im2 in im1:
        splitm1 = (im2.name)
        recvm1.append(splitm1)
        Namesm1.append(i.name)
        
        Rxns =dict(zip(recvm1,Namesm1))


for key, value in Rxns.items(): 
   if value in Rxns_final: 
       Rxns_final[value].append(key) 
   else: 
       Rxns_final[value]=[key] 
for i in Rxns_final: 
    pass
   
txt_file.write(str(Rxns_final)+'\n')

#### Reciever_signal_frame_id,key:reciever_name,value:frame_id #### 
Namesm1=[]
receive_msg_frameid = []
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




        




         
    







