import math
 
T = int(input())
for tc in range(T):
    n = int(input())
    data = [list(map(int, list(input().strip()))) for _ in range(n)]
 
    ans = 0
    plus = 0
    center = math.floor(n / 2)  
    for i in range(math.ceil(n/2)):
        ans += sum(data[i][center-plus:center+plus+1])
 
        if i == math.ceil(n/2)-1:
            continue
        ans += sum(data[n-i-1][center-plus:center+plus+1])
 
        plus += 1
    print(f'#{tc+1} {ans}')