token = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}

text = input()
N = len(text)

cnt = 0
i = 0
while i < N:
    if i < N-1 and text[i:i+2] in token:  # 2자리 토큰 확인 가능
        i += 2
    elif i < N-2 and text[i:i+3] in token:  # 3자리 토큰 확인 가능
        i += 3
    else:
        i += 1
    cnt += 1

print(cnt)
