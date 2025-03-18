T = int(input())
passwd = {'1011000':0, '1001100':1, '1100100':2, '1011110':3, '1100010':4, '1000110':5, '1111010':6, '1101110':7, '1110110':8, '1101000':9}
for tc in range(T):
    n, m = map(int, input().split())
    data = [list(map(int, list(input().strip()))) for _ in range(n)]
    reversed_data = [row[::-1] for row in data]
 
    code = []
    for i in range(n):
        for j in range(m-56): # No need to search all
            if reversed_data[i][j] == 1:
                code = reversed_data[i][j:j+56]
                break
    ans = 0
    converted_code = []
    for i in range(8):
        tmp = ''.join(map(str, code[i*7:i*7+7]))
        tmp = passwd[tmp]
        if i % 2 == 1:
            ans += tmp*3
        else:
            ans += tmp
        converted_code.append(tmp)
 
    if ans % 10 == 0:
        print(f'#{tc+1} {sum(converted_code)}')
    else:
        print(f'#{tc+1} 0')