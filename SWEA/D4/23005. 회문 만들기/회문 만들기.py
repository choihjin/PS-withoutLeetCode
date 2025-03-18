T = int(input())
for tc in range(1, T+1):
    s = input().strip()
    st = 0
    en = len(s) - 1
    res = 0
    
    while st < en:
        if s[st] != s[en]:
            if s[st] == 'x':
                st += 1  
                res += 1
            elif s[en] == 'x':
                en -= 1
                res += 1
            else:
                res = -1  
                break
        else:
            st += 1
            en -= 1

    print(res)