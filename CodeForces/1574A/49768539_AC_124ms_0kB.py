t = (int)(input())

for _ in range(t):
    n = (int)(input())

    for i in range(n):
        print("()", end = "")

    print()

    for i in range(1, n):

        for j in range(1, n):

            if(i == j):
                print("(())", end = "")
            else:
                print("()", end = "")
        
        print()


