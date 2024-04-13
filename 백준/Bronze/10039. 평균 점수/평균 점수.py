a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

score = []
score.append(int(a))
score.append(int(b))
score.append(int(c))
score.append(int(d))
score.append(int(e))

sum = 0
for i in range(len(score)):
    if score[i] < 40:
        score[i] = 40
    sum += score[i]

print(sum//5)