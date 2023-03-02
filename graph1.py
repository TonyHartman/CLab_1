import numpy as np
import matplotlib.pyplot as plt
time = [56,63,67,62,63,68,72,78,80,84,90,100,99,106,105,104,110,119,115,118,124,133,140]
number = []
for i in range(1, len(time) + 1):
    number.append(np.log(100 * 1.5**i))

k = np.polyfit(number, time, 1)
x_th = np.arange(np.log(100), np.log(100 * 1.5**(len(time) + 1)), np.log(100 * 1.5**(len(time) + 1))/1000)
y_th = []
for i in range(0, len(x_th)):
    y_th.append(k[0] * x_th[i] + k[1])
plt.figure(figsize=(10, 5))
plt.plot(x_th, y_th, label=r'Full search')
plt.errorbar(number, time, xerr=0, yerr=0, fmt=".k", label=r'data')

plt.xlabel(r'$ln(N)$', fontsize=20)
plt.ylabel(r'$t$', fontsize=20)
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.show()
