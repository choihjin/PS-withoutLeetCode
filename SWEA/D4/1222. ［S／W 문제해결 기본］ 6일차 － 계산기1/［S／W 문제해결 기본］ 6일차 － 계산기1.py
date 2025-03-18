T = 10
for tc in range(1, T+1):
    size = int(input())
    exp = list(input())
    for i in range(1, size):
        if exp[i] != '+':
            exp[i], exp[i-1] = exp[i-1], exp[i]

    stack = []
    ans = 0
    for n in exp:
        if n != '+':
            stack.append(int(n))
        else:
            tmp = stack.pop()
            tmp += stack.pop()
            stack.append(tmp)
    print(f'#{tc} {stack.pop()}')