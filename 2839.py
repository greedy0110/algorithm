N = int(input())

ans = -1
for i in range(5):
    remaining = N-3*i
    if remaining == 0:
        ans = i
        break
    elif remaining < 0:
        break
    elif remaining % 5 == 0:
        ans = i + remaining // 5
        break

print(ans)
