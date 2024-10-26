n = input()
solucion = 0
abren = 0

for i in n:
    if i == '(':
        abren += 1
    elif i == ')' and abren > 0:
        solucion += 2
        abren -= 1

print(solucion)