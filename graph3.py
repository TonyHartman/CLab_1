import numpy as np
import matplotlib.pyplot as plt
time1 = [2,3,4,6,9,11,15,20,28,41,66,91,135,199,299,447,675,1007,1513,2257,3391,5101,7729] # биноминальное
time2 = [0,1,2,3,4,7,10,14,22,32,49,77,108,161,241,363,545,823,1225,1832,2787,4178,6229] # равновероятное распределение
number = []
for i in range(1, len(time1) + 1):
    number.append(100 * 1.5**i)

k1 = np.polyfit(number, time1, 1)
x_th1 = np.arange(0, 1200000, 1000)
y_th1 = []
for i in range(0, len(x_th1)):
    y_th1.append(k1[0] * x_th1[i] + k1[1])
plt.figure(figsize=(10, 5))

k2 = np.polyfit(number, time2, 1)
x_th2 = np.arange(0, 1200000, 1000)
y_th2 = []
for i in range(0, len(x_th2)):
    y_th2.append(k2[0] * x_th2[i] + k2[1])
plt.figure(figsize=(10, 5))

plt.figure(figsize=(10, 5))
plt.plot(x_th1, y_th1, label=r'Search A - binomial distribution')
plt.plot(x_th2, y_th2, label=r'Search A - uniform distribution')
plt.errorbar(number, time1, xerr=0, yerr=0, fmt=".k", label="data")
plt.errorbar(number, time2, xerr=0, yerr=0, fmt=".k")

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()
