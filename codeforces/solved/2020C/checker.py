for t in range(int(input())):
    b, c, d = map(int, input().split())
    print(b^d if (((b^d )| b) - (c & (b^d)) == d) else -1)
