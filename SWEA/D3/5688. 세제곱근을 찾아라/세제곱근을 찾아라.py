def find_cube_root(N):
    X = round(N ** (1/3))  # 세제곱근을 반올림하여 정수로 변환
    if X**3 == N:
        return X
    else:
        return -1

T = int(input())
for tc in range(1, T + 1):
    N = int(input())
    res = find_cube_root(N)
    print(f'#{tc} {res}')