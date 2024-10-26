n = int(input())
solucion = 1
 
lista = list(map(int, input().split()))
 
lista.sort()
 
cmp = lista[0]
 
for i in range(1, n):
    if(lista[i] != lista[i - 1]):
        solucion += 1
 
print(solucion)