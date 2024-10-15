n, m = map(int, input().split())


result1 = 1
for i in range(1,n+1):
    result1 *= i
    
#print(result1)

result2 = 1
for i in range(1,n-m+1):
    if n == m:
        result = 1
        break
    else:
        result2 *= i
    
#print(result2)

result3 = 1
for i in range(1,m+1):
    result3 *= i

#print(result3)

total = result1 // (result2 * result3)

print(int(total))