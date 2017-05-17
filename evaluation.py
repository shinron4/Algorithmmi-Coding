#!/usr/bin/python

T = int(raw_input())
case = 0
output = []
while case < T:
	N = int(raw_input())
	i = 0
	dictionary = {}
	evaluate = []
	while i < N:
		string = raw_input()
		dictionary.update({string.split("=")[0]: string.split("(")[1].split(")")[0].split(",")})
		i += 1
	length = len(evaluate)
	while True:
		for sym in dictionary.keys():
			if sym not in evaluate:
				if(dictionary[sym][0] == ''):
					evaluate.append(sym)
				else:
					l = dictionary[sym]
					count = 0
					for i in l:
						if i in evaluate:
							count += 1
					if count == len(l):
						evaluate.append(sym)
		if len(evaluate) == length:
			break
		else:
			length = len(evaluate)
	if len(evaluate) == len(dictionary.keys()):
		output.append("Case #%d: %s" % (case + 1, "GOOD"))
	else:
		output.append("Case #%d: %s" % (case + 1, "BAD"))
	case += 1
for i in output:
	print i
