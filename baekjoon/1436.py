N = int(input())

ret = 0
count = 0
for i in range(666, 6670000):
    if str(i).find("666") != -1:
        count = count + 1
        if count == N:
            ret = i
            break

print(ret)
