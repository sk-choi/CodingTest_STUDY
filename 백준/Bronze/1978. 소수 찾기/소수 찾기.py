import math

n = 1000
array = [True for i in range(n+1)]
odd_arr = []
for i in range(2, int(math.sqrt(n)+1)):
  if array[i] == True:
    j = 2
    while i * j <= n: 
      array[i*j] = False
      j+=1
for i in range(2, n+1):
  if array [i]:
    odd_arr.append(i)

#print(arr)

n = int(input())
num = input().split()
num = list(map(int, num))
count = 0

for i in range(len(odd_arr)):
  if odd_arr[i] in num:
    count += 1
  else:
    count = count
print(count)