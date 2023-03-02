import numpy as np
import matplotlib.pyplot as plt
time = [1,2,3,4,6,10,14,21,33,46,68,102,161,229,342,514,807,1288,1754,2731,4023,6130,9293]
number = []
for i in range(1, len(time) + 1):
    number.append((100 * 1.5**i))



k = np.polyfit(number, time, 1)
x_th = np.arange(0, 1200000, 1000)
y_th = []
for i in range(0, len(x_th)):
    y_th.append(k[0] * x_th[i] + k[1])
plt.figure(figsize=(10, 5))

plt.figure(figsize=(10, 5))
plt.plot(x_th, y_th, label=r'Smart search')
plt.errorbar(number, time, xerr=0, yerr=0, fmt=".k", label="data")

plt.xlabel(r'$N$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()
