t = (int)(input())

for _ in range(t):
    a = 0
    b = 0
    cont = 0

    cadena = input()

    for i in cadena:
        if i == '(':
            a += 1
        elif i == ')' and a > 0:
            cont += 1
            a -= 1
        elif i == '[':
            b += 1
        elif i == ']' and b > 0:
            cont += 1
            b -= 1

    print(cont)