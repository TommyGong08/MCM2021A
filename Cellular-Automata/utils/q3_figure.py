import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from pandas import DataFrame, Series
from matplotlib.pyplot import MultipleLocator

# 这两行代码解决 plt 中文显示的问题
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# read file
datafile = '../data/season_new.xlsx'
data = pd.read_excel(datafile)
df = DataFrame(data)

T = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24]
A = df.iloc[0:24,1]
B = df.iloc[0:24,2]
C = df.iloc[0:24,3]
D = df.iloc[0:24,4]
E = df.iloc[0:24,5]
F = df.iloc[0:24,6]
G = df.iloc[0:24,7]
H = df.iloc[0:24,8]
I = df.iloc[0:24,9]


plt.plot(T, A, '-', label='FungusA')
plt.plot(T, B, '-', label='FungusB')
plt.plot(T, C, '-', label='FungusC')
plt.plot(T, D, '-', label='FungusD')
plt.plot(T, E, '-', label='FungusE')
plt.plot(T, F, '-', label='FungusF')
plt.plot(T, G, '-', label='FungusG')
plt.plot(T, H, '-', label='FungusH')
plt.plot(T, I, '-', label='FungusI')

T2 = [0,12,24]
plt.legend(loc='best',frameon=False) # 显示图例，即每条线对应 label 中的内容
plt.xticks(T)  # 设置横坐标刻度为给定的年份
plt.xlabel('Iteration times') # 设置横坐标轴标题
plt.ylabel('Number of fungi') # 设置横坐标轴标题

plt.show() # 显示图形