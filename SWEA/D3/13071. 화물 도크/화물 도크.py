T = int(input())
for tc in range(1, T+1):
    N = int(input())
    time = [list(map(int, input().split())) for _ in range(N)]
    time.sort(key=lambda x:x[1]) # end time 기준 정렬

    ans = 0
    cur = 0
    for t in time:
        if cur > t[0]:
            continue

        cur = t[1]
        ans += 1

    print(f'#{tc} {ans}')