T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    trees = list(map(int, input().split()))

    largest = max(trees)
    total_diff = 0
    odd = 0
    for tree in trees:
        total_diff += largest - tree
        if (largest - tree) % 2:
            odd += 1

    days = (total_diff // 3) * 2 + total_diff % 3
    one = days // 2 + days % 2
    two = days // 2

    if odd <= one:
        res = days
    else:
        res = odd * 2 - 1

    print(f'#{tc} {res}')