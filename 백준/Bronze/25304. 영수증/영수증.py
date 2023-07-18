cash = int(input())
num = int(input())
multi = []
sum = 0
for i in range(int(num)):
    buy = input().split()
    multi.append(buy)
    sum += (int(multi[i][0]) * int(multi[i][1]))


if sum == cash:
       print("Yes")
else:
       print("No")    


     