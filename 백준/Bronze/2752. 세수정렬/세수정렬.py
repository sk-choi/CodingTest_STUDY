num = input().split()
num = list(map(int, num))
num = sorted(num)

for i in range(3):
    print(num[i], end = ' ')