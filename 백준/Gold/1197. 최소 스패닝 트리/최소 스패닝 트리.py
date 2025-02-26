class Set:
    def __init__(self):
        self.p = list(range(V+1))
        self.rank = [1] * (V+1)

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

V, E = map(int, input().split())
edges = [list(map(int, input().split())) for _ in range(E)]

mst = kruskal()
print(sum(mst))