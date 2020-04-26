import os
import sys
file1 = open(sys.argv[1],"r+") 
flag = False
d = file1.read()
d1 = (d.splitlines())
data5 = []
txt_file = open(sys.argv[2]+'pack.txt','w')
#### pack ####
for i in d1:
    if flag:
       data5.append(i)
    if '_pack' in i :
       flag = True
       data5.append(i)
    if '_unpack' in i:
       flag = False

for i in data5:
    if '_unpack' in i:
       (data5.remove(i))
      
for i in data5:
    txt_file.write(i+'\n')
    


#### unpack ####
data6 = []
txt_file_1 = open(sys.argv[2]+'unpack.txt','w')
for i in d1:
    if flag:
       data6.append(i)
    if '_unpack' in i :
       flag = True
       data6.append(i)
    if '_encode' in i:
       flag = False

for i in data6:
    if '_encode' in i:
       (data6.remove(i))
for i in data6:
    txt_file_1.write(i+'\n')
    #print(i)

#### encode #####
data7= []
txt_file_2 = open(sys.argv[2]+'encode.txt','w')
for i in d1:
    if flag:
       data7.append(i)
    if '_encode' in i :
       flag = True
       data7.append(i)
    if '_decode' in i:
       flag = False

for i in data7:
    if '_decode' in i:
       (data7.remove(i))
       
for i in data7:
    txt_file_2.write(i+'\n')

#### decode #####
data8 = []
txt_file_3 = open(sys.argv[2]+'decode.txt','w')
for i in d1:
    if flag:
       data8.append(i)
    if '_decode' in i :
       flag = True
       data8.append(i)
    if '_range' in i:
       flag = False

for i in data8:
    if '_range' in i:
       (data8.remove(i))
       
for i in data8:
    txt_file_3.write(i+'\n')


#### static #####   
data9 = []
data10 = []        
txt_file_4 = open(sys.argv[2]+'static.txt','w')
for i in d1:
    if flag:
       data9.append(i)
    if 'static' in i :
       flag = True
       data10.append(i)
    if '_pack' in i:
       flag = False

txt_file_4.write(data10[0]) 
data5.pop()    
for i in data9:
    txt_file_4.write(i+'\n')
    

data11 = []
txt_file_5 = open(sys.argv[2]+'range.txt','w')
for i in d1:
    if flag:
       data11.append(i)
    if 'in_range' in i :
       flag = True
       data11.append(i)
    if '_encode' in i:
       flag = False
    if '_pack' in i:
       flag = False

for i in data11:
    if '_encode' in i:
       (data11.remove(i))
    if '_pack' in i:
       (data11.remove(i))
       
for i in data11:
    txt_file_5.write(i+'\n')

