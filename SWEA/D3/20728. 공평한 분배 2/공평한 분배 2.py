T = int(input())
for tc in range(1, T+1):
    N, K = map(int, input().split())
    pockets = list(map(int, input().split()))
    pockets.sort()

    ans = float('inf')
    for i in range(N-K+1):
        ans = min(ans, pockets[i+K-1] - pockets[i])

    print(f'#{tc} {ans}')