import os
import sys

print("Start Program")
print(sys.argv[1])
os.system('cantools generate_c_source %s' % (sys.argv[1]))
print("End Program ")