#!/usr/bin/env python
# -*- coding: utf-8 -*-
def save(str, pattern):
    buff = []
    for item in str:
        if pattern in item:
            buff.append(item)
            continue
    return buff

def cutout(str, pattern):
    buff = []
    for item in str:
        if pattern in item:
            buff.append(item[:item.index(pattern)])
            del item
            continue
    return buff

f = open('rough.apt')
input_list_1 = f.readlines()
input_str_1 = ''.join(input_list_1)
pattern = '\n'
input_split_1 = input_str_1.split(pattern)
#print input_split_1
input_list_2 = save(input_split_1, '$$PT')
input_str_2 = ''.join(input_list_2)
input_split_2 = input_str_2.split('GOTO/')
output = cutout(input_split_2, '$$PT')
#print output
writer = open('output_file.txt', 'w')
writer.write('\n'.join(output))
writer.close
