from itertools import combinations as com
T = int(input())
for tc in range(1, T+1):
    n = int(input())
    data = [list(map(int, input().split())) for _ in range(n)]

    ans = 40000
    for case in com(range(n), n//2):
        another = list(set(range(n)) - set(case))

        a = 0
        for x, y in com(case, 2):
            a += data[x][y] + data[y][x]
        b = 0
        for x, y in com(another, 2):
            b += data[x][y] + data[y][x]

        ans = min(ans, abs(a-b))
    print(f'#{tc} {ans}')