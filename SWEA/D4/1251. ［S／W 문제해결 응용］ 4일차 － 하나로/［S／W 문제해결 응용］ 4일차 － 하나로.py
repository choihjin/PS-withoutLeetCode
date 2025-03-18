import heapq
def prim():
    mst = []
    visited = [False] * N
    min_edge = [float('inf')] * N  # 각 정점까지의 최소 비용
    min_edge[0] = 0  # 시작 정점(0)에서 시작
    min_heap = [(0, 0)]  # (가중치, 정점)

    while len(mst) < N:  # MST의 크기가 N이 될 때까지 진행
        weight, v = heapq.heappop(min_heap)
        if visited[v]:
            continue

        visited[v] = True
        mst.append(weight)

        for j in range(N):
            if not visited[j]:
                w = ((x[v] - x[j]) ** 2 + (y[v] - y[j]) ** 2) * E
                if w < min_edge[j]:  # 더 작은 가중치만 유지
                    min_edge[j] = w
                    heapq.heappush(min_heap, (w, j))

    return mst

T = int(input())
for tc in range(1, T+1):
    N = int(input())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    E = float(input())

    mst = prim()
    print(f'#{tc} {round(sum(mst))}')