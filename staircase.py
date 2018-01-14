#!/bin/python

import sys


n = int(raw_input().strip())

for i in range(n):
    row = ""
    for j in range(n - i - 1):
        row += " "
    for k in range(i + 1):
        row += "#"
    print row