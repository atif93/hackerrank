#!/bin/python

import sys


n = int(raw_input().strip())
a = []
for a_i in xrange(n):
    a_temp = map(int,raw_input().strip().split(' '))
    a.append(a_temp)

diag1 = 0
diag2 = 0
for i, row in enumerate(a):
    for j, val in enumerate(row):
        if i == j:
            diag1 += val
        if i + j == n - 1:
            diag2 += val
            
print abs(diag1 - diag2)