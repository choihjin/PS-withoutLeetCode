# 2819
direct = [(1, 0), (-1, 0), (0, 1), (0, -1)]
def dfs(x, y, s):
    if len(s) == 7:
        if s not in ans:
            ans.append(s)
        return

    for i, j in direct:
        nx, ny = x + i, y + j
        if nx < 0 or nx >= n or ny < 0 or ny >= n: # out of range
            continue
        dfs(nx, ny, s+str(data[nx][ny]))

T = int(input())
for tc in range(1, T+1):
    n = 4
    data = [list(map(int, input().split())) for _ in range(n)]

    ans = []
    for i in range(n):
        for j in range(n):
            dfs(i, j, '')

    print(f'#{tc} {len(ans)}')