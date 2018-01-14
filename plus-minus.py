#!/bin/python

import sys


n = int(raw_input().strip())
arr = map(int,raw_input().strip().split(' '))

p = 0
m = 0
z = 0

for num in arr:
    if num > 0:
        p += 1
    elif num < 0:
        m += 1
    else:
        z += 1
        
print float(p) / n
print float(m) / n
print float(z) / n