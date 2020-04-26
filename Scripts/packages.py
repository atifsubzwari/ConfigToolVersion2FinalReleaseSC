import subprocess
import time
def install(name):
    subprocess.call(['pip', 'install', name])

list1 = ['cantools','selenium','mod']
for i in list1:
    ad = install(i)

