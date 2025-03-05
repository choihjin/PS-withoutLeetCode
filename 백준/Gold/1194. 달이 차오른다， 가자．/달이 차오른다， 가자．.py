from collections import deque
# 빈 칸: 언제나 이동할 수 있다. ('.')
# 벽: 절대 이동할 수 없다. ('#')
# 열쇠: 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. ('a', 'b', 'c', 'd', 'e', 'f')
# 문: 대응하는 열쇠가 있을 때만 이동할 수 있다. ('A', 'B', 'C', 'D', 'E', 'F')
# 민식이의 현재 위치: 빈 곳이고, 민식이가 현재 서 있는 곳이다. ('0')
# 출구: 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. ('1')
N, M = map(int, input().split())
maze = [list(input().strip()) for _ in range(N)]

Q = deque()
for i in range(N):
    for j in range(M):
        if maze[i][j] == '0':
            Q.append((0, i, j)) # no key, start point

time = 0
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
key = {
    'a': 32,
    'b': 16,
    'c': 8,
    'd': 4,
    'e': 2,
    'f': 1
}

# visited[key_state][x][y]
visited = [[[-1] * M for _ in range(N)] for _ in range(64)]
visited[0][Q[0][1]][Q[0][2]] = 0 # no key, start point
while Q:
    key_state, x, y = Q.popleft()
    # print(key_state, x, y)
    for d in range(4):
        nx, ny = x + dx[d], y + dy[d]

        # out of range
        if nx < 0 or nx >= N or ny < 0 or ny >= M: continue

        # print(nx, ny, visited[key_state][nx][ny])
        # already visited
        if visited[key_state][nx][ny] >= 0: continue

        # blocked
        if maze[nx][ny] == '#': continue

        # door and haven't key
        if maze[nx][ny] in 'ABCDEF' and not(key_state & key[maze[nx][ny].lower()]): continue

        nxt_key_state = key_state
        # find new key
        if maze[nx][ny] in 'abcdef' and not(key_state & key[maze[nx][ny]]):
            nxt_key_state += key[maze[nx][ny]]

        # find exit
        if maze[nx][ny] == '1':
            # for i in range(64):
            #     print(visited[i])
            print(visited[key_state][x][y]+1)
            exit(0)

        visited[nxt_key_state][nx][ny] = visited[key_state][x][y] + 1
        Q.append((nxt_key_state, nx, ny))

print(-1)