import sys
from collections import deque

input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(input().strip()) for _ in range(n)]
visited = [[0 for _ in range(m)] for _ in range(n)]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

Q = deque()
for i in range(n):
    if len(Q): 
        break
    for j in range(m):
        if arr[i][j] == 'I':
            Q.append((i, j))
            visited[i][j] = 1
            break

ans = 0
while Q:
    x, y = Q.popleft()
    
    for dir in range(4):
        nx = x + dx[dir]
        ny = y + dy[dir]

        if nx < 0 or nx >=n or ny < 0 or ny >= m:
            continue
        if visited[nx][ny] or arr[nx][ny] == 'X':
            continue
        if arr[nx][ny] == 'P':
            ans += 1
            
        Q.append((nx, ny))
        visited[nx][ny] = 1

if ans > 0:
    print(ans)
else:
    print('TT')