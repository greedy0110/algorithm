fibo = [0, 1]

n = int(input())

for i in range(2, n+1):
    fibo.append(fibo[-2] + fibo[-1])

print(fibo[n])
