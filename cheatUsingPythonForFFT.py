# https://www.codechef.com/COOK98A/problems/DOTIT

# can be solved using FFT but also passes python numpy.dot function in given time limit

import numpy as np
for i in range(int(input())):
	n,q=(int(s) for s in input().split())
	A=np.array([int(s) for s in input().split()])
	B=np.array([int(s) for s in input().split()])
	for j in range(q):
		x,y,l=(int(s) for s in input().split())
		print(np.dot(A[x-1:x+l-1],B[y-1:y+l-1]))
