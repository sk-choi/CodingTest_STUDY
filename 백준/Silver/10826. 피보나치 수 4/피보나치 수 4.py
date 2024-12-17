num = input()
num = int(num)

fibo = [0, 1]

for i in range(2, num+1, 1):
    number = fibo[i-1] + fibo[i-2]    
    fibo.append(number)
    number = 0
print(fibo[num])