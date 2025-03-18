T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for tc in range(1, T+1):
    pipe = input()
    stack = []
    ans = 0
    for i in range(len(pipe)):
        if pipe[i] == '(':
            stack.append('(')
        else:
            if pipe[i-1] == '(': # lazer case
                stack.pop()
                ans += len(stack)
            else: # end of pipe
                ans += 1
                stack.pop()
    print(f'#{tc} {ans}')