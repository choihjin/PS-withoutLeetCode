import heapq
N = int(input())
E = int(input())
adj = [[] for _ in range(N+1)]
pre = [0] * (N+1)
d = [float('inf')] * (N+1)

for i in range(E):
    s, e, w = map(int, input().split())
    adj[s].append((w, e))

ts, te = map(int, input().split())

d[ts] = 0
pq = [(0, ts)]
while pq:
    w, s = heapq.heappop(pq)
    if d[s] != w: continue
    for nw, ns in adj[s]:
        if d[ns] <= d[s] + nw: continue
        d[ns] = d[s] + nw
        heapq.heappush(pq, (d[ns], ns))
        pre[ns] = s

path = []
cur = te
while cur != ts:
    path.append(cur)
    cur = pre[cur]
path.append(ts)

print(d[te])
print(len(path))
print(*path[::-1])