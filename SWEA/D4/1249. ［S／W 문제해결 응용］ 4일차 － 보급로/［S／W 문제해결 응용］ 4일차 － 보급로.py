dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
T = int(input())
for tc in range(1, T+1):
    n = int(input())
    road = [list(map(int, input().strip())) for _ in range(n)]
    visited = [[float('inf')] * n for _ in range(n)]

    q = []
    q.append((0, 0))
    visited[0][0] = 0
    while(len(q)):
        x, y = q.pop(0)
        for dx, dy in dir:
            nx, ny = x + dx, y + dy

            if nx < 0 or nx >= n or ny < 0 or ny >= n: # out of range
                continue

            if visited[x][y] + road[nx][ny] < visited[nx][ny]:
                visited[nx][ny] = visited[x][y] + road[nx][ny]
                q.append((nx, ny))

    print(f'#{tc} {visited[n-1][n-1]}')