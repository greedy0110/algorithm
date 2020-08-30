import random

# C-1.20

def my_shuffle(data):
    for i in range(len(data)):
        j = random.randint(i, len(data)-1)
        data[i], data[j] = data[j], data[i]

sample = [i for i in range(10)]
my_shuffle(sample)
print(sample)

