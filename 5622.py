alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers = "22233344455566677778889999"

table = dict(zip(alpha, numbers))

time = 0
for alpha in input():
    time += int(table[alpha]) + 1
print(time)
