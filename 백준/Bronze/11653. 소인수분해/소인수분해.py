n = int(input())
sum = 2
if n == 1:
    print(' ')
else:
    while (n/sum) > 1:
        if (n/sum) == 1:
            print(sum)
            break
        elif (n/sum) > 1:
           if (n%sum) == 0:
               n = n//sum
               sum = sum
               print(sum)
           elif (n%sum) > 0:
               sum += 1
    print(sum)