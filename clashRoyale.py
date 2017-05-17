#!/usr/bin/python

left = 0
def maximumAS(Cards, coinleft):
	AS = 0
	if len(Cards) > left:
		for c in range(0, len(Cards)):
			newCards = [Cards[nc] for nc in range(0, len(Cards)) if nc != c]
			maximum = 0
			for l in Cards[c]:
				if coinleft >= l[1]:
					AS = maximumAS(newCards, coinleft - l[1]) + l[0]
					if AS > maximum:
						maximum = AS
			return maximum
	return 0
def getline():
	line = raw_input()
	while line == "":
		line = raw_input()
	return line
T = int(getline())
case = 0
output = []
while case < T:
	Cards = []
	[M,N] = [int(i) for i in getline().split(" ")]
	left = N - 8
	for c in range(0, N):
		AS = []
		Cost = []
		[maxl, curr] = [int(i) for i in getline().split(" ")]
		AS = [int(i) for i in getline().split(" ")]
		if maxl > 1:
			Cost = [int(i) for i in getline().split(" ")]		
		tcost = 0
		Cards.append([])
		for l in range(0, maxl):
			if (l + 1) >= curr:
				Cards[c].append([AS[l], tcost])
				if l < len(Cost):
					tcost += Cost[l]
	output.append("Case #%d: %d" % (case + 1, maximumAS(Cards, M)))
	case += 1
for i in output:
	print i
