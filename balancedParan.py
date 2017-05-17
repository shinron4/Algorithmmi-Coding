#!/usr/bin/python

MaxSub = [0, 1]
def MaxSubString(P):
	length = len(MaxSub)
	while P >= length:
		maximum = 0
		for i in range(0, length):
			q = MaxSub[i] + MaxSub[length - 1 - i] + length - i
			if q > maximum:
				maximum = q
		MaxSub.append(maximum)
		length += 1
	return MaxSub[P]

T = int(raw_input())
case = 0
output = []	 
while case < T:
	[L, R] = [int(i) for i in (raw_input()).split(" ")]
	output.append("Case #%d: %d" % (case + 1, MaxSubString(min(L, R))))
	case += 1
for i in output:
	print i


