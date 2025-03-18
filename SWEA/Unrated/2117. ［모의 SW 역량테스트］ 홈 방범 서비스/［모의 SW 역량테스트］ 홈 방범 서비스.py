T = int(input())
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
for tc in range(1, T + 1):
    N, M = map(int, input().split())
    city = [list(map(int, input().split())) for _ in range(N)]

    houses = [(i, j) for i in range(N) for j in range(N) if city[i][j] == 1]  # 집 리스트
    max_houses = len(houses)  # 최대 가능한 집 개수
    ans = 0

    def count_houses(x, y, K):
        """(x, y)를 중심으로 K 범위 내의 집 개수 세기"""
        cnt = 0
        for hx, hy in houses:
            if abs(hx - x) + abs(hy - y) < K:  # 맨해튼 거리 조건
                cnt += 1
        return cnt

    for i in range(N):
        for j in range(N):
            for K in range(1, 2 * N):
                cost = K * K + (K - 1) * (K - 1)
                cnt = count_houses(i, j, K)

                if cnt * M >= cost:  # 이익이 나는 경우
                    ans = max(ans, cnt)

                if cnt == max_houses:  # 모든 집을 포함하면 더 이상 탐색할 필요 없음
                    break

    print(f'#{tc} {ans}')
