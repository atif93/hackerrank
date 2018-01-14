#!/bin/python

import sys

def aVeryBigSum(n, ar):
    # Complete this function
    sum = 0
    for num in ar:
        sum += num
        
    return sum

n = int(raw_input().strip())
ar = map(long, raw_input().strip().split(' '))
result = aVeryBigSum(n, ar)
print(result)
