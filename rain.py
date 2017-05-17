#!/usr/bin/python
def reachable(H, grid, R, C):
	Q = []
	for i in range(0, R):
		for j in range(0, C):
			if (i == 0 or j == 0 or i == R -1 or j == C - 1):
				Q.append([i,j])
	while len(Q) != 0:
		[x, y] = Q.pop(0)
		if(x - 1 > 0 and y < C):
			if grid[x-1][y] != 'x' and H[x-1][y] >= H[x][y]:
				grid[x-1][y] = 'x'
				Q.append([x-1,y])
			elif grid[x-1][y] != 'x' and H[x-1][y] < H[x][y]:
				if grid[x-1][y] > 0:
					grid[x-1][y] = min(grid[x-1][y], H[x][y])
				else:
					grid[x-1][y] = H[x][y]
		if(x + 1 < R and y < C):
			if grid[x+1][y] != 'x' and H[x+1][y] >= H[x][y]:
				grid[x+1][y] = 'x'
				Q.append([x+1,y])
			elif grid[x+1][y] != 'x' and H[x+1][y] < H[x][y]:
				if grid[x+1][y] > 0:
					grid[x+1][y] = min(grid[x+1][y], H[x][y])
				else:
					grid[x+1][y] = H[x][y]
		if(x < R and y - 1  > 0):
			if grid[x][y-1] != 'x' and H[x][y-1] >= H[x][y]:
				grid[x][y-1] = 'x'
				Q.append([x,y-1])
			elif grid[x][y-1] != 'x' and H[x][y-1] < H[x][y]:
				if grid[x][y-1] > 0:
					grid[x][y-1] = min(grid[x][y-1], H[x][y])
				else:
					grid[x][y-1] = H[x][y]
		if(x < R and y + 1 < C):
			if grid[x][y+1] != 'x' and H[x][y+1] >= H[x][y]:
				grid[x][y+1] = 'x'
				Q.append([x,y+1])
			elif grid[x][y+1] != 'x' and H[x][y+1] < H[x][y]:
				if grid[x][y+1] > 0:
					grid[x][y+1] = min(grid[x][y+1], H[x][y])
				else:
					grid[x][y+1] = H[x][y]
T = int(raw_input())
case = 0
output = []
def findregion(grid, x, y):
	Q = []
	region.append([])
	boundary.append([[x,y, grid[x][y]]])
	Q.append([x,y])
	grid[x][y] = 'r'
	while len(Q) != 0:
		[x, y] = Q.pop(0)
		if(x - 1 > 0 and y < C):
			if grid[x-1][y] == '0':
				grid[x-1][y] = 'r'
				Q.append([x-1,y])
				region[len(region) - 1].append([x-1,y])
			elif grid[x-1][y] != 'x' and grid[x-1][y] != 'r' and grid[x-1][y] > 0:
				boundary[len(boundary) - 1].append([x-1,y,grid[x-1][y]])
				grid[x-1][y] = 'r'
				Q.append([x-1,y])
		if(x + 1 < R and y < C):
			if grid[x+1][y] == '0':
				grid[x+1][y] = 'r'
				Q.append([x+1,y])
				region[len(region) - 1].append([x+1,y])
			elif grid[x+1][y] != 'x' and grid[x+1][y] != 'r' and grid[x+1][y] > 0:
				boundary[len(boundary) - 1].append([x+1,y,grid[x+1][y]])
				grid[x+1][y] = 'r'
				Q.append([x+1,y])
		if(x < R and y - 1  > 0):
			if grid[x][y-1] == '0':
				grid[x][y-1] = 'r'
				Q.append([x,y-1])
				region[len(region) - 1].append([x,y-1])
			elif grid[x][y-1] != 'x' and grid[x][y-1] != 'r' and grid[x][y-1] > 0:
				boundary[len(boundary) - 1].append([x,y-1,grid[x][y-1]])
				grid[x][y-1] = 'r'
				Q.append([x,y-1])
		if(x < R and y + 1 < C):
			if grid[x][y+1] == '0':
				grid[x][y+1] = 'r'
				Q.append([x,y+1])
				region[len(region) - 1].append([x,y+1])
			elif grid[x][y+1] != 'x' and grid[x][y+1] != 'r' and grid[x][y+1] > 0:
				boundary[len(boundary) - 1].append([x,y+1,grid[x][y+1]])
				grid[x][y+1] = 'r'
				Q.append([x,y+1])
def getkey(rbele):
	return rbele[2]
while case < T:
	[R, C] = (raw_input()).split(" ")
	R = int(R)
	C = int(C)
	H = [[int(j) for j in raw_input().split(" ")] for i in range(0, R)]
	total = 0
	while True:
		grid = [['x' if (i == 0 or j == 0 or i == R -1 or j == C - 1) else '0' for j in range(0, C)] for i in range(0, R)]
		reachable(H, grid, R, C)
		remain = False
		for r in range(0, R):
			for c in range(0, C):
				if grid[r][c] != 'x':
					remain = True
					break
			if remain == True:
				break
		if remain == False:
			break
		region = []
		boundary = []
		while True:
			found = False
			for r in range(0, R):
				for c in range(0, C):
					if grid[r][c] != 'x' and grid[r][c] != 'r':  
						findregion(grid, r,c)
						found = True
			if found == False:
				break
		for r in range(0, len(boundary)):
			[x,y,minb] = min(boundary[r], key = getkey)
			for b in boundary[r]:
				grid[b[0]][b[1]] = minb
			for rele in region[r]:
				grid[rele[0]][rele[1]] = minb
		for r in range(0, R):
			for c in range(0, C):
				if grid[r][c] != 'x':
					if H[r][c] <= grid[r][c]:
						total += (grid[r][c] - H[r][c])
						H[r][c] = grid[r][c]
	output.append("Case #%d: %s" % (case + 1, total))
	case += 1
for i in output:
	print i
