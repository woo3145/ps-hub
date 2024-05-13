import sys

# sys.stdin = open("input.txt", "r")

n = int(sys.stdin.readline().strip())

left = []
right = []
bothZero = []
bothOne = []

def appendData(s):
    if s[0] == '0' and s[-1] == '0':
        bothZero.append(s)
    elif s[0] == '1' and s[-1] == '1':
        bothOne.append(s)
    elif s[0] == '1':
        left.append(s)
    elif s[-1] == '1':
        right.append(s)

for _ in range(n):
    t = sys.stdin.readline().strip()
    appendData(t)

if 1 < len(bothOne):
    t = "".join(bothOne)
    bothOne.clear()
    bothOne.append(t)

if 1 < len(bothZero):
    t = "".join(bothZero)
    bothZero.clear()
    bothZero.append(t)

while len(left) or len(right):
    if len(bothOne) and len(left):
        newBundle = bothOne.pop() + left.pop()
        appendData(newBundle)
    if len(bothOne) and len(right):
        newBundle = right.pop() + bothOne.pop()
        appendData(newBundle)
    elif len(bothZero) and len(left):
        newBundle = left.pop() + bothZero.pop()
        appendData(newBundle)
    elif len(bothZero) and len(right):
        newBundle = bothZero.pop() + right.pop()
        appendData(newBundle)
    elif len(left) and len(right):
        newBundle = right.pop() + left.pop()
        appendData(newBundle)
    else:
        break

temp = []
temp.extend(bothZero)
temp.extend(bothOne)
temp.extend(left)
temp.extend(right)
result = ''.join(temp)

prevBit = result[0]
answer = 0
for c in result:
    if prevBit != c:
        answer += 1
        prevBit = c

print(answer)