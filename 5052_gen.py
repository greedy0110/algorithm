import random

t = 50
n = 10000

f = open("5050_gen.txt", "w")
f.writelines(str(t) + "\n")
for _ in range(t):
    f.writelines(str(n) + "\n")
    f.writelines(
        "\n".join([str(random.randint(0, 1000000000)) for _ in range(n)]))
    f.write("\n")
f.close()
