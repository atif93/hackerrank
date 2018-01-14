#!/bin/python

import sys

arr = map(int, raw_input().strip().split(' '))

smallest = 1000000001
largest = 0
smi = -1
lri = -1
for i, num in enumerate(arr):
    if num < smallest:
        smallest = num
        smi = i
    if num > largest:
        largest = num
        lri = i

smsum = 0
lrsum = 0
for i in range(len(arr)):
    if i != smi:
        lrsum += arr[i]
    if i != lri:
        smsum += arr[i]
        
print smsum, lrsum