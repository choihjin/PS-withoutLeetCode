T = int(input())
for tc in range(1, T+1):
    N = int(input())
    a = list(map(int, input().split()))
    dp = [1] * N

    for i in range(N):
        mx = 0
        for j in range(i):
            if a[j] < a[i]:
                mx = max(mx, dp[j])
        dp[i] = mx + 1

    print(f'#{tc} {max(dp)}')