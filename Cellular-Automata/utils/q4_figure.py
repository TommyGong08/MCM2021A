import matplotlib.pyplot as plt
import matplotlib.pyplot as subplot
import matplotlib as mp1
import numpy as np
# 设置输出文字类型
mp1.rcParams['font.family'] = 'Times New Roman'

# 设置标签
labels1 =["FungusA","FungusB","FungusC","FungusD","FungusE","FungusF","FungusG","FungusH","FungusI"]
labels2 =["FungusA","FungusB","FungusC","FungusD","FungusE","FungusG","FungusH","FungusI"]
labels3 =["FungusF"]
labels4 =["FungusI"]
labels5 =["FungusD","FungusE","FungusF"]
# 设置数据
fracs1 = [12,59,32,23,23,4,45,117,85]
fracs2 = [43,59,23,12,9,77,104,73]
fracs3 = [400]
fracs4 = [400]
fracs5 = [89,179,132]

# 画面积图
plt.subplot(3,2,1)
subplot.pie(fracs1 ,labels=labels1,autopct='%1.1f%%',shadow=False,startangle=150,pctdistance = 0.5)
subplot.title("Arid",size = 18)
plt.subplot(3,2,2)
subplot.pie(fracs2 ,labels=labels2,autopct='%1.1f%%',shadow=False,startangle=150,pctdistance = 0.5)
subplot.title("Semi—Arid",size = 18)
plt.subplot(3,2,3)
subplot.pie(fracs3 ,labels=labels3,autopct='%1.1f%%',shadow=False,startangle=150,pctdistance = 0.5)
subplot.title("Temperate",size = 18)
plt.subplot(3,2,4)
subplot.pie(fracs4 ,labels=labels4,autopct='%1.1f%%',shadow=False,startangle=150,pctdistance = 0.5)
subplot.title("Arboreal",size = 18)
plt.subplot(3,2,5)
subplot.pie(fracs5 ,labels=labels5,autopct='%1.1f%%',shadow=False,startangle=150,pctdistance = 0.5)
subplot.title("Rain forests",size = 18)

plt.size = 22
# 可视化呈现
plt.show()