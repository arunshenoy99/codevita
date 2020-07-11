m, a, b = map(int, input().split(','))

list1 = []

for i in range(m):
    row = input().split(';')
    for r in row:
        list2 = []
        x, y = r.split(',')
        list2.append((int(x), int(y)))
    list1.append(list2)

row, col = [int(i) for i in input().split(',')]

for i in range(a*b):
    row, col = list1[row - 1][col - 1]

print("%d,%d"%(row, col))