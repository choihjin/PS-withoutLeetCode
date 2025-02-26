def find(x):
    if p[x] < 0:
        return x
    p[x] = find(p[x])
    return p[x]

def union(x, y):
    x = find(x)
    y = find(y)
    if x == y: return False;
    p[y] = x;
    return True;

n, m = map(int, input().split())
operator = [list(map(int, input().split())) for _ in range(m)]
p = [-1] * (n+1)

for op in operator:
    if op[0] == 0:
        union(op[1], op[2])
    else:
        x = find(op[1])
        y = find(op[2])
        if x == y:
            print("YES")
        else:
            print("NO")