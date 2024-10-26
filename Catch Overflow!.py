t = (int)(input())
pila = []
sol = 0
asd = 0
mul = 1
NMAX = 2 ** 32 - 1

lista = [input() for _ in range(t)]

for i in lista:
    if i.startswith("add"):
        sol += mul

    elif i.startswith("end"):
        if asd > 0:
            asd -= 1
        
        else:
            mul /= pila.pop()

    else:
        a = (int)(i.split()[1])

        if mul > NMAX:
            asd += 1

        else:
            pila.append(a)
            mul *= a

    if sol > NMAX:
        break

if sol > NMAX:
    print("OVERFLOW!!!")
else:
    print((int)(sol))