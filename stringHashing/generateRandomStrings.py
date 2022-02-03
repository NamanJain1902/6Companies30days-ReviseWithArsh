import string
import random as rd

with open("inp", 'w') as f:
    l = ["".join(rd.sample(string.ascii_lowercase[:4], 4)) for _ in range(10)]
    f.write(str(len(l)) + "\n")
    for item in l:
        f.write(item)
        f.write("\n")
