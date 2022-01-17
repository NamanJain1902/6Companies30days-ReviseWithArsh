import os
import re
import sys


path = sys.argv[1]
for fil in os.listdir(path):
    print(fil)
    l = fil.split("_")
    if(len(l[0]) == 1):
        os.rename(fil, '0' + fil)
    


