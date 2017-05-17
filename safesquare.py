#!/usr/bin/python

def minimum(a, b):
	if a <= b:
		return a
	else:
		return b

T = int(raw_input())
case = 0
output = []
world = []

for l in range(0, 3000):
	world.append([])
	for m in range(0, 3000):
		world[l].append('')

while case < T:
	[R, C, K] = (raw_input()).split(" ")
	R = int(R)
	C = int(C)
	K = int(K)
	for l in range(0, R):
		for m in range(0, C):
			world[l][m] = '0'
	j = ss = 0
	while j < K:
		[l, m] = (raw_input()).split(" ")
		l = int(l)
		m = int(m)
		world[l][m] = '1'
		j += 1
	D = minimum(R, C);
	for j in range(1, D + 1):
		for l in range(0, R - j + 1):
			for m in range(0, C - j + 1):
				count = 0
				for p in range(l, l + j):
					for q in range(m, m + j):
						if world[p][q] == '0':
							count += 1
				if count == j*j: 
					ss += 1
	output.append("Case #%d: %d"%(case + 1, ss))
	case += 1
for i in range(0, T):
	print output[i]
