import numpy as np
import matplotlib.pyplot as plt

N = 5
FungusA = (12,43,0,0,0)
FungusB = (59,59,0,0,0)
FungusC = (59,59,0,0,0)
FungusD = (59,59,0,0,0)
FungusE = (59,59,0,0,0)
FungusF = (59,59,0,0,0)
FungusG = (59,59,0,0,0)
FungusH = (59,59,0,0,0)
FungusI = (59,59,0,0,0)
d = []
for i in range(0, len(FungusA)):
    sum = FungusA[i] + FungusB[i] + FungusC[i] + FungusD[i] +FungusE[i] + FungusF[i]+ FungusG[i] + FungusH[i] + FungusI[i]
    d.append(sum)
M = (10, 11, 7, 11, 8, 6, 6, 5, 3, 3, 7, 5, 9)
# menStd = (2, 3, 4, 1, 2)
# womenStd = (3, 5, 2, 3, 3)
ind = np.arange(N)  # the x locations for the groups
width = 0.35  # the width of the bars: can also be len(x) sequence

p1 = plt.bar(ind, FungusA, width, color='#d62728')  # , yerr=menStd)
p2 = plt.bar(ind, FungusB, width, bottom=FungusA)
p3 = plt.bar(ind, M, width, bottom=d)
p4 = plt.bar(ind, FungusA, width)
p5 = plt.bar(ind, FungusA, width, bottom=S)
p6 = plt.bar(ind, M, width, bottom=d)
p7 = plt.bar(ind, FungusA, width)
p8 = plt.bar(ind, FungusA, width, bottom=S)
p9 = plt.bar(ind, M, width, bottom=d)

plt.ylabel('Numbers')
plt.title('Environment')
plt.xticks(ind, ('G1', 'G2', 'G3', 'G4', 'G5')
plt.yticks(np.arange(0, 81, 20))
plt.legend((p1[0], p2[0], p3[0]), ('S', 'C', 'M'))

plt.show()