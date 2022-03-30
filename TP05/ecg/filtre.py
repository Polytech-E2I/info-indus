import numpy as np
from scipy import signal
import matplotlib.pyplot as plt
sr = 44100
coef = [-8,-8,-8,-9,-9,-9,-9,-10,-10,-10,-10,-11,-11,-11,-11,-12,-12,-12,-12,-13,-13,-13,-13,-13,-13,-14,-14,-14,-14,-14,-14,-14,-14,-14,-15,-15,-15,-15,-15,-15,985,-15,-15,-15,-15,-15,-15,-14,-14,-14,-14,-14,-14,-14,-14,-14,-13,-13,-13,-13,-13,-13,-12,-12,-12,-12,-11,-11,-11,-11,-10,-10,-10,-10,-9,-9,-9,-9,-8,-8,-8]

print("Somme : {}".format(np.sum(coef)))

w, h = signal.freqz(b=coef, a=1)
x = w * sr * 1.0 / (2 * np.pi)
y = 20 * np.log10(abs(h))
plt.figure(figsize=(10,5))
plt.semilogx(x, y)
plt.ylabel('Amplitude [dB]')
plt.xlabel('Frequency [Hz]')
plt.title('Frequency response')
plt.grid(which='both', linestyle='-', color='grey')
plt.xticks([20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000], ["20", "50", "100", "200", "500", "1K", "2K", "5K", "10K", "20K"])
plt.show()