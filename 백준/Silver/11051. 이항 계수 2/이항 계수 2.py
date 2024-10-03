a = input().split()

a = list(map(int, a))

sum = 1
sum2 = 1
for i in range(a[1]):
    sum *= (a[0]-i)
    sum2 *= (a[1]-i)
print((int(sum//sum2))%10007)