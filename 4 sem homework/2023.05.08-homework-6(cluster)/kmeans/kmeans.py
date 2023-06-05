import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

f = open('data6.txt')
coords = np.array(list(map(int, f.read().split())))
f.close()
dots = np.reshape(coords, (-1, 2))

kmeans = KMeans(n_clusters=4, random_state=0, n_init="auto").fit(dots)

plt.figure(1)
plt.scatter(dots[:, 0], dots[:, 1], s=0.75, c=(kmeans.labels_))
plt.show()
