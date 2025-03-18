MAX = 1000002
prime = [True] * MAX
prime[0] = prime[1] = False

# 에라토스테네스의 체로 소수 판별
for i in range(2, int(MAX ** 0.5) + 1):
    if prime[i]:
        for j in range(i * i, MAX, i):
            prime[j] = False

# 각 자리수(D)별 누적합 배열 미리 계산 (D는 0부터 9까지 고려)
cum = {str(d): [0] * MAX for d in range(10)}
for i in range(1, MAX):
    s = str(i)
    for d in cum:
        # 이전 값에 현재 숫자가 특별 소수이면 1을 더함
        cum[d][i] = cum[d][i - 1] + (1 if prime[i] and d in s else 0)

T = int(input())
for tc in range(1, T + 1):
    D, A, B = input().split()
    A = int(A)
    B = int(B)
    d = str(D)  # D를 문자열로 변환
    # A가 0일 경우를 대비한 예외 처리
    result = cum[d][B] - (cum[d][A - 1] if A > 0 else 0)
    print(f'#{tc} {result}')