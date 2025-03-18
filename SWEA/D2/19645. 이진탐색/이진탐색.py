def binary_search(target):
    l, r = 1, P
    count = 0
    while r - l > 1:
        count += 1
        page = (l + r) // 2
        if page == target:
            return count
        elif page > target:
            r = page
        else:
            l = page
    return count
 
T = int(input())
for test_case in range(1, T + 1):
    P, A, B = map(int, input().split())
    cnt_A = binary_search(A)
    cnt_B = binary_search(B)
 
    if cnt_A > cnt_B:
        ans = 'B'
    elif cnt_A < cnt_B:
        ans = 'A'
    else:
        ans = 0
 
    print(f'#{test_case} {ans}')