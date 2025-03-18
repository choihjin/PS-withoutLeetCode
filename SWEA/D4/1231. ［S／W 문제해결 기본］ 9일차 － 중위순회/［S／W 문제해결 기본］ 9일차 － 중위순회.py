def in_order(n):
    global ans
    if n:
        in_order(left[n])
        ans += tree[n]
        in_order(right[n])

for tc in range(1, 11):
    n = int(input())
    tree = [0] * (n+1)
    left = [0] * (n+1)
    right = [0] * (n+1)

    for i in range(n):
        tmp = input().split()
        tree[int(tmp[0])] = tmp[1]
        if len(tmp) > 2:
            left[int(tmp[0])] = int(tmp[2])
        if len(tmp) > 3:
            right[int(tmp[0])] = int(tmp[3])

    ans = ''
    in_order(1)
    print(f'#{tc} {ans}')