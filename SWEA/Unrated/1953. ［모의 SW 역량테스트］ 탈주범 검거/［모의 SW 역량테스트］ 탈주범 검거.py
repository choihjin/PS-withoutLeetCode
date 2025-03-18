tunnel = {1: [(1, 0), (-1, 0), (0, 1), (0, -1)],
          2: [(1, 0), (-1, 0)],
          3: [(0, 1), (0, -1)],
          4: [(0, 1), (-1, 0)],
          5: [(0, 1), (1, 0)],
          6: [(0, -1), (1, 0)],
          7: [(-1, 0), (0, -1)]}
T = int(input())
for tc in range(1, T+1):
    n, m, gx, gy, t = map(int, input().split())
    road = [list(map(int, input().split())) for _ in range(n)]
    visited = [[0] * m for _ in range(n)]

    q = []
    q.append((gx, gy))
    visited[gx][gy] = 1
    ans = 0
    while len(q):
        x, y = q.pop(0)

        if visited[x][y] == t + 1:
            break
        ans += 1

        for dx, dy in tunnel[road[x][y]]:
            nx, ny = x + dx, y + dy

            if nx < 0 or nx >= n or ny < 0 or ny >= m: # out of range
                continue
            if not road[nx][ny]: # blocked
                continue
            if (-dx, -dy) not in tunnel[road[nx][ny]]: # not connected
                continue
            if visited[nx][ny]: # already visited
                continue

            q.append((nx, ny))
            visited[nx][ny] = visited[x][y] + 1

    print(f'#{tc} {ans}')