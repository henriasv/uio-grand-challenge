# Read binary file
import numpy as np
import matplotlib.pyplot as plt

filename = "output/positions.bin"

numBlocks 	= 70;

positions = np.fromfile(filename)
nt = len(positions)/numBlocks;

positions.resize(nt, numBlocks)

plt.pcolormesh(positions-positions[0])
plt.xlabel('Block index')
plt.ylabel('Time step')
plt.colorbar()
plt.show()
