dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
T = 10
for tc in range(1, T+1):
    tmp = int(input())
    n = 16
    m = [list(map(int, input().strip())) for _ in range(n)]
    visited = [[0] * n for _ in range(n)]

    q = []
    q.append((1, 1))
    visited[1][1] = 1
    while(len(q)):
        x, y = q.pop(0)
        for i, j in dir:
            nx, ny = x + i, y + j

            if nx < 0 or nx >= n or ny < 0 or ny >= n: # out of range
                continue
            if visited[nx][ny] or m[nx][ny] == 1: # already visited or blocked
                continue

            q.append((nx, ny))
            visited[nx][ny] = 1

    print(f'#{tc} {visited[13][13]}')