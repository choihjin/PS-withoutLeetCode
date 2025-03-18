T = int(input())
for tc in range(1, T+1):
    N, M, C = map(int, input().split())
    honey = [list(map(int, input().split())) for _ in range(N)]

    profits = [[] for _ in range(N)]
    for i in range(N):
        for j in range(N - M + 1):
            if sum(honey[i][j:j + M]) <= C:
                profits[i].append(sum(i * i for i in honey[i][j:j + M]))
            else:
                tmp = honey[i][j:j + M]
                tmp.sort(reverse=True)

                cal = []
                for k in range(M):
                    plus = [tmp[k]]
                    for idx in range(k+1, M):
                        if sum(plus) + tmp[idx] <= C:
                            plus.append(tmp[idx])
                    cal.append(sum(q**2 for q in plus))
                cal.sort(reverse=True)
                profits[i].append(cal[0])

    ans = 0
    x, y = 0, 0
    while x < N-1:
        if y == N-M+1:
            x += 1
            y = 0

        for i in range(N):
            for j in range(N-M+1):
                if i == x and j == y:
                    continue
                elif i == x and abs(j - y) < M:
                    continue
                ans = max(ans, profits[i][j] + profits[x][y])

        y += 1

    print(f'#{tc} {ans}')