from collections import deque

# 2 ≤ N ≤ 20
# 1 ≤ M ≤ N2
# 1 ≤ fuel ≤ 500,000

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
def find_passenger():
    Q = deque()
    visited = [[-1] * N for _ in range(N)]
    Q.append((taxi[0], taxi[1]))
    visited[taxi[0]][taxi[1]] = 0
    candidates = []

    while Q:
        x, y = Q.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1 and board[nx][ny] == 0:
                visited[nx][ny] = visited[x][y] + 1
                Q.append((nx, ny))

    # 승객들 중에서 최적의 승객 찾기
    for i in range(len(passengers)):
        px, py, _, _ = passengers[i]
        if visited[px][py] != -1:  # 택시가 갈 수 있는 승객인지 확인
            candidates.append((visited[px][py], px, py, i))

    if not candidates:
        return -1, -1

    # 거리, 행, 열 순으로 정렬 후 가장 우선순위 높은 승객 선택
    candidates.sort()
    return candidates[0][3], candidates[0][0]  # 승객 인덱스, 거리


def find_ep(idx):
    px, py, ex, ey = passengers.pop(idx)
    Q = deque()
    visited = [[-1] * N for _ in range(N)]

    Q.append((px, py))
    visited[px][py] = 0

    while Q:
        x, y = Q.popleft()
        for d in range(4):
            nx, ny = x + dx[d], y + dy[d]
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1 and board[nx][ny] == 0:
                visited[nx][ny] = visited[x][y] + 1
                Q.append((nx, ny))

    if visited[ex][ey] == -1:  # 목적지 도달 불가능하면 실패
        return -1

    global taxi
    taxi = [ex, ey]
    return visited[ex][ey]


N, M, fuel = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
taxi = [x - 1 for x in map(int, input().split())]
passengers = [list(x - 1 for x in map(int, input().split())) for _ in range(M)]

while passengers:
    idx, dist_to_passenger = find_passenger()
    if dist_to_passenger == -1:
        print(-1)
        exit(0)

    fuel -= dist_to_passenger
    if fuel < 0:
        print(-1)
        exit(0)

    dist_to_destination = find_ep(idx)
    if dist_to_destination == -1 or fuel < dist_to_destination:
        print(-1)
        exit(0)

    fuel -= dist_to_destination
    fuel += dist_to_destination * 2

print(fuel)