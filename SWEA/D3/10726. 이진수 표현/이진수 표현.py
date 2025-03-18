T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for tc in range(1, T+1):
    n, m = map(int, input().split())
    m = bin(m)
    m = m[2:]

    ans = 'ON'
    start = len(m)-1
    end = start - n
    for i in range(start, end, -1):
        if i < 0 or m[i] == '0':
            ans = 'OFF'
            break
    print(f'#{tc} {ans}')