#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import matplotlib.pyplot as plt
import csv
import numpy as np

datal = []
stamp = []

with open('duration.csv') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        datal.append(row['duration'])
        stamp.append(row['header'])

data = np.array(datal)
data = data.astype(np.float)
data /= 1000000
data = abs(1-data)
plt.hist(data,1000) 
plt.title("histogram") 
plt.show()