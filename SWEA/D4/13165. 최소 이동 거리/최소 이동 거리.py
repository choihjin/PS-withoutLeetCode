import heapq
T = int(input())
for tc in range(1, T+1):
    N, E = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    d = [float('inf')] * (N+1)

    for i in range(E):
        s, e, w = map(int, input().split())
        adj[s].append((w, e))

    d[0] = 0
    pq = [(0, 0)]
    while pq:
        w, s = heapq.heappop(pq)
        if d[s] != w: continue
        for nw, ns in adj[s]:
            if d[ns] <= d[s] + nw: continue
            d[ns] = d[s] + nw
            heapq.heappush(pq, (d[ns], ns))

    print(f'#{tc} {d[N]}')