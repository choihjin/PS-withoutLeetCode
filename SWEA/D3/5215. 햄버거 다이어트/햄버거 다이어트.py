def dfs(s, k, used):
    global ans
    if k <= L:
        ans = max(ans, s)

    for i in range(N):
        if len(used) != 0 and i < used[-1]:
            continue
        if i not in used:
            used.append(i)
            dfs(s + score[i], k + kcal[i], used)
            used.pop()

T = int(input())
for tc in range(1, T+1):
    N, L = map(int, input().split())
    score = []
    kcal = []
    for i in range(N):
        s, k = map(int, input().split())
        score.append(s)
        kcal.append(k)

    ans = 0
    dfs(0, 0, [])
    print(f'#{tc} {ans}')