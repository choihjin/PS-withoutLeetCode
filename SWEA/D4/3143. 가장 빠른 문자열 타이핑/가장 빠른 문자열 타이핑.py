T = int(input())
for tc in range(1, T+1):
    s, p = input().split()
    cnt = 0
    pos = 0

    while True:
        idx = s.find(p, pos)
        if idx == -1:
            break
        cnt += 1
        pos = idx + len(p)
    
    res = len(s) - cnt * (len(p) - 1)
    print(f'#{tc} {res}')