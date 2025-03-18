dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
block = ((),
              (1, 3, 0, 2),
              (3, 0, 1, 2),
              (2, 0, 3, 1),
              (1, 2, 3, 0),
              (1, 0, 3, 2))

def bfs(x, y, d):
    sx, sy = x, y
    score = 0

    while 1:
        x += dir[d][0]
        y += dir[d][1]

        # return start point or black hole
        if m[x][y] == -1 or (x, y) == (sx, sy):
            break

        if 1 <= m[x][y] <= 5:
            d = block[m[x][y]][d]
            score += 1
        elif m[x][y] >= 6:
            x, y = wormhole[(x, y)]

    return score

T = int(input())
for tc in range(1, T+1):
    n = int(input())

    m = [[5] * (n + 2)]
    for i in range(n):
        m.append([5] + list(map(int, input().split())) + [5])
    m.append([5] * (n + 2))

    # find worm hole
    wormhole = {}
    tmp = [0] * 11
    for i in range(1, n+1):
        for j in range(1, n+1):
            if m[i][j] >= 6:
                if tmp[m[i][j]]:
                    wormhole[tmp[m[i][j]]] = (i, j)
                    wormhole[(i, j)] = tmp[m[i][j]]
                else:
                    tmp[m[i][j]] = (i, j)

    # bfs
    ans = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            if not m[i][j]: # empty space
                for d in range(4):
                    ans = max(ans, bfs(i, j, d))

    print(f'#{tc} {ans}')
    wormhole.clear()