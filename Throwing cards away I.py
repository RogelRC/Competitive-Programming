from collections import deque

lista = deque()
descartados = []

while True:
    n = (int)(input())

    if n == 0:
        break

    lista.clear()
    descartados.clear()

    for i in range(n):
        lista.append(n - i)

    while len(lista) > 1:
        a = lista.pop()

        descartados.append(a)

        if len(lista) == 1:
            break

        a = lista.pop()
        lista.appendleft(a)

    print("Discarded cards:", end = "")

    for i in range(len(descartados)):
        print(" " + str(descartados[i]), end = "")

        if i < len(descartados) - 1:
            print(",", end = "")

    print()
    print("Remaining card: " + str(lista[0]))