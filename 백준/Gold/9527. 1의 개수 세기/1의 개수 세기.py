def count_ones(X):
    if X == 0:
        return 0

    count = 0
    while X > 0:
        # X보다 작거나 같은 최대 2^k 찾기
        k = 1
        while k <= X:
            k <<= 1
        high_bit = k >> 1  # X보다 작거나 같은 최대 2^k

        # 해당 구간까지의 1 개수 계산
        ones_in_full_range = (high_bit >> 1) * (high_bit.bit_length() - 1)
        remaining = X - high_bit  # 남은 부분

        # 총 개수 업데이트
        count += ones_in_full_range + remaining + 1

        # 다음 반복을 위해 X를 줄이기
        X = remaining  # ✅ 재귀 대신 X를 업데이트

    return count


A, B = map(int, input().split())
print(count_ones(B) - count_ones(A-1))