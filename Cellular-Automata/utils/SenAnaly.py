import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from pandas import DataFrame, Series

# 这两行代码解决 plt 中文显示的问题
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
# read file
datafile = '../data/Sensitivity Analyse.xlsx'
data = pd.read_excel(datafile)
df = DataFrame(data)

T = df.iloc[:,0]
A = df.iloc[:,1]
B = df.iloc[:,2]
C = df.iloc[:,3]
D = df.iloc[:,4]
E = df.iloc[:,5]

plt.plot(T, A, '*-', label='K_m')
plt.plot(T, B, '*-', label='K_T')
plt.plot(T, C, '*-', label='V_ex')
plt.plot(T, D, '*-', label='mos_evm')
plt.plot(T, E, '*-', label='T_evm')

plt.xticks(T)  # 设置横坐标刻度为给定的年份
plt.xlabel('Rate of change') # 设置横坐标轴标题
plt.ylabel('Proportion of ') # 设置横坐标轴标题
plt.legend() # 显示图例，即每条线对应 label 中的内容
plt.ylim(0.55,0.725)
plt.show() # 显示图形