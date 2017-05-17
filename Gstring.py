def bitarray(k):
    bits = []
    mask = 1
    for i in range(0,400):
        if k & mask == 1:
            bits.insert(0, 1)
        else:
            bits.insert(0, 0)
        k = k/2
    return bits

def findlarge(k):
    bits = bitarray(k)
    i = 0
    while i < 400 and bits[i] == 0:
        i += 1
    return len(bits) - i

def findbit(k):
    reverse = 0
    while True:
        N = findlarge(k)
        if N > 0:
            pos = 2**(N - 1)
            if k > pos:
                reverse += 1
                k = 2**N - k
            else:
                break
    if reverse%2 == 0:
        return 0
    else:
        return 1

T = int(raw_input())
case = 0
output = []
while case < T:
    output.append("Case #%d: %d"%(case + 1, findbit(int(raw_input()))))
    case += 1

for i in output:
	print i
