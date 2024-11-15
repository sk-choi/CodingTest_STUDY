num = int(input())

facto = 1;
for i in range(num):
    facto *= (i+1)
    
str_facto = str(facto)

count = 0

length = len(str_facto)
for j in range(length-1, 0, -1):
    if str_facto[j] == "0":
        count = count+1
    else:
        break
    
print(count)