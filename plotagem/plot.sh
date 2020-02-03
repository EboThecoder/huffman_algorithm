from matplotlib import pyplot as plt 
from matplotlib import style 
import numpy as np

style.use('ggplot')

N, BST, RBT = np.loadtxt('plot_points.txt',unpack=True,delimiter = ';')

N, BST, RBT = zip(*sorted(zip(N, BST, RBT)))

plt.plot(N,BST,label='BST')
plt.scatter(N,BST,marker='.', color='b')
plt.plot(N,RBT,label='RBT')
plt.scatter(N,RBT,marker='.', color='r')

plt.title('Tree Comparison\nBST vs RBT')
plt.ylabel('Comparisons')
plt.xlabel('Tree size')
plt.legend()

plt.show()