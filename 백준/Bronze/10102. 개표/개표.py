num = int(input())
win = list(input())

for i in range(num):
    win

count1 = 0
count2 = 0
for i in range(len(win)):
   
    if win[i] == "A":
        count1+=1
    if win[i] == "B":
        count2+=1

if count1 > count2:
    print("A")

elif count2 > count1:
    print("B")

elif count1 == count2:
    print("Tie")
