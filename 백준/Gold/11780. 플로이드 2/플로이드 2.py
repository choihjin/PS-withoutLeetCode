n = int(input())
m = int(input())
D = [[float('inf')] * n for _ in range(n)]
nxt = [[0] * n for _ in range(n)]

for i in range(n): D[i][i] = 0
for i in range(m):
    a, b, c = map(int, input().split())
    D[a-1][b-1] = min(D[a-1][b-1], c)
    nxt[a-1][b-1] = b-1

for k in range(n):
    for i in range(n):
        for j in range(n):
            if D[i][j] > D[i][k] + D[k][j]:
                D[i][j] = D[i][k] + D[k][j]
                nxt[i][j] = nxt[i][k]

# 최소 비용 출력
for i in range(n):
    for j in range(n):
        if D[i][j] == float('inf'):
            print(0, end=" ")
        else:
            print(D[i][j], end=" ")
    print()

for i in range(n):
    for j in range(n):
        if D[i][j] == 0 or D[i][j] == float('inf'):
            print(0)
            continue

        path = []
        cur = i
        while cur != j:
            path.append(cur)
            cur = nxt[cur][j]
        path.append(j)

        print(len(path), end=" ")
        for p in path:
            print(p+1, end=" ")
        print()