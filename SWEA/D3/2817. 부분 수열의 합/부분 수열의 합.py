def dfs(idx, used):
    global ans
    if sum(used) >= k:
        if sum(used) == k:
            ans += 1
        return

    for i in range(idx, n):
        used.append(arr[i])
        dfs(i+1, used)
        used.pop()

T = int(input())
for tc in range(1, T+1):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    ans = 0
    dfs(0, [])
    print(f'#{tc} {ans}')