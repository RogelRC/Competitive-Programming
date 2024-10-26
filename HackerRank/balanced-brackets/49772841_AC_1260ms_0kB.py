def func(c):
    if c == '(':
        return ')'
    elif c == '[':
        return ']'
    elif c == '{':
        return '}'

casos = (int)(input())
pila = []

for _ in range(casos):
    pila.clear()
    flag = True

    cadena = input()

    for i in cadena:
        if i == '(' or i == '[' or i == '{':
            pila.append(i)

        else:
            if len(pila) == 0:
                flag = False
                break

            a = pila.pop()

            if func(a) != i:
                flag = False
                break
    
    if flag and len(pila) == 0:
        print("YES")

    else:
        print("NO")