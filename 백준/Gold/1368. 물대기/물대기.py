# N : 논의 수
# W = 우물 파는 비용
# P_ij = i와 j 논을 연결하는데 드는 비용
class Set:
    def __init__(self):
        self.p = list(range(N+1))
        self.rank = [1] * (N+1)

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)

        if px == py:
            return False

        if self.rank[px] > self.rank[py]:
            self.p[py] = px
        elif self.rank[px] < self.rank[py]:
            self.p[px] = py
        else:
            self.p[py] = px
            self.rank[px] += 1
        return True

def kruskal():
    mst =[]
    U = Set()

    edges.sort(key=lambda x:x[2])
    for edge in edges:
        s, e, w = edge
        if U.union(s, e):
            mst.append(w)

    return mst

N = int(input())
W = [int(input()) for _ in range(N)]
P = [list(map(int, input().split())) for _ in range(N)]
edges = []
for i in range(N):
    for j in range(i+1, N):
        edges.append((i, j, P[i][j]))
for i in range(N):
    edges.append((i, N, W[i]))

mst = kruskal()
print(sum(mst))