#!/bin/python

import sys

def birthdayCakeCandles(n, ar):
    # Complete this function
    sum = 0
    max = 0
    for i in range(n):
        if max < ar[i]:
            max = ar[i]
            sum = 0
        if max == ar[i]:
            sum += 1
    return sum

n = int(raw_input().strip())
ar = map(int, raw_input().strip().split(' '))
result = birthdayCakeCandles(n, ar)
print(result)
