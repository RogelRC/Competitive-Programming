st = [0] * 400005

pos = 0; val = 0

def update(p, l, r):
    if l == r:
        st[p] = val
    
    else:
        mid = (l + r) // 2

        if(pos <= mid):
            update(p * 2, l, mid)
        else:
            update(p * 2 + 1, mid + 1, r)

        st[p] = max(st[p * 2], st[p * 2 + 1])
    
querys = (int)(input())

for _ in range(querys):
    line = input()

    if line.startswith("1"):
        pos += 1

        val = (int)(line.split()[1])

        update(1, 1, 100000)

    elif line.startswith("2"):
        val = 0

        update(1, 1, 100000)

        pos -= 1

    else:
        print(st[1])