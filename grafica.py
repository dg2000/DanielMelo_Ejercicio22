import numpy as np

import matplotlib.pyplot as plt


x = np.loadtxt("datos.txt")[:, 0]

y = np.loadtxt("datos.txt")[:, 1]

original = np.loadtxt("datos.txt")[:, 2]


plt.plot(x, y, label = "Nueva")
plt.plot(x, original, label = "Original")
plt.legend(loc=0)

plt.show()
