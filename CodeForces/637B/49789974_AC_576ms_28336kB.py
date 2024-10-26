N = (int)(input())
cola = []
sset = set()

for _ in range(N):
    line = input()

    cola.append(line)
    sset.add(line)

while len(cola) > 0:
    actual = cola.pop()

    if actual in sset:
        sset.remove(actual)

        print(actual)