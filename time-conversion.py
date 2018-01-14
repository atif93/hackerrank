#!/bin/python

import sys

def timeConversion(s):
    # Complete this function
    tmap = [i + 12 for i, _ in enumerate(range(12))]
    if s[8] == 'A' and s[:2] == "12":
        s = "00" + s[2:]
    if s[8] == 'P' and s[:2] <= "11":
        s = str(int(s[:2]) + 12) + s[2:]
    s = s[:-2]
    
    return s

s = raw_input().strip()
result = timeConversion(s)
print(result)
